/*!
*@file SignRequest.h
*@brief 登录请求封装
*@details 实现登录请求队列
*@author flyfish
*@version 0.0.1
*@date 2011-8-31
*/
#ifndef SIGNREQUSET_H
#define SIGNREQUSET_H
#include <QObject>
<<<<<<< HEAD
class QSignInfo;        //登录请求基本信息
class QQueue<class T>;
class QSignRequest:public QObject{
=======

//class QQueue<class T>;

//!QSignInfo 记录登录基本信息
class QSignInfo{
public:
    typedef enum LOG_ROLE{
        ROLE_DOCTOR,
        ROLE_ADMIN,
        ROLE_VISITOR
    }LOG_ROLE;
    QSignInfo( QString &name,
               QSignInfo::LOG_ROLE role = QSignInfo::ROLE_VISITOR,
               QString passWord = QString(""));
    bool operator ==(QSignInfo& infor);
private:
    QString nameInfo;
    QSignInfo::LOG_ROLE roleInfo;
    QString pwdInfo;
};
class QSignRequest:public QObject{
    Q_OBJECT
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
public://typedefs
    //!请求类型枚举
    /*!
      表示当前登录请求的来源
    */
<<<<<<< HEAD
    typedef enum {
=======
    typedef enum REQ_SRC_TYPE{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        SIGNREQ_LOCAL, /*!< 登录请求来自本机*/
        SIGNREQ_REMOTE /*!< 登录请求来自网络*/
    }REQ_SRC_TYPE;
    //!请求状态
    /*!
      表示当前请求被处理的状态
    */
<<<<<<< HEAD
    typedef enum{
=======
    typedef enum REQ_STATUS{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        REQ_ACCEPT, /*!< 登录请求被接受*/
        REQ_REJECT, /*!< 登录请求被拒绝*/
        REQ_INQUE   /*!< 请求正处于队列中*/
    }REQ_STATUS;
    //!请求类别
    /*!
      本类还可以用于表示用户注销请求，因此具有请求类别
    */
<<<<<<< HEAD
    typedef enum{
=======
    typedef enum REQ_TYPE{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        REQ_SIGNIN, /*!< 用户登录请求*/
        REQ_LOGOUT  /*!< 用户注销请求*/
    }REQ_TYPE;
public://functions
    QSignRequest(QObject* parent = 0);
<<<<<<< HEAD
    QSignRequest(const QSignInfo* signInfor,
                 REQ_SRC_TYPE signReqTye = QSignRequest::SIGNRE_LOCAL,
                 REQ_TYPE signType = QSignRequest::REQ_SIGNIN,
                 QObject* parent =0);
    REQ_STATUS ProcessSignReq(void);
private:
    static QQueue<QSignRequest* > sign_req_queue;/*!< 登录请求队列/
};

=======
    QSignRequest( QString& name,
                  QString& passwd,
                  QSignInfo::LOG_ROLE role,
                 QSignRequest::REQ_SRC_TYPE signReqType = QSignRequest::SIGNREQ_LOCAL,
                 REQ_TYPE signType = QSignRequest::REQ_SIGNIN,
                 QObject* parent =0);
    QSignRequest(QSignInfo* signInfor,
                 REQ_SRC_TYPE signReqType = QSignRequest::SIGNREQ_LOCAL,
                 REQ_TYPE signType = QSignRequest::REQ_SIGNIN,
                 QObject* parent =0);
    ~QSignRequest();
    REQ_STATUS ProcessSignReq(void);
    bool operator ==(QSignRequest& req);
private:
//    static QQueue<QSignRequest* > sign_req_queue;/*!< 登录请求队列    *///这个队列应该有服务器来维护
    REQ_SRC_TYPE requestSrcType;                 /*!< 请求来源       */
    REQ_STATUS reqStatus;                        /*!< 请求状态       */
    REQ_TYPE   reqType;                          /*!< 登录或者注销请求*/
    QSignInfo* reqForSignInfor;                  /*!< 登录信息       */
signals://信号
    void REQ_REACHED(QSignRequest* signReq);
public slots://槽函数
    void Req_Processed(QObject* obj,QSignRequest::REQ_STATUS processResult);//当登录请求处理完成后会发送信号到该槽函数
};


>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
#endif // SIGNREQUSET_H
