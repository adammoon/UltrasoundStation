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
<<<<<<< HEAD
class QSignInfo;        //��¼���������Ϣ
class QQueue<class T>;
class QSignRequest:public QObject{
=======

//class QQueue<class T>;

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
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
public://typedefs
    //!��������ö��
    /*!
      ��ʾ��ǰ��¼�������Դ
    */
<<<<<<< HEAD
    typedef enum {
=======
    typedef enum REQ_SRC_TYPE{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        SIGNREQ_LOCAL, /*!< ��¼�������Ա���*/
        SIGNREQ_REMOTE /*!< ��¼������������*/
    }REQ_SRC_TYPE;
    //!����״̬
    /*!
      ��ʾ��ǰ���󱻴����״̬
    */
<<<<<<< HEAD
    typedef enum{
=======
    typedef enum REQ_STATUS{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        REQ_ACCEPT, /*!< ��¼���󱻽���*/
        REQ_REJECT, /*!< ��¼���󱻾ܾ�*/
        REQ_INQUE   /*!< ���������ڶ�����*/
    }REQ_STATUS;
    //!�������
    /*!
      ���໹�������ڱ�ʾ�û�ע��������˾����������
    */
<<<<<<< HEAD
    typedef enum{
=======
    typedef enum REQ_TYPE{
>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
        REQ_SIGNIN, /*!< �û���¼����*/
        REQ_LOGOUT  /*!< �û�ע������*/
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
    static QQueue<QSignRequest* > sign_req_queue;/*!< ��¼�������/
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
//    static QQueue<QSignRequest* > sign_req_queue;/*!< ��¼�������    *///�������Ӧ���з�������ά��
    REQ_SRC_TYPE requestSrcType;                 /*!< ������Դ       */
    REQ_STATUS reqStatus;                        /*!< ����״̬       */
    REQ_TYPE   reqType;                          /*!< ��¼����ע������*/
    QSignInfo* reqForSignInfor;                  /*!< ��¼��Ϣ       */
signals://�ź�
    void REQ_REACHED(QSignRequest* signReq);
public slots://�ۺ���
    void Req_Processed(QObject* obj,QSignRequest::REQ_STATUS processResult);//����¼��������ɺ�ᷢ���źŵ��òۺ���
};


>>>>>>> 04eb43e92c848075202b15886a61a5d65d6cc358
#endif // SIGNREQUSET_H
