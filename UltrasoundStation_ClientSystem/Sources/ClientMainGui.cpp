#include "Headers/ClientMainGui.h"
//Qt include
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
QClientMainGui* QClientMainGui::mainGui = 0;

QClientMainGui* QClientMainGui::getGuiInstance(){
    if(0 != QClientMainGui::mainGui){
        qDebug("use old GUI");
        return QClientMainGui::mainGui;
    }else{
        qDebug("create new GUI");
        return ( 0 == (QClientMainGui::mainGui = new QClientMainGui()))? 0 : QClientMainGui::mainGui;
    }
}

QClientMainGui::QClientMainGui(QWidget *parent){
    Q_UNUSED(parent);
    //do nothing
    setMenuContext();
    move(1,1);
    resize(800,600);
}

QClientMainGui::~QClientMainGui(){

}

bool QClientMainGui::setMenuContext(){
    qDebug("%s\n","QClientMainGui::setMenuContext()");
    bool rValue = true;
    mainMenuBar = new QMenuBar(this);
    if( !mainMenuBar ){
        return false;
    }
    QMenu* loadMenu = new QMenu("&SignIn",this);
    mainMenuBar->addMenu(loadMenu);
    return rValue;
}

void QClientMainGui::signal_slots_connect()const{
    qDebug("%s\n","QClientMainGui::signal_slots_connect()");
}
