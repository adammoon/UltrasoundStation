/*!
*@file signinwidget.h
*@brief �����û���¼
*@details �û���¼����������Ա�����Ҳ��������Զ�̷���
*@author fiyfish
*@version 0.0.1
*@date 2011-8-27
*/
#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
class QLabel;
class QLineEdit;
class QComboBox;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class QSignRequest;
class QLoadReqProcServer;
//!QsignInWidget
class QsignInWidget : public QWidget
{
    Q_OBJECT
public:
    typedef enum{
        STATUS_ROLE_DOCTOR,     /**< doctor loadded*/
        STATUS_ROLE_VISITOR,    /**< visitor loadded*/
        STATUS_ROLE_ADMIN       /**< administrator loaded*/
    }ROLE;
    explicit QsignInWidget(QWidget *parent = 0);
private://members
    QLabel *label_UserName,*label_PWD,*label_Role;
    QLineEdit *textUserName,*textPassWord;
    QComboBox *comboRole;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout_lineOne,*layout_lineTwo,*layout_lineThree,*layout_lineFour;
    QPushButton *btn_LoadIn,*btn_ResetInfo,*btn_Cancel;
private://functions
    void setSubWidget(void);
    QStringList roleList;
signals:

public slots:
    void loadIn();
    void resetContext();
};
#endif // SIGNINWIDGET_H
