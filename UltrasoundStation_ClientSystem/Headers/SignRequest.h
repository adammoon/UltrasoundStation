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
class QQueue<class T>;
class QSignRequest:public QObject{
public://typedefs
    //!请求类型枚举
    /*!
      表示当前登录请求的来源
    */
    typedef enum {
        SIGNREQ_LOCAL, /*!< 登录请求来自本机*/
        SIGNREQ_REMOTE /*!< 登录请求来自网络*/
    }REQ_SRC_TYPE;
    //!请求状态
    /*!
      表示当前请求被处理的状态
    */
    typedef enum{
        REQ_ACCEPT, /*!< 登录请求被接受*/
        REQ_REJECT, /*!< 登录请求被拒绝*/
        REQ_INQUE   /*!< 请求正处于队列中*/
    }REQ_STATUS;
    //!请求类别
    /*!
      本类还可以用于表示用户注销请求，因此具有请求类别
    */
    typedef enum{
        REQ_SIGNIN, /*!< 用户登录请求*/
        REQ_LOGOUT  /*!< 用户注销请求*/
    }REQ_TYPE;
public://functions
    QSignRequest(QObject* parent = 0);
    QSignRequest(const QSignInfo* signInfor,
                 REQ_SRC_TYPE signReqTye = QSignRequest::SIGNRE_LOCAL,
                 REQ_TYPE signType = QSignRequest::REQ_SIGNIN,
                 QObject* parent =0);
    REQ_STATUS ProcessSignReq(void);
private:
    static QQueue<QSignRequest* > sign_req_queue;/*!< 登录请求队列/
};

#endif // SIGNREQUSET_H
