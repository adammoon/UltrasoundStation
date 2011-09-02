#ifndef LOADREQPROCESSSERVER_H
#define LOADREQPROCESSSERVER_H
#include <QObject>
#include <QThread>
#include "Headers/SignRequest.h"
class QList<class T>;
class QSignRequest;
class QMutex;
//ʹ��"����ģʽ"ʵ�ָ÷�������
class QLoadReqProcServer:public QThread{
    Q_OBJECT
public:
    static QLoadReqProcServer* getServerInstance();
    static bool closeServerInstance(void);

    static bool newReq(QSignRequest* req);         //������
    static bool cancelReq(QSignRequest* req);      //ȡ������

    static QSignRequest::REQ_STATUS queryREQStatus(QSignRequest* req);  /**< ���û��Ĳ�ѯ�ӿ�*/
private:
    QLoadReqProcServer();
    ~QLoadReqProcServer();
    void run();                                                             //�̺߳���
    static QLoadReqProcServer* serverInstance;      /**< Ψһ�ķ��������     */
    static QList<QSignRequest*> waitProcQueue;      /**< �ȴ������������     */
    static QList<QSignRequest*> denyQueue;
    static QList<QSignRequest*> acceptQueue;
    static QList<QSignRequest*> cancelQueue;
    static QMutex mutex;                                            /**< �ٽ�������*/
    //functions
    static void ProcessReq(void);
    static bool queryReqInfor( QSignRequest* req);  /**< ������֤�û���Ϣ�Ƿ���Ч*/
    static void recordSignReq( QSignRequest* req);
    //for debug
    static void checkQueue(void);
signals:
    //void reqProcessed(QObject* req,QSignRequest::REQ_STATUS procResult);   //�źź�������Ҫ��cpp�����ʵ�ִ���
};

#endif // LOADREQPROCESSSERVER_H
