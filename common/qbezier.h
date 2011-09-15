#ifndef QBEZIER_H
#define QBEZIER_H

#include <QList>
class QPointF;
/*!
  \class QBezier
  \brief 贝塞尔曲线生成类
  \details 根据现有的起点和终点，用户选用的控制点
  使用贝塞尔曲线生成算法生成曲线的点序列
  \author flyfish
  \date 2011-09-15
  */
class QBezier
{
public:
    typedef QList<QPointF> curve;
    /*! 构造函数

      */
    QBezier(QPointF s,QPointF e);
    /*! 设置控制点的函数
      \param 设置的控制点
      \return
      \sa rmCtrlPoint()
      */
    void setCtrlPoint(QPointF c);
    /*! 删除控制点
      \param 要删除的控制点
      \return
      \sa setCtrlPoint()
      */
    void rmCtrlPoint(QPointF c);
    /*! 获得当前参数下的曲线点序列
      \param void
      \return 贝塞尔曲线点序列
    */
    inline curve getCurve(void)const{ return outCurve;}
private:
    float Boensitan(float t);
    /*! 更新曲线
      \param void
      \return 更新后的曲线
      */
    void updateCurve(void);
private:
    QList<QPointF> ctrlPoint;	/*!< 控制点*/
    QPointF startPoint,endPoint;	    /*!< 起始和结束点*/
    float deta;		/*!< t的间隔值 */
    quint32 ctrlCnt;	/*!< 控制点个数 */
    curve outCurve;	/*!< 生成的曲线 */
};

#endif // QBEZIER_H
