#include "Headers/LoadReqProcessServer.h"

#include <QList>

//static members
QLoadReqProcServer* QLoadReqProcServer::serverInstance = 0;
QList<QSignRequest*> QLoadReqProcServer::acceptQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::waitProcQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::denyQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::cancelQueue = QList<QSignRequest*>();

QLoadReqProcServer* QLoadReqProcServer::getServerInstance(){
    if( 0 != QLoadReqProcServer::serverInstance ){
        return QLoadReqProcServer::serverInstance;
    }else{
        return new QLoadReqProcServer();
    }
}

bool QLoadReqProcServer::closeServerInstance(void){
    qDebug("QLoadReqProcServer::closeServerInstance(void)");
    //加入销毁服务器的过程
    return true;
}

QLoadReqProcServer::QLoadReqProcServer(){
    isRunning = false;//线程未启动
}

QLoadReqProcServer::~QLoadReqProcServer(){

}
//新的登录请求
bool QLoadReqProcServer::newReq(QSignRequest *req){
    if( 0 == req ){
        qDebug("QLoadReqProcServer::newReq(req):req should not be zero!\n");
        return false;
    }
    QLoadReqProcServer::waitProcQueue.append(req);
    //连接服务器和请求的信号和槽，当等待队列中的元素被处理时，将会通知请求对象
    connect(QLoadReqProcServer::getServerInstance(),SIGNAL(reqProcessed(QObject*,QSignRequest::REQ_STATUS)),req,SLOT(Req_Processed(QObjcet*,QSignRequest::REQ_STATUS)));
    //记录请求到日志中
    QLoadReqProcServer::recordSignReq(req);
    return true;
}
//取消登录的请求
bool QLoadReqProcServer::cancelReq( QSignRequest *req){
    if( 0 == req ){
        qDebug("QLoadReqProcServer::cancelReq(req):req should not be zero!\n");
        return false;
    }
    if( true == QLoadReqProcServer::waitProcQueue.contains(req) ){
        QLoadReqProcServer::waitProcQueue.removeOne(req);
        QLoadReqProcServer::cancelQueue.append(req);
    }
    return true;
}
//启动或者重启服务线程,当使用独立线程实现服务时需要重点修改
bool QLoadReqProcServer::startLoadReqProcServer(bool restart){
    if(restart){
        qDebug("重启load server!\n");
        QLoadReqProcServer::serverInstance->isRunning = true;
        QLoadReqProcServer::ProcessReq();
        return true;
    }
    QLoadReqProcServer::ProcessReq();
    return true;
}
//获取服务运行状态
bool QLoadReqProcServer::getReqProcServerRunStatus(){
    return QLoadReqProcServer::getServerInstance()->isRunning;
}

//处理目前队列中的请求
void QLoadReqProcServer::ProcessReq(){
    while(false == waitProcQueue.empty()){
        if( true == queryReqInfor( waitProcQueue.first() ) ){
            //用户验证为合法用户，触发消息
            emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_ACCEPT);
            acceptQueue.append(waitProcQueue.first());//将请求加入到接受队列中
        }else{//非法用户
            emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_REJECT);
            denyQueue.append(waitProcQueue.first());//将请求加入拒绝队列
        }
        waitProcQueue.removeFirst();
    }
}
//查询请求是否能够被允许，是否合法
bool QLoadReqProcServer::queryReqInfor( QSignRequest* req){
    if( 0 == req){
        return false;
    }
    //加入验证代码:可以是使用简单文本存储的用户信息验证，也可以是数据库存储的用户信息验证
    return false;
}
//记录目前在服务器上的账号信息
void QLoadReqProcServer::recordSignReq( QSignRequest* req){
    qDebug("recordSignReq() not implement in current!\n");
}

//void QLoadReqProcServer::reqProcessed(QSignRequest::REQ_STATUS procResult){
//    qDebug("QLoadReqProcServer::reqProcessed");
//}
//为了测试目的
void QLoadReqProcServer::checkQueue(){
    //按照设计意图，显然我们的每一个队列中的元素应该具有相同的特征
    //例如:在waitProcQueue中的请求的状态都应该是REQ_INQUE
    //1.检查waitProcQueue
    QList<QSignRequest* >::iterator itor;
    for(itor = waitProcQueue.begin();itor != waitProcQueue.end();itor++){
        if((*itor)->ProcessSignReq() != QSignRequest::REQ_INQUE){
            Q_ASSERT_X(false,"in checkQueue","while check waitProcQueue");
        }
    }
}
