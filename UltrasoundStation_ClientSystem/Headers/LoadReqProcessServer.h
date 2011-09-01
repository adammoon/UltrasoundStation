#ifndef LOADREQPROCESSSERVER_H
#define LOADREQPROCESSSERVER_H
#include <QObject>
#include <QThread>
#include "Headers/SignRequest.h"
class QList<class T>;
class QSignRequest;
//ʹ��"����ģʽ"ʵ�ָ÷�������
class QLoadReqProcServer:public QObject{
    Q_OBJECT
public:
    static QLoadReqProcServer* getServerInstance();
    static bool closeServerInstance(void);

    static bool newReq(QSignRequest* req);         //������
    static bool cancelReq(QSignRequest* req);      //ȡ������

    static bool startLoadReqProcServer(bool restart = false);   //��������
    static bool getReqProcServerRunStatus(void);

private:
    QLoadReqProcServer();
    ~QLoadReqProcServer();
    static QLoadReqProcServer* serverInstance;      /*< Ψһ�ķ��������     */
    static QList<QSignRequest*> waitProcQueue;      /*< �ȴ������������     */
    static QList<QSignRequest*> denyQueue;
    static QList<QSignRequest*> acceptQueue;
    static QList<QSignRequest*> cancelQueue;
    //functions
    static void ProcessReq(void);
    static bool queryReqInfor( QSignRequest* req);
    static void recordSignReq( QSignRequest* req);
    //for debug
    static void checkQueue(void);
    bool isRunning;
signals:
    void reqProcessed(QObject* req,QSignRequest::REQ_STATUS procResult);   //�źź�������Ҫ��cpp�����ʵ�ִ���
};

#endif // LOADREQPROCESSSERVER_H
