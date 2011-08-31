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
class QQueue<class T>;
class QSignRequest:public QObject{
public://typedefs
    //!��������ö��
    /*!
      ��ʾ��ǰ��¼�������Դ
    */
    typedef enum {
        SIGNREQ_LOCAL, /*!< ��¼�������Ա���*/
        SIGNREQ_REMOTE /*!< ��¼������������*/
    }REQ_SRC_TYPE;
    //!����״̬
    /*!
      ��ʾ��ǰ���󱻴����״̬
    */
    typedef enum{
        REQ_ACCEPT, /*!< ��¼���󱻽���*/
        REQ_REJECT, /*!< ��¼���󱻾ܾ�*/
        REQ_INQUE   /*!< ���������ڶ�����*/
    }REQ_STATUS;
    //!�������
    /*!
      ���໹�������ڱ�ʾ�û�ע��������˾����������
    */
    typedef enum{
        REQ_SIGNIN, /*!< �û���¼����*/
        REQ_LOGOUT  /*!< �û�ע������*/
    }REQ_TYPE;
public://functions
    QSignRequest(QObject* parent = 0);
    QSignRequest(const QSignInfo* signInfor,
                 REQ_SRC_TYPE signReqTye = QSignRequest::SIGNRE_LOCAL,
                 REQ_TYPE signType = QSignRequest::REQ_SIGNIN,
                 QObject* parent =0);
    REQ_STATUS ProcessSignReq(void);
private:
    static QQueue<QSignRequest* > sign_req_queue;/*!< ��¼�������/
};

#endif // SIGNREQUSET_H
