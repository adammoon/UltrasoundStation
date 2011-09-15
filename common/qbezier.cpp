#include "qbezier.h"

#include <QPointF>

#include <cmath>

QBezier::QBezier(QPointF s,QPointF e)
{
    if(s.isNull() || e.isNull())
	return;
    startPoint = s;
    endPoint = e;
    ctrlCnt = 0;
    outCurve.append(s);
    outCurve.append(e);
}
//按照x升序排列
void QBezier::setCtrlPoint(QPointF c)
{
    if (c.isNull())
	return;
    if ( ctrlPoint.isEmpty() )
    {
	ctrlPoint.append(c);
	updateCurve();
	return;
    }
    QList<QPointF>::Iterator itor;
    for(itor = ctrlPoint.begin();itor != ctrlPoint.end();itor++){
	if(*itor.rx() > c.rx())
	{
	    break;
	}
    }
    ctrlPoint.insert(itor,c);
    updateCurve();
}
//
void QBezier::rmCtrlPoint(QPointF c)
{
    if (c.isNull() || ctrlPoint.isEmpty() )
	return;
    QList<QPointF>::Iterator itor;
    for(itor = ctrlPoint.begin();itor != ctrlPoint.end();itor++)
    {
	if(*itor == c)
	    break;
    }
    ctrlPoint.erase(itor);
    updateCurve();
}
//伯恩斯坦多项式
float QBezier::Boensitan(float t)
{

}
