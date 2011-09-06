#include "../common/commonFunction.h"
#include "Headers/SignRequest.h"
#include "Headers/LoadReqProcessServer.h"

#include <QString>
#include <QDateTime>

QSignRequest::QSignRequest(QObject *parent):QObject(parent){
}
//���캯��2
QSignRequest::QSignRequest( QString &name,
                            QString &passwd,
                            QSignInfo::LOG_ROLE role,
                           REQ_SRC_TYPE signReqType, REQ_TYPE signType,
                           QObject *parent):QObject(parent){
    reqForSignInfor = new QSignInfo(name,role,passwd);
    this->requestSrcType = signReqType;
    this->reqStatus = QSignRequest::REQ_INQUE;
    this->reqType = signType;
    reqTime = QDateTime::currentDateTime().toString("yyMMddhhmmss");
//    QDateTime curTime = QDateTime::currentDateTime();
//    reqTime = curTime.toString("yyMMddhhmmss");
    //2.֪ͨ���������µ����������
    QLoadReqProcServer::newReq(this);
}

//���캯��3
QSignRequest::QSignRequest(QSignInfo *signInfor, REQ_SRC_TYPE signReqType, REQ_TYPE signType, QObject *parent):QObject(parent){
    if(0 == signInfor){
        qDebug("In QSignRequest() the QSignInfo pointer can't be zero!");
        return;
    }
    //1.Ϊ˽�б�����ֵ
    this->reqForSignInfor = signInfor;
    this->requestSrcType = signReqType;
    this->reqStatus = QSignRequest::REQ_INQUE;
    this->reqType = signType;
    reqTime = QDateTime::currentDateTime().toString("yyMMddhhmmss");
    //2.֪ͨ���������µ����������
    QLoadReqProcServer::newReq(this);
}

QSignRequest::~QSignRequest(){
    //˵��:
    //����ʹ��QSignRequest����һ������ʱ�������˳�������Χʱ������������
    //�Ⲣ������һ������ȡ�����������Ѿ���¼�ɹ���������ﲻӦ��ɾ���κζ���
    //��¼���󴴽�ʱʹ��new����ʱ����������Ա����ڱ��֣��Ӷ����ݸ�QLoadReqProServer����
    //��ˣ�һ����¼���������Ӧ�ñ��ֵ�QLoadReqProServer�����˳��������û�����һ��ȡ��������
}
//�����û�����������ϵͳ���û�ͨ���ýӿڵķ���ֵ����֪�û������Ƿ񱻽���
QSignRequest::REQ_STATUS QSignRequest::ProcessSignReq(){
    //qDebug("QSignRequest::REQ_STATUS QSignRequest::ProcessSignReq()\n");
    return this->reqStatus;
}
//==����������
bool QSignRequest::operator ==(QSignRequest& req){
    if(*this->reqForSignInfor == *req.reqForSignInfor &&
       this->reqStatus == req.reqStatus &&
       this->requestSrcType == req.requestSrcType &&
       this->reqType == req.reqType &&
       this->reqTime == req.reqTime){
        return true;
    }
    return false;
}

////////////////////////////////////////QSingInfo//////////////////////////////////////////////
QSignInfo::QSignInfo( QString &name, QSignInfo::LOG_ROLE role,  QString passWord){
    nameInfo = name;
    roleInfo = role;
    pwdInfo = passWord;
}
bool QSignInfo::operator ==(QSignInfo& infor){
    if(this->nameInfo == infor.nameInfo &&
       this->pwdInfo == infor.pwdInfo &&
       this->roleInfo == infor.roleInfo ){
        return true;
    }
    return false;
}
