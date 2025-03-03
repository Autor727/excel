#include "data.h"
#include <QAxObject>
#include<QMessageBox>
#include<QDebug>
#include<QDir>

//构造函数
Data::Data(QObject *parent):excel(nullptr)
    , workbook(nullptr)
    , worksheet(nullptr){}

//析构函数
Data::~Data(){
    if(excel)
    {
        delete excel;
        excel=nullptr;
    }
}

//返回行数
int Data::rowCount(){
    return tableData.size();
}

//返回列数
int Data::columnCount(){
    return tableData.empty()?0:tableData[0].size();
}

//设置行数
void Data::setRowCount(int row){
    tableData.resize(row);
}

//设置列数
void Data::setColumnCount(int col){
    for(int i=0;i<tableData.size();i++)
    {
        tableData[i].resize(col);
    }
}

//清空数据
void Data::clear(){
    tableData.clear();
}

//从excel中读入数据
bool Data::loadFromFile(const QString &fileName)
{
    excel=new QAxObject("Excel.Application", nullptr);//创建excel应用对象
    if (!excel || excel->isNull()) {
        QMessageBox::critical(nullptr, "Error",
            "Failed to create Excel object. Please ensure Microsoft Excel is installed.");
        return 0;
    }
    excel->dynamicCall("SetVisible(bool)",false);//不显示excel页面
    QAxObject*workbooks=excel->querySubObject("WorkBooks");
    workbook=workbooks->querySubObject("Open(const QString&)",fileName);
    worksheet=workbook->querySubObject("WorkSheets(int)",1);

    QAxObject*usedRange=worksheet->querySubObject("UsedRange");//获取使用区域
    QAxObject*rows=usedRange->querySubObject("Rows");//获取行集合
    QAxObject*columns=usedRange->querySubObject("Columns");//获取列集合
    int rowCount=rows->property("Count").toInt();//从行集合中获取行数
    int columnCount=columns->property("Count").toInt();//从列集合中获取列数

    tableData.resize(rowCount);//重新设置行数
    for(int i=0;i<rowCount;i++)
    {
        tableData[i].resize(columnCount);//更新每一行的列数
    }

    //利用usedValue批量读取数据
    QVariant var = usedRange->property("Value");
    QVariantList varRows = var.toList();
    for (int i = 0; i < rowCount; ++i) {
        QVariantList varColumns = varRows[i].toList();
        for (int j = 0; j < columnCount; ++j) {
            tableData[i][j] = varColumns[j].toString();
        }
    }
    workbook->dynamicCall("Close()");//关闭工作簿
    excel->dynamicCall("Quit()");//退出excel应用
    delete excel;
    excel=nullptr;
    return 1;
}

//保存数据到excel文件
bool Data::saveToFile(const QString &fileName)
{
    //此处跟打开是一样的，只是把数据写入到excel中
    if (!excel || excel->isNull()) {
        QMessageBox::critical(nullptr, "Error", "Failed to create Excel object. Please ensure Microsoft Excel is installed.");
        return false;
    }
    excel->dynamicCall("SetVisible(bool Visible)", false);
    QAxObject *workbooks = excel->querySubObject("Workbooks");
    workbook = workbooks->querySubObject("Add");
    worksheet = workbook->querySubObject("Worksheets(int)", 1);
    int rowCount = tableData.size();
    int columnCount = tableData.empty() ? 0 : tableData[0].size();

    // 准备数据以便写入 Excel
    QVariantList varRows;
    for (int i = 0; i < rowCount; ++i) {
        QVariantList varColumns;
        for (int j = 0; j < columnCount; ++j) {
            varColumns.append(QVariant(tableData[i][j]));
        }
        varRows.append(QVariant(varColumns));
    }

    // 将数据转换为 QVariant 以便设置到 Excel 单元格中
    QVariant var = QVariant(varRows);

    // 获取要写入数据的范围对象
    QAxObject *range = worksheet->querySubObject("Range(const QString&)", QString("A1:%1%2").arg(QChar('A' + columnCount - 1)).arg(rowCount));

    // 将数据写入到 Excel 单元格中
    range->setProperty("Value", var);

    // 确保文件名有正确的扩展名
    QString safeFileName = fileName;
    if (!safeFileName.endsWith(".xlsx", Qt::CaseInsensitive) && !safeFileName.endsWith(".xls", Qt::CaseInsensitive)) {
        safeFileName += ".xlsx";  // 默认使用 .xlsx 扩展名
    }

    // 指定文件格式
    int fileFormat = (safeFileName.endsWith(".xlsx", Qt::CaseInsensitive)) ? 51 : 56; // 51 是 .xlsx 格式，56 是 .xls 格式

    // 保存工作簿到指定文件
    workbook->dynamicCall("SaveAs(const QString&, int)", QDir::toNativeSeparators(safeFileName), fileFormat);

    // 关闭工作簿
    workbook->dynamicCall("Close()");

    // 退出 Excel 应用程序
    excel->dynamicCall("Quit()");

    // 释放 Excel 对象
    delete excel;
    excel = nullptr;
    return true;
}

//获取单元格的数据
QString Data::getCellData(int row, int col)
{
    if(row<0||row>tableData.size()||col<0||col>tableData[row].size())
    return "";
    return tableData[row][col];
}

//改变单元格的数据
void Data::setCellData(int row, int col, QString data)
{
    if(row<0||row>tableData.size()||col<0||col>tableData[row].size())
    return;
    tableData[row][col]=data;
}
