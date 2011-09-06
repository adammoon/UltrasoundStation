#ifndef REPORTEDITUI_H
#define REPORTEDITUI_H

#include <QWidget>

namespace Ui {
    class reportEditUi;
}

class reportEditUi : public QWidget
{
    Q_OBJECT

public:
    explicit reportEditUi(QWidget *parent = 0);
    ~reportEditUi();

private:
    Ui::reportEditUi *ui;
};

#endif // REPORTEDITUI_H
