#include "Headers/LoadReqProcessServer.h"
#include "commonFunction.h"

#include <QList>
#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QDir>
//static members
QLoadReqProcServer* QLoadReqProcServer::serverInstance = 0;
QList<QSignRequest*> QLoadReqProcServer::acceptQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::waitProcQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::denyQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::cancelQueue = QList<QSignRequest*>();
//overQueue�б�����ȡ�������ɹ�������
QList<QSignRequest*> QLoadReqProcServer::overQueue = QList<QSignRequest*>();

bool QLoadReqProcServer::bStop = false;
QMutex QLoadReqProcServer::mutex ;
QMutex QLoadReqProcServer::mutex_Stop ;

QString logFileName = QString(".client.Log");

QLoadReqProcServer* QLoadReqProcServer::getServerInstance(){
    if( 0 != QLoadReqProcServer::serverInstance ){
        return QLoadReqProcServer::serverInstance;
    }else{
        return new QLoadReqProcServer();
    }
}

QLoadReqProcServer::QLoadReqProcServer(){
}
QLoadReqProcServer::~QLoadReqProcServer(){
    qDebug("~QLoadReqProcServer()");
}
//�µĵ�¼����
bool QLoadReqProcServer::newReq(QSignRequest *req){
    if( 0 == req ){
        qDebug("QLoadReqProcServer::newReq(req):req should not be zero!\n");
        return false;
    }
    mutex.lock();
    QLoadReqProcServer::waitProcQueue.append(req);
    //���ӷ�������������źźͲۣ����ȴ������е�Ԫ�ر�����ʱ������֪ͨ�������
    //connect(QLoadReqProcServer::getServerInstance(),SIGNAL(reqProcessed(QObject*,QSignRequest::REQ_STATUS)),req,SLOT(Req_Processed(QObjcet*,QSignRequest::REQ_STATUS)));
    //��¼������־��
    QLoadReqProcServer::recordSignReq(req);
    mutex.unlock();
    return true;
}
//ȡ����¼������
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
//����Ŀǰ�����е�����
void QLoadReqProcServer::ProcessReq(){
    if(!QLoadReqProcServer::waitProcQueue.isEmpty()){
        qDebug("The Wait Queue is not empty!");
        QSignRequest* lREQ = QLoadReqProcServer::waitProcQueue.first();
        lREQ->reqType = QSignRequest::REQ_LOGOUT;
        if( findReqInQueue(cancelQueue,lREQ) ){
            qDebug("cancel req");
            waitProcQueue.removeAll(lREQ);
            cancelQueue.removeAll(lREQ);
            lREQ->reqStatus = QSignRequest::REQ_OVER;
            overQueue.append(lREQ);
            return;
        }
        lREQ->reqType = QSignRequest::REQ_SIGNIN;
        Q_ASSERT_X(lREQ->reqStatus == QSignRequest::REQ_INQUE,"in ProcessReq()","wait queue' item should be REQ_INQUE status");
        if( true == queryReqInfor( lREQ ) ){
            //�û���֤Ϊ�Ϸ��û���������Ϣ
            lREQ->reqStatus = QSignRequest::REQ_ACCEPT;
            QLoadReqProcServer::acceptQueue.append(lREQ);//��������뵽���ܶ�����
            qDebug("In Server Thread:user sign req accept!");
        }else{//�Ƿ��û�
             lREQ->reqStatus = QSignRequest::REQ_REJECT;
            QLoadReqProcServer::denyQueue.append(lREQ);//���������ܾ�����
            qDebug("user sign req reject!");
            }
        QLoadReqProcServer::waitProcQueue.removeFirst();
        qDebug("wait queue is not empty!");
    }
}
//��ѯ�����Ƿ��ܹ��������Ƿ�Ϸ�
bool QLoadReqProcServer::queryReqInfor( QSignRequest* req){
    if( 0 == req){
        return false;
    }
    //������֤����:������ʹ�ü��ı��洢���û���Ϣ��֤��Ҳ���������ݿ�洢���û���Ϣ��֤
    return false;
}
//��¼Ŀǰ�ڷ������ϵ��˺���Ϣ
void QLoadReqProcServer::recordSignReq( QSignRequest* req){
    QString reqTime = req->reqTime;
    QString name = req->reqForSignInfor->nameInfo;
    QString role;
    QString procResult;
    switch(req->reqForSignInfor->roleInfo){
        case QSignInfo::ROLE_DOCTOR:
        role = "Doctor";
        break;
        case QSignInfo::ROLE_VISITOR:
        role = "Visitor";
        break;
        case QSignInfo::ROLE_ADMIN:
        role = "Admin";
        break;
    }
    switch(req->reqStatus){
        case QSignRequest::REQ_ACCEPT:
        procResult = "accept";
        break;
        case QSignRequest::REQ_REJECT:
        procResult = "reject";
        break;
        case QSignRequest::REQ_INQUE:
        procResult = "inque";
        break;
        case QSignRequest::REQ_OVER:
        procResult = "cancelled";
        break;
    }
    QFile logFile(QDir::homePath()+logFileName);
    if(logFile.exists()){
        qDebug("log file not exists");
    }
    if(!logFile.open(QIODevice::ReadWrite|QIODevice::Append)){
        qDebug("fault");
        QFile::FileError err = logFile.error();
        Q_UNUSED(err);
        qDebug("fault");
        return;
    }
    QTextStream outer(&logFile);
    outer<<qSetFieldWidth(10)<<reqTime<<name <<role<<procResult;
    logFile.close();
    qDebug("recordSignReq() not implement in current!\n");
}
//Ϊ�˲���Ŀ��
void QLoadReqProcServer::checkQueue(){
    //���������ͼ����Ȼ���ǵ�ÿһ�������е�Ԫ��Ӧ�þ�����ͬ������
    //����:��waitProcQueue�е������״̬��Ӧ����REQ_INQUE
    //1.���waitProcQueue
    QList<QSignRequest* >::iterator itor;
    for(itor = waitProcQueue.begin();itor != waitProcQueue.end();itor++){
        if((*itor)->ProcessSignReq() != QSignRequest::REQ_INQUE){
            Q_ASSERT_X(false,"in checkQueue","while check waitProcQueue");
        }
    }
}
//�û���ѯREQ״̬�Ľӿ�
QSignRequest::REQ_STATUS QLoadReqProcServer::queryREQStatus(QSignRequest* req){
    if( 0 == req ){
        qDebug("queryREQStatus param should not be zero!\n");
        return QSignRequest::REQ_REJECT;
    }
    QSignRequest::REQ_STATUS s = QSignRequest::REQ_INQUE;
    mutex.lock();
    if( waitProcQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_INQUE;
    }
    if( acceptQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_ACCEPT;
    }
    if( acceptQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_REJECT;
    }if( overQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_OVER;
    }
    mutex.unlock();
    return s;
}
//stopLoadReqProcServer()
void QLoadReqProcServer::stopLoadReqProcServer(){
    mutex_Stop.lock();
    bStop= true;
    mutex_Stop.unlock();
}
//clean()
void QLoadReqProcServer::clean(){
    qDebug("befor quit, clean the server thread");
    QSignRequest* temp = NULL;
    while(!waitProcQueue.isEmpty()){
        //����ȴ�����
        temp = waitProcQueue.takeFirst();
        SAFE_DELETE(temp->reqForSignInfor);
        SAFE_DELETE(temp);
    }
    while(!denyQueue.isEmpty()){
        //����ܾ�����
        temp = denyQueue.takeFirst();
        SAFE_DELETE(temp->reqForSignInfor);
        SAFE_DELETE(temp);
    }
    while(!acceptQueue.isEmpty()){
        //������ܶ���
        temp = acceptQueue.takeFirst();
        SAFE_DELETE(temp->reqForSignInfor);
        SAFE_DELETE(temp);
    }
    while(!overQueue.isEmpty()){
        //������ܶ���
        temp = overQueue.takeFirst();
        SAFE_DELETE(temp->reqForSignInfor);
        SAFE_DELETE(temp);
    }
    SAFE_DELETE(serverInstance);
}
//findReqInQueue
bool QLoadReqProcServer::findReqInQueue(QList<QSignRequest*> reqQue, QSignRequest *req){
    if(reqQue.isEmpty()){
        return false;
    }
    if( NULL == req ){
        return false;
    }
    QList<QSignRequest* >::iterator itor;
    for ( itor = reqQue.begin();itor != reqQue.end(); itor++)
        {
            if(*(*itor) == *req){
                return true;
            }
        }
    return false;
}

//�̺߳���
void QLoadReqProcServer::run(){
    while(1){
        mutex.lock();
        ProcessReq();   //��������д���
        mutex.unlock();
        mutex_Stop.lock();
        if(bStop){
            break;
        }
        mutex_Stop.unlock();
    }
    //�����߳���Դ���������
    clean();
    qDebug("thread will end!");
    exec();
}

