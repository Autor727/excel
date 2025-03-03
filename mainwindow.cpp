#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include "newdialog.h"

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

void MainWindow::on_tableWidget_cellChanged(int row, int col)
{
    QTableWidgetItem*item=ui->tableWidget->item(row,col);
    if(item)
    {
     data->setCellData(row,col,item->text());
    }
}

void MainWindow::newFile()
{
    newDialog *dialog=new newDialog();
    connect(dialog,&newDialog::Created,this,&MainWindow::tableCreated);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::tableCreated(int rows,int cols)
{
    ui->tableWidget->setRowCount(rows);
    ui->tableWidget->setColumnCount(cols);
    data->setRowCount(rows);
    data->setColumnCount(cols);
}
