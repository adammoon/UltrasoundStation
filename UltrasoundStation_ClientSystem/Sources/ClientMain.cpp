#include <QtGui/QApplication>
#include "Headers/ClientMainGui.h"
#include "Headers/signinwidget.h"
#include "Headers/LoadReqProcessServer.h"
int main(int argc, char *argv[])
{
    QApplication client(argc, argv);
//    QClientMainGui* gui;
//    gui = QClientMainGui::getGuiInstance();
//    gui->show();
    //������¼����
    QLoadReqProcServer* loadAdminServer = QLoadReqProcServer::getServerInstance();
    loadAdminServer->start();
    QsignInWidget gui;
    gui.show();
    return client.exec();
}
