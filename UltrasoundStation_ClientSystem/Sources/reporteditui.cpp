#include "Headers/reporteditui.h"
#include "ui_reporteditui.h" //����ļ��ڱ����Ż����

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
