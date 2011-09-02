#include "Headers/signinwidget.h"
#include "Headers/SignRequest.h"
#include "Headers/LoadReqProcessServer.h"

#include <QPushButton>
#include <QlineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

QsignInWidget::QsignInWidget(QWidget *parent) :
    QWidget(parent)
{
    roleList<<"doctor"<<"visitor"<<"admin";
    setSubWidget();
    //��ť���źŴ���
    connect(btn_LoadIn,SIGNAL(clicked()),this,SLOT(loadIn()));
    setLayout(mainLayout);
}
//�ؼ������ڲ���
void QsignInWidget::setSubWidget(){
    //�������ֱ�ǩ
    label_UserName = new QLabel("User_Name:",this);
    label_PWD = new QLabel("PassWord:",this);
    label_Role = new QLabel("Load_Role:",this);
    //�����ı������Ͽ�
    textUserName = new QLineEdit("visitor",this);
    textPassWord = new QLineEdit("",this);
    comboRole = new QComboBox(this);
    //��ť�ؼ�����
    btn_LoadIn = new QPushButton("&loadIn...",this);
    btn_ResetInfo = new QPushButton("&reset",this);
    btn_Cancel = new QPushButton("&cancel",this);
    //��ʼ����Ͽ��е�����
    comboRole->addItems(roleList);
    //���ñ�ǩ���֮���buddy��ϵ
    label_UserName->setBuddy(textUserName);
    label_PWD->setBuddy(textPassWord);
    label_Role->setBuddy(comboRole);
    //������Ҫ����������ö��뷽ʽ�Ĵ���
    //����
    mainLayout = new QVBoxLayout(this);
    layout_lineOne = new QHBoxLayout(this);
    layout_lineTwo = new QHBoxLayout(this);
    layout_lineThree = new QHBoxLayout(this);
    layout_lineFour = new QHBoxLayout(this);
    layout_lineOne->addWidget(label_UserName);
    layout_lineOne->addWidget(textUserName);
    layout_lineTwo->addWidget(label_Role);
    layout_lineTwo->addWidget(comboRole);
    layout_lineThree->addWidget(label_PWD);
    layout_lineThree->addWidget(textPassWord);
    layout_lineFour->addWidget(btn_LoadIn);
    layout_lineFour->addWidget(btn_ResetInfo);
    layout_lineFour->addWidget(btn_Cancel);
    mainLayout->addLayout(layout_lineOne);
    mainLayout->addLayout(layout_lineTwo);
    mainLayout->addLayout(layout_lineThree);
    mainLayout->addLayout(layout_lineFour);
}
//��½��ť����
void QsignInWidget::loadIn(){
    QString userName,userPassWd;
    QSignInfo::LOG_ROLE role;
    userName = textUserName->text();
    userPassWd = textPassWord->text();
    QString roleStr = comboRole->currentText();
    if(roleList[0] == roleStr)role = QSignInfo::ROLE_DOCTOR;
    if(roleList[1] == roleStr)role = QSignInfo::ROLE_VISITOR;
    if(roleList[2] == roleStr)role = QSignInfo::ROLE_ADMIN;
    QSignRequest* currentREQ = new QSignRequest(userName,
                                                userPassWd,
                                                role);
    while(currentREQ->ProcessSignReq() != QSignRequest::REQ_ACCEPT);//�ȴ�
    return;
}
