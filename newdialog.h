#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QWidget>

namespace Ui {
class newDialog;
}

class newDialog : public QWidget
{
    Q_OBJECT

public:
    explicit newDialog(QWidget *parent = nullptr);
    ~newDialog();

private slots:
    void on_buttonSure_clicked();
    void on_buttonClear_clicked();
signals:
    void Created(int,int);

private:
    Ui::newDialog *ui;
};

#endif // NEWDIALOG_H
