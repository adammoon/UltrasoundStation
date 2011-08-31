#include "Headers/SignRequest.h"

#include <QQueue>
QQueue<QSignRequest* > QSignRequest::sign_req_queue = QQueue<QSignRequest*>();

QSignRequest::QSignRequest(QObject *parent):QObject(parent){
}

QSignRequest::QSignRequest(const QSignInfo *signInfor, REQ_SRC_TYPE signReqTye, REQ_TYPE signType, QObject *parent):QObject(parent){
    if(0 == signInfor){
        qDebug("In QSignRequest() the QSignInfo pointer can't be zero!");
        return;
    }
    //1.为私有变量赋值
    //2.将当前请求加入到请求队列中

}
