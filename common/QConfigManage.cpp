#include "QConfigManage.h"
#include <QTextCodec>
#include <QString>
#include <QVariant>
#include <QSettings>
//static members

QString QConfigManager::keyLoadLogFileName = "Log_Sec/LoadLogFileName_Key";
//配置文件使用ini格式保存，保存在当前用户文件夹下
QSettings QConfigManager::configFile(QSettings::IniFormat,QSettings::UserScope,"SWUST.CS","ULTRASOUND_STATION");
//私有的构造和析构函数
QConfigManager::QConfigManager(){
    Q_ASSERT_X(false,"in QConfigManager.cpp","QConfigMananger can't have any object");
}
QConfigManager::~QConfigManager(){
    Q_ASSERT_X(false,"in QConfigManager.cpp","QConfigManager can't destory any object");
}
//初始化配置
void QConfigManager::initCfgManager(){
    //设置配置文件的编码为中文GB18030
    configFile.setIniCodec("GB18030-0");
    qDebug("QConfigManager.cpp:initCfgmanager()");
}
//getKeyValue
QVariant QConfigManager::getKeyValue(const QString& key){
    qDebug("QConfigManager.cpp：getKeyValue() run in");
    if( key.isEmpty() ){
        qDebug("QConfigManager.cpp：getKeyValue() run out");
        return QVariant();
    }
    return configFile.value(key);
    qDebug("QConfigManager.cpp：getKeyValue() run out");
}
void QConfigManager::writeKeyValue(const QString&key,QVariant value){
    if(key.isEmpty()){
        return;
    }
    configFile.setValue(key,value);
}
