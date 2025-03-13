#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include <QTableWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openFile();//打开文件
    void saveFile();//保存文件
    //用来接受如果单元格内容发生变化，那么data也要发生变化
    void on_tableWidget_cellChanged(int row, int column);
    void newFile();//用于信号连接，接受来自dialog的行数和列数
    void tableCreated(int,int);//创建一个空白的excel表格
    void insert();//插入行/列
    void Delete();//删除行/列
    void searchInTable();//在内部查询
    void replaceInTable();//替换

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    Data *data;
};
#endif // MAINWINDOW_H
