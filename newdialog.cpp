#include "newdialog.h"
#include "ui_newdialog.h"

newDialog::newDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newDialog)
{
    ui->setupUi(this);
}

newDialog::~newDialog()
{
    delete ui;
}

void newDialog::on_buttonSure_clicked()
{
    int row=ui->spinBoxRow->value();
    int col=ui->spinBoxCol->value();
    emit Created(row,col);
    close();
}


void newDialog::on_buttonClear_clicked()
{
    ui->spinBoxRow->clear();
    ui->spinBoxCol->clear();
}

