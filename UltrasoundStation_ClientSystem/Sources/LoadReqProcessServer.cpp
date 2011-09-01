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
    //�������ٷ������Ĺ���
    return true;
}

QLoadReqProcServer::QLoadReqProcServer(){
    isRunning = false;//�߳�δ����
}

QLoadReqProcServer::~QLoadReqProcServer(){

}
//�µĵ�¼����
bool QLoadReqProcServer::newReq(QSignRequest *req){
    if( 0 == req ){
        qDebug("QLoadReqProcServer::newReq(req):req should not be zero!\n");
        return false;
    }
    QLoadReqProcServer::waitProcQueue.append(req);
    //���ӷ�������������źźͲۣ����ȴ������е�Ԫ�ر�����ʱ������֪ͨ�������
    connect(QLoadReqProcServer::getServerInstance(),SIGNAL(reqProcessed(QObject*,QSignRequest::REQ_STATUS)),req,SLOT(Req_Processed(QObjcet*,QSignRequest::REQ_STATUS)));
    //��¼������־��
    QLoadReqProcServer::recordSignReq(req);
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
//�����������������߳�,��ʹ�ö����߳�ʵ�ַ���ʱ��Ҫ�ص��޸�
bool QLoadReqProcServer::startLoadReqProcServer(bool restart){
    if(restart){
        qDebug("����load server!\n");
        QLoadReqProcServer::serverInstance->isRunning = true;
        QLoadReqProcServer::ProcessReq();
        return true;
    }
    QLoadReqProcServer::ProcessReq();
    return true;
}
//��ȡ��������״̬
bool QLoadReqProcServer::getReqProcServerRunStatus(){
    return QLoadReqProcServer::getServerInstance()->isRunning;
}

//����Ŀǰ�����е�����
void QLoadReqProcServer::ProcessReq(){
    while(false == waitProcQueue.empty()){
        if( true == queryReqInfor( waitProcQueue.first() ) ){
            //�û���֤Ϊ�Ϸ��û���������Ϣ
            emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_ACCEPT);
            acceptQueue.append(waitProcQueue.first());//��������뵽���ܶ�����
        }else{//�Ƿ��û�
            emit serverInstance->reqProcessed((QObject*)waitProcQueue.first(),QSignRequest::REQ_REJECT);
            denyQueue.append(waitProcQueue.first());//���������ܾ�����
        }
        waitProcQueue.removeFirst();
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
    qDebug("recordSignReq() not implement in current!\n");
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
