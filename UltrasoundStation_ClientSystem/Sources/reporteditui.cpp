#include "Headers/reporteditui.h"
#include "ui_reporteditui.h" //这个文件在编译后才会输出

reportEditUi::reportEditUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reportEditUi)
{
    ui->setupUi(this);
}

reportEditUi::~reportEditUi()
{
    delete ui;
}
