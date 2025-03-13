#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include "newdialog.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , data(new Data(this))
{
    ui->setupUi(this);
    ui->tableWidget = new QTableWidget(this); // 创建表格控件
    setCentralWidget(ui->tableWidget);
    //从数据中读取行数和列数并初始化表格
    ui->tableWidget->setRowCount(data->rowCount());
    ui->tableWidget->setColumnCount(data->columnCount());
    //链接按钮和槽
    connect(ui->actionOPen,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::saveFile);
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::newFile);
    connect(ui->actionInsert,&QAction::triggered,this,&MainWindow::insert);
    connect(ui->actionDelete,&QAction::triggered,this,&MainWindow::Delete);
    connect(ui->actionSearch, &QAction::triggered, this, &MainWindow::searchInTable);
    connect(ui->actionReplace,&QAction::triggered,this,&MainWindow::replaceInTable);
    //链接单元格信号变化和槽函数
    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//打开文件（把data的数据中展示在表格中）
void MainWindow::openFile()
{
    // 打开文件对话框选择Excel文件
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Excel File"), "", tr("Excel Files (*.xls *.xlsx)"));
    if (fileName.isEmpty()){
        QMessageBox::warning(this,tr("Error"),tr("Excel does not exist!"));
        return;
    }
    // 断开表格控件的单元格内容变化信号和槽的连接,以防填充的时候反复触发函数
    disconnect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);

    // 加载Excel文件并填充表格控件
    if (data->loadFromFile(fileName))//如果成功的把数据导入data中则下面是展示
     {
        ui->tableWidget->setRowCount(data->rowCount());//用数据的行数设置表格的行数
        ui->tableWidget->setColumnCount(data->columnCount());//用数据的列数设置表格的列数
        //按照行列方式在表格中展示数据
        for (int i = 0; i < data->rowCount(); ++i) {
            for (int j = 0; j < data->columnCount(); ++j) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(data->getCellData(i, j)));
                //将数据放到一个单元格类中，在把这个单元格类放到表格中的对应位置
            }
        }
        //重新连接以便后续对于单元格的单独操作
        connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to load the Excel file."));
    }
}

//保存文件（把表格中的数据保存到data中）
void MainWindow::saveFile()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save Excel File"),"",tr("Excel files (*.xls *.xlsx)"));
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,tr("Error"),tr("route does not exist!"));
        return;
    }
    data->excel = new QAxObject("Excel.Application",this);
    //把表格中的数据保存到data中
    if (data->saveToFile(fileName)) {
        QMessageBox::information(this, tr("Save Excel File"), tr("File saved successfully!"));
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to save the Excel file."));
    }
}

//接受变化的单元格
void MainWindow::on_tableWidget_cellChanged(int row, int col)
{
    QTableWidgetItem*item=ui->tableWidget->item(row,col);
    if(item)
    {
     data->setCellData(row,col,item->text());
    }
}

//打开一个新的文件并发送信号
void MainWindow::newFile()
{
    newDialog *dialog=new newDialog();
    connect(dialog,&newDialog::Created,this,&MainWindow::tableCreated);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

//实际创建表格
void MainWindow::tableCreated(int rows,int cols)
{
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(cols);
    data->setRowCount(rows);
    data->setColumnCount(cols);
}

void MainWindow::insert()
{
    // 获取选中的区域
    QList<QTableWidgetSelectionRange> selectedRanges = ui->tableWidget->selectedRanges();

    // 如果没有选中任何区域
    if (selectedRanges.isEmpty()) {
        QMessageBox::warning(this, tr("错误"), tr("请选中一行或一列！"));
        return;
    }

    // 只处理第一个选中的区域
    QTableWidgetSelectionRange range = selectedRanges.first();

    // 判断是否选中了整列
    if (range.rowCount() == ui->tableWidget->rowCount() && range.columnCount() == 1) {
        int col = range.leftColumn(); // 获取选中的列号
        for (auto& rowData : data->tableData) {
            rowData.insert(rowData.begin() + col, ""); // 在数据模型中插入空列
        }
        ui->tableWidget->insertColumn(col); // 在表格中插入列
        for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
            ui->tableWidget->setItem(i, col, new QTableWidgetItem("")); // 初始化新列
        }
    }
    // 判断是否选中了整行
    else if (range.columnCount() == ui->tableWidget->columnCount() && range.rowCount() == 1) {
        int row = range.topRow(); // 获取选中的行号
        int cols = ui->tableWidget->columnCount();
        data->tableData.insert(data->tableData.begin() + row, std::vector<QString>(cols, "")); // 在数据模型中插入空行
        ui->tableWidget->insertRow(row); // 在表格中插入行
        for (int j = 0; j < cols; ++j) {
            ui->tableWidget->setItem(row, j, new QTableWidgetItem("")); // 初始化新行
        }
    }
    // 其他情况（例如选中单个单元格或多个单元格）
    else {
        QMessageBox::warning(this, tr("错误"), tr("请仅选中完整的一行或一列！"));
        return;
    }
}

//删除
void MainWindow::Delete()
{
    // 获取用户选中的区域
    QList<QTableWidgetSelectionRange> selectedRanges = ui->tableWidget->selectedRanges();

    // 如果没有选中任何区域，提示用户
    if (selectedRanges.isEmpty()) {
        QMessageBox::warning(this, tr("错误"), tr("请选中一行或一列！"));
        return;
    }
    
    // 只处理第一个选中的区域
    QTableWidgetSelectionRange range = selectedRanges.first();
    // 判断是否选中了整列
    if (range.rowCount() == ui->tableWidget->rowCount() && range.columnCount() == 1) {
        int col = range.leftColumn(); // 获取选中的列号
        // 从数据模型中删除该列
        for (auto& rowData : data->tableData) {
            if (col < rowData.size()) {
                rowData.erase(rowData.begin() + col);
            }
        }
        // 从表格界面中删除该列
        ui->tableWidget->removeColumn(col);
    }
    // 判断是否选中了整行
    else if (range.columnCount() == ui->tableWidget->columnCount() && range.rowCount() == 1) {
        int row = range.topRow(); // 获取选中的行号
        if (row < data->tableData.size()) {
            data->tableData.erase(data->tableData.begin() + row);
        }
        // 从表格界面中删除该行
        ui->tableWidget->removeRow(row);
    }
    // 其他情况（例如选中单个单元格或多个单元格），提示用户
    else {
        QMessageBox::warning(this, tr("错误"), tr("请仅选中完整的一行或一列！"));
        return;
    }
}

//在表格中查询
void MainWindow::searchInTable()
{
    bool ok;
    QString searchText = QInputDialog::getText(this, tr("查找"), tr("输入要查找的内容"), QLineEdit::Normal, "", &ok);
    if (!ok || searchText.isEmpty()) {
        return;
    }

    for (int row = 0; row < data->tableData.size(); ++row) {
        for (int col = 0; col < data->tableData[row].size(); ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && item->text() == searchText) {
                // 找到匹配项，滚动到该单元格并选中
                ui->tableWidget->setCurrentCell(row, col);
                ui->tableWidget->scrollToItem(item, QAbstractItemView::PositionAtCenter);
                return;
            }
        }
    }

    QMessageBox::information(this, tr("查找"), tr("未找到匹配项！"));
}

void MainWindow::replaceInTable()
{
    bool ok;
    QString searchText = QInputDialog::getText(this, tr("替换"), tr("输入要查找的内容"), QLineEdit::Normal, "", &ok);
    if (!ok || searchText.isEmpty()) {
        return;
    }

    QString replaceText = QInputDialog::getText(this, tr("替换"), tr("输入替换后的内容"), QLineEdit::Normal, "", &ok);
    if (!ok || replaceText.isEmpty()) {
        return;
    }

    bool found = false;
    for (int row = 0; row < data->tableData.size(); ++row) {
        for (int col = 0; col < data->tableData[row].size(); ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && item->text() == searchText) {
                // 替换匹配项
                item->setText(replaceText);
                data->tableData[row][col] = replaceText;
                found = true;
            }
        }
    }

    if (found) {
        QMessageBox::information(this, tr("替换"), tr("替换完成！"));
    } else {
        QMessageBox::information(this, tr("替换"), tr("未找到匹配项！"));
    }
}
