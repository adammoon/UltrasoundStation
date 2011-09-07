#include "Headers/qreportmanageui.h"
#include "ui_qreportmanageui.h"

QReportManageUi::QReportManageUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QReportManageUi)
{
    ui->setupUi(this);
}

QReportManageUi::~QReportManageUi()
{
    delete ui;
}
