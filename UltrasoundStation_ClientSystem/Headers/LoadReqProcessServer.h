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

    static bool newReq(QSignRequest* req);         //������
    static bool cancelReq(QSignRequest* req);      //ȡ������

    static QSignRequest::REQ_STATUS queryREQStatus(QSignRequest* req);  /**< ���û��Ĳ�ѯ�ӿ�*/
    static void stopLoadReqProcServer(void);        //�˳����߳�
private:
    QLoadReqProcServer();
    ~QLoadReqProcServer();
    void run();                                                             //�̺߳���
    static QLoadReqProcServer* serverInstance;      /**< Ψһ�ķ��������     */
    static QList<QSignRequest*> waitProcQueue;      /**< �ȴ������������     */
    static QList<QSignRequest*> denyQueue;
    static QList<QSignRequest*> acceptQueue;
    static QList<QSignRequest*> cancelQueue;
    static QList<QSignRequest*> overQueue;          /**< �Ѵ����ȡ������     */
    static QMutex mutex;                            /**< �ٽ�������*/
    static QMutex mutex_Stop;
    static bool bStop;
    //functions
    static void ProcessReq(void);
    static bool queryReqInfor( QSignRequest* req);  /**< ������֤�û���Ϣ�Ƿ���Ч*/
    static void recordSignReq( QSignRequest* req);
    static void clean();                            /**< �߳��˳�ʱִ��������*/
    static bool findReqInQueue(QList<QSignRequest*> reqQue,QSignRequest* req);
    //for debug
    static void checkQueue(void);
signals:
    //void reqProcessed(QObject* req,QSignRequest::REQ_STATUS procResult);   //�źź�������Ҫ��cpp�����ʵ�ִ���
};

#endif // LOADREQPROCESSSERVER_H
