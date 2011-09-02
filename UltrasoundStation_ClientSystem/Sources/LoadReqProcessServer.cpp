#include "Headers/LoadReqProcessServer.h"

#include <QList>
#include <QMutex>

//static members
QLoadReqProcServer* QLoadReqProcServer::serverInstance = 0;
QList<QSignRequest*> QLoadReqProcServer::acceptQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::waitProcQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::denyQueue = QList<QSignRequest*>();
QList<QSignRequest*> QLoadReqProcServer::cancelQueue = QList<QSignRequest*>();
QMutex QLoadReqProcServer::mutex ;

QLoadReqProcServer* QLoadReqProcServer::getServerInstance(){
    if( 0 != QLoadReqProcServer::serverInstance ){
        return QLoadReqProcServer::serverInstance;
    }else{
        return new QLoadReqProcServer();
    }
}

bool QLoadReqProcServer::closeServerInstance(void){
    qDebug("QLoadReqProcServer::closeServerInstance(void)");
    //�������ٷ������Ĺ���
    return true;
}

QLoadReqProcServer::QLoadReqProcServer(){
}
QLoadReqProcServer::~QLoadReqProcServer(){

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
        QSignRequest*lREQ = QLoadReqProcServer::waitProcQueue.first();
        Q_ASSERT_X(lREQ->reqStatus == QSignRequest::REQ_INQUE,"in ProcessReq()","wait queue' item should be REQ_INQUE status");
        if( true == queryReqInfor( lREQ ) ){
            //�û���֤Ϊ�Ϸ��û���������Ϣ
            //emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_ACCEPT);
            lREQ->reqStatus = QSignRequest::REQ_ACCEPT;
            QLoadReqProcServer::acceptQueue.append(lREQ);//��������뵽���ܶ�����
            qDebug("In Server Thread:user sign req accept!");
        }else{//�Ƿ��û�
            //emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_REJECT);
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
    qDebug("recordSignReq() not implement in curQ_ASSERT(false);rent!\n");
}
//void QLoadReqProcServer::reqProcessed(QSignRequest::REQ_STATUS procResult){
//    qDebug("QLoadReqProcServer::reqProcessed");
//}
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
    QSignRequest::REQ_STATUS s;
    mutex.lock();
    if( waitProcQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_INQUE;
    }
    if( acceptQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_ACCEPT;
    }
    if( acceptQueue.indexOf(req) != -1){
        s = QSignRequest::REQ_REJECT;
    }
    mutex.unlock();
    return s;
}
//�̺߳���
void QLoadReqProcServer::run(){
    while(1){
        mutex.lock();
        ProcessReq();
        mutex.unlock();
    }
    qDebug("thread will end!");
    exec();
}

