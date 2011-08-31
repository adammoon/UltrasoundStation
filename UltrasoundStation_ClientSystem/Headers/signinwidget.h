/*!
*@file signinwidget.h
*@brief 定义用户登录
*@details 用户登录请求可以来自本机，也可以来自远程访问
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
//!QsignInWidget
class QsignInWidget : public QWidget
{
    Q_OBJECT
public:
    typedef enum{
        STATUS_ROLE_DOCTOR,     /**< doctor loadded*/
        STATUS_ROLE_VISITOR,    /**< visitor loadded*/
        STATUS_ROLE_ADMIN       /**< administrator loaded*/
    }SING_STATUS;
    explicit QsignInWidget(QWidget *parent = 0);
private://members
    QLabel *label_UserName,*label_PWD,*label_Role;
    QLineEdit *textUserName,*textPassWord;
    QComboBox *comboRole;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout_lineOne,*layout_lineTwo,*layout_lineThree;
private://functions
    void setSubWidget(void);
signals:

public slots:

};

#endif // SIGNINWIDGET_H
