#ifndef LOADREQPROCESSSERVER_H
#define LOADREQPROCESSSERVER_H
#include <QObject>
#include <QThread>
#include "Headers/SignRequest.h"
class QList<class T>;
class QSignRequest;
//使用"单件模式"实现该服务器类
class QLoadReqProcServer:public QObject{
    Q_OBJECT
public:
    static QLoadReqProcServer* getServerInstance();
    static bool closeServerInstance(void);

    static bool newReq(QSignRequest* req);         //新请求
    static bool cancelReq(QSignRequest* req);      //取消请求

    static bool startLoadReqProcServer(bool restart = false);   //启动处理
    static bool getReqProcServerRunStatus(void);

private:
    QLoadReqProcServer();
    ~QLoadReqProcServer();
    static QLoadReqProcServer* serverInstance;      /*< 唯一的服务器句柄     */
    static QList<QSignRequest*> waitProcQueue;      /*< 等待处理请求队列     */
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
    void reqProcessed(QObject* req,QSignRequest::REQ_STATUS procResult);   //信号函数不需要在cpp中添加实现代码
};

#endif // LOADREQPROCESSSERVER_H
