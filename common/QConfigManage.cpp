#include "QConfigManage.h"
#include <QTextCodec>
#include <QString>
#include <QVariant>
#include <QSettings>
//static members

QString QConfigManager::keyLoadLogFileName = "Log_Sec/LoadLogFileName_Key";
//�����ļ�ʹ��ini��ʽ���棬�����ڵ�ǰ�û��ļ�����
QSettings QConfigManager::configFile(QSettings::IniFormat,QSettings::UserScope,"SWUST.CS","ULTRASOUND_STATION");
//˽�еĹ������������
QConfigManager::QConfigManager(){
    Q_ASSERT_X(false,"in QConfigManager.cpp","QConfigMananger can't have any object");
}
QConfigManager::~QConfigManager(){
    Q_ASSERT_X(false,"in QConfigManager.cpp","QConfigManager can't destory any object");
}
//��ʼ������
void QConfigManager::initCfgManager(){
    //���������ļ��ı���Ϊ����GB18030
    configFile.setIniCodec("GB18030-0");
    qDebug("QConfigManager.cpp:initCfgmanager()");
}
//getKeyValue
QVariant QConfigManager::getKeyValue(const QString& key){
    qDebug("QConfigManager.cpp��getKeyValue() run in");
    if( key.isEmpty() ){
        qDebug("QConfigManager.cpp��getKeyValue() run out");
        return QVariant();
    }
    return configFile.value(key);
    qDebug("QConfigManager.cpp��getKeyValue() run out");
}
void QConfigManager::writeKeyValue(const QString&key,QVariant value){
    if(key.isEmpty()){
        return;
    }
    configFile.setValue(key,value);
}
