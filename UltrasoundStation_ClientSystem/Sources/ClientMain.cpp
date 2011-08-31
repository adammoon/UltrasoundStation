#include <QtGui/QApplication>
#include "Headers/ClientMainGui.h"

int main(int argc, char *argv[])
{
    QApplication client(argc, argv);
    QClientMainGui* gui;
    gui = QClientMainGui::getGuiInstance();
    gui->show();
    return client.exec();
}
