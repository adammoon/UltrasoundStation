/*!
*@file SignRequest.h
*@brief ��¼�����װ
*@details ʵ�ֵ�¼�������
*@author flyfish
*@version 0.0.1
*@date 2011-8-31
*/
#ifndef SIGNREQUSET_H
#define SIGNREQUSET_H
#include <QObject>

class QSignInfo;        //��¼���������Ϣ
//!QSignInfo ��¼��¼������Ϣ
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
    //!��������ö��
    /*!
      ��ʾ��ǰ��¼�������Դ
    */
    typedef enum REQ_SRC_TYPE{
        SIGNREQ_LOCAL, /*!< ��¼�������Ա���*/
        SIGNREQ_REMOTE /*!< ��¼������������*/
    }REQ_SRC_TYPE;
    //!����״̬
    /*!
      ��ʾ��ǰ���󱻴����״̬
    */
    typedef enum REQ_STATUS{
        REQ_ACCEPT, /*!< ��¼���󱻽���*/
        REQ_REJECT, /*!< ��¼���󱻾ܾ�*/
        REQ_INQUE   /*!< ���������ڶ�����*/
    }REQ_STATUS;
    //!�������
    /*!
      ���໹�������ڱ�ʾ�û�ע��������˾����������
    */
    typedef enum REQ_TYPE{
        REQ_SIGNIN, /*!< �û���¼����*/
        REQ_LOGOUT  /*!< �û�ע������*/
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
    REQ_SRC_TYPE requestSrcType;                 /*!< ������Դ       */
    REQ_STATUS reqStatus;                        /*!< ����״̬       */
    REQ_TYPE   reqType;                          /*!< ��¼����ע������*/
    QSignInfo* reqForSignInfor;                  /*!< ��¼��Ϣ       */
    friend class QLoadReqProcServer;
};


#endif // SIGNREQUSET_H
