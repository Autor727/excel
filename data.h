#ifndef DATA_H
#define DATA_H

#include<QString>
#include<vector>
#include<QAxObject>
using namespace std;

class Data
{
public:
    Data(QObject *parent = nullptr);
    ~Data();
    int rowCount();//获得行数
    int columnCount();//获得列数
    void setRowCount(int row);//设置行数
    void setColumnCount(int col);//设置列数
    void clear();//清空数据

    bool loadFromFile(const QString&filePath);//从Excel文件中加载数据
    bool saveToFile(const QString&filePath); //保存数据到Excel文件

    QString getCellData(int row,int col);//获得单元格数据
    void setCellData(int row,int col,QString data);//设置单元格数据

public:
   //创建QAxObject对象用来接受excel格式的数据
   QAxObject *excel; // Excel应用对象
   QAxObject *workbook; // 工作簿对象
   QAxObject *worksheet; // 工作表对象
   vector<vector<QString>> tableData; // 数据表格
};

#endif // DATA_H
