#ifndef LOADREQPROCESSSERVER_H
#define LOADREQPROCESSSERVER_H
#include <QObject>
#include <QThread>
#include "Headers/SignRequest.h"
class QList<class T>;
class QSignRequest;
class QMutex;
//使用"单件模式"实现该服务器类
class QLoadReqProcServer:public QThread{
    Q_OBJECT
public:
    static QLoadReqProcServer* getServerInstance();

    static bool newReq(QSignRequest* req);         //新请求
    static bool cancelReq(QSignRequest* req);      //取消请求

    static QSignRequest::REQ_STATUS queryREQStatus(QSignRequest* req);  /**< 给用户的查询接口*/
    static void stopLoadReqProcServer(void);        //退出该线程
private:
    QLoadReqProcServer();
    ~QLoadReqProcServer();
    void run();                                                             //线程函数
    static QLoadReqProcServer* serverInstance;      /**< 唯一的服务器句柄     */
    static QList<QSignRequest*> waitProcQueue;      /**< 等待处理请求队列     */
    static QList<QSignRequest*> denyQueue;
    static QList<QSignRequest*> acceptQueue;
    static QList<QSignRequest*> cancelQueue;
    static QList<QSignRequest*> overQueue;          /**< 已处理的取消队列     */
    static QMutex mutex;                            /**< 临界区访问*/
    static QMutex mutex_Stop;
    static bool bStop;
    //functions
    static void ProcessReq(void);
    static bool queryReqInfor( QSignRequest* req);  /**< 用于验证用户信息是否有效*/
    static void recordSignReq( QSignRequest* req);
    static void clean();                            /**< 线程退出时执行清理功能*/
    static bool findReqInQueue(QList<QSignRequest*> reqQue,QSignRequest* req);
    //for debug
    static void checkQueue(void);
signals:
    //void reqProcessed(QObject* req,QSignRequest::REQ_STATUS procResult);   //信号函数不需要在cpp中添加实现代码
};

#endif // LOADREQPROCESSSERVER_H
