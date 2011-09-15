#ifndef QBEZIER_H
#define QBEZIER_H

#include <QList>
class QPointF;
/*!
  \class QBezier
  \brief ����������������
  \details �������е������յ㣬�û�ѡ�õĿ��Ƶ�
  ʹ�ñ��������������㷨�������ߵĵ�����
  \author flyfish
  \date 2011-09-15
  */
class QBezier
{
public:
    typedef QList<QPointF> curve;
    /*! ���캯��

      */
    QBezier(QPointF s,QPointF e);
    /*! ���ÿ��Ƶ�ĺ���
      \param ���õĿ��Ƶ�
      \return
      \sa rmCtrlPoint()
      */
    void setCtrlPoint(QPointF c);
    /*! ɾ�����Ƶ�
      \param Ҫɾ���Ŀ��Ƶ�
      \return
      \sa setCtrlPoint()
      */
    void rmCtrlPoint(QPointF c);
    /*! ��õ�ǰ�����µ����ߵ�����
      \param void
      \return ���������ߵ�����
    */
    inline curve getCurve(void)const{ return outCurve;}
private:
    float Boensitan(float t);
    /*! ��������
      \param void
      \return ���º������
      */
    void updateCurve(void);
private:
    QList<QPointF> ctrlPoint;	/*!< ���Ƶ�*/
    QPointF startPoint,endPoint;	    /*!< ��ʼ�ͽ�����*/
    float deta;		/*!< t�ļ��ֵ */
    quint32 ctrlCnt;	/*!< ���Ƶ���� */
    curve outCurve;	/*!< ���ɵ����� */
};

#endif // QBEZIER_H
