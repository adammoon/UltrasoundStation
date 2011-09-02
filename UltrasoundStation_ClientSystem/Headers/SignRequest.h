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

class QSignInfo;        //登录请求基本信息
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
public://typedefs
    //!请求类型枚举
    /*!
      表示当前登录请求的来源
    */
    typedef enum REQ_SRC_TYPE{
        SIGNREQ_LOCAL, /*!< 登录请求来自本机*/
        SIGNREQ_REMOTE /*!< 登录请求来自网络*/
    }REQ_SRC_TYPE;
    //!请求状态
    /*!
      表示当前请求被处理的状态
    */
    typedef enum REQ_STATUS{
        REQ_ACCEPT, /*!< 登录请求被接受*/
        REQ_REJECT, /*!< 登录请求被拒绝*/
        REQ_INQUE   /*!< 请求正处于队列中*/
    }REQ_STATUS;
    //!请求类别
    /*!
      本类还可以用于表示用户注销请求，因此具有请求类别
    */
    typedef enum REQ_TYPE{
        REQ_SIGNIN, /*!< 用户登录请求*/
        REQ_LOGOUT  /*!< 用户注销请求*/
    }REQ_TYPE;
public://functions
    QSignRequest(QObject* parent = 0);
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
    REQ_SRC_TYPE requestSrcType;                 /*!< 请求来源       */
    REQ_STATUS reqStatus;                        /*!< 请求状态       */
    REQ_TYPE   reqType;                          /*!< 登录或者注销请求*/
    QSignInfo* reqForSignInfor;                  /*!< 登录信息       */
    friend class QLoadReqProcServer;
};


#endif // SIGNREQUSET_H
