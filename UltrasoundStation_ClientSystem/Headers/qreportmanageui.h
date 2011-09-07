#ifndef QREPORTMANAGEUI_H
#define QREPORTMANAGEUI_H

#include <QWidget>

namespace Ui {
    class QReportManageUi;
}

class QReportManageUi : public QWidget
{
    Q_OBJECT

public:
    explicit QReportManageUi(QWidget *parent = 0);
    ~QReportManageUi();

private:
    Ui::QReportManageUi *ui;
};

#endif // QREPORTMANAGEUI_H
