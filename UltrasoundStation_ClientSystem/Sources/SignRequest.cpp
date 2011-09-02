#include "../common/commonFunction.h"
#include "Headers/SignRequest.h"
#include "Headers/LoadReqProcessServer.h"

#include <QString>

QSignRequest::QSignRequest(QObject *parent):QObject(parent){
}
//构造函数2
QSignRequest::QSignRequest( QString &name,
                            QString &passwd,
                            QSignInfo::LOG_ROLE role,
                           REQ_SRC_TYPE signReqType, REQ_TYPE signType,
                           QObject *parent):QObject(parent){
    reqForSignInfor = new QSignInfo(name,role,passwd);
    this->requestSrcType = signReqType;
    this->reqStatus = QSignRequest::REQ_INQUE;
    this->reqType = signType;
    //2.通知服务器有新的请求包到达
    QLoadReqProcServer::newReq(this);
}

//构造函数3
QSignRequest::QSignRequest(QSignInfo *signInfor, REQ_SRC_TYPE signReqType, REQ_TYPE signType, QObject *parent):QObject(parent){
    if(0 == signInfor){
        qDebug("In QSignRequest() the QSignInfo pointer can't be zero!");
        return;
    }
    //1.为私有变量赋值
    this->reqForSignInfor = signInfor;
    this->requestSrcType = signReqType;
    this->reqStatus = QSignRequest::REQ_INQUE;
    this->reqType = signType;
    //2.通知服务器有新的请求包到达
    QLoadReqProcServer::newReq(this);
}

QSignRequest::~QSignRequest(){
    //释放请求
    //1.向服务器申请取消该请求
    QLoadReqProcServer::cancelReq(this);
    //2.删除登录请求的相关信息
    SAFE_DELETE(reqForSignInfor);
}
//处理用户发出的请求，系统与用户通过该接口的返回值来获知用户请求是否被接受
QSignRequest::REQ_STATUS QSignRequest::ProcessSignReq(){
    //qDebug("QSignRequest::REQ_STATUS QSignRequest::ProcessSignReq()\n");
    return this->reqStatus;
}
//==操作符重载
bool QSignRequest::operator ==(QSignRequest& req){
    if(*this->reqForSignInfor == *req.reqForSignInfor &&
       this->reqStatus == req.reqStatus &&
       this->requestSrcType == req.requestSrcType &&
       this->reqType == req.reqType ){
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
       this->roleInfo == infor.roleInfo){
        return true;
    }
    return false;
}
