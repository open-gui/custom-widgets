/***************************************************************************
 *   Copyright (C) 2008 by P. Sereno                                       *
 *   http://www.sereno-online.com                                          *
 *   http://www.qt4lab.org                                                 *
 *   http://www.qphoton.org                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QColor>
#include <QtGlobal>
#include <QtGui>
#include <QPolygon>
#include <math.h>
#include "qmeter.h"
#include <QPainter>


#define PI 3.1415926535


void QMeter::drawCrown(QPainter *painter)
{

    painter->save();
    QRectF rectangle(-47, -47, 94, 94);
    int startAngle = 30 * 16;
    int spanAngle = 390 * 16;
    QLinearGradient linearGrad(QPointF(-47, -47), QPointF(94, 94));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(0.3, QColor(60,60,60,250));
    QPen pen;
    QBrush brush=QBrush(linearGrad);
    pen.setBrush(brush);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawArc(rectangle, startAngle, spanAngle);
    painter->restore();
}


void QMeter::drawBackground(QPainter *painter)
{
	painter->setBrush(m_background);
	painter->drawEllipse(-45, -45, 90, 90);
}


void QMeter::drawTicks(QPainter *painter)
{
	painter->save();
    QPen pen=QPen(m_foreground);
    pen.setWidth(0);
    painter->setPen(pen);
	int nSteps=m_steps;
	painter->rotate(-m_startAngle) ;	
	double angleStep=(-m_endAngle+m_startAngle)/m_steps;
    for ( int i=0; i<=nSteps;i++ )
	{
//		if(i&0x0001)
         painter->drawLine(28,0,30,0 );
//		else
//         painter->drawLine(26,0,31,0 );
        painter->rotate( angleStep/1 );
	}		
	painter->restore();	

    pen.setWidth(0);
    painter->setPen(pen);
    double spanAngle=m_endAngle-m_startAngle;
    painter->drawArc(-28,-28,56,56, m_startAngle*16, spanAngle*16);
}


void QMeter::drawScale(QPainter *painter)
{
	painter->save();
	painter->setPen(m_foreground);
    double startRad=m_startAngle*PI/180.0;
    startRad+=PI/2;
    double deltaRad=(m_endAngle-m_startAngle)/(m_steps)*(PI/180);
	double sina,cosa;
	for ( int i=0; i<=m_steps; i++ ) 
	{
		sina=sin((double)(startRad+i*deltaRad));
		cosa=cos((double)(startRad+i*deltaRad));			
		double tmpVal=i*((m_maxValue-m_minValue)/m_steps);
		tmpVal+=m_minValue;
		QString str = QString( "%1" ).arg(tmpVal,0,'f',m_precision);
		QFontMetricsF fm( this->font() );
		double w=fm.size(Qt::TextSingleLine,str).width();
		double h=fm.size(Qt::TextSingleLine,str).height();
        int x=(int)((38*sina)-(w/2));
        int y=(int)((38*cosa)+(h/4));
		painter->drawText(x,y,str);	
	}		
	painter->restore();	
}


void QMeter::drawUnits(QPainter *painter)
{
	painter->setPen(m_foreground);
	painter->setBrush(m_foreground);
    painter->setPen(m_foreground);
    QRectF labelRect=QRectF(-15,-20,30,10);
    painter->drawText(labelRect,Qt::AlignCenter, m_units);
}


void QMeter::drawNumericValue(QPainter *painter)
{
    if(!enableNumericIndicator())
        return;
	QString str = QString( "%1" ).arg(m_value,0,'f',m_precision);
    QFont f=font();
    QFontMetricsF fm( f );
	QColor color;
	
	if(!m_thresholdFlag)
     color=Qt::yellow;
	else
	 color=Qt::red;

    QPen pen;
    pen.setWidth(0);
    painter->setPen(pen);
    QRectF labelRect=QRectF(-15,25,30,10);
    painter->drawRect(labelRect);

    painter->setPen(color);
    QFont font = painter->font();
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(labelRect,Qt::AlignCenter, str);

}


void QMeter::drawNeedle(QPainter *painter)
{
    // hat shadow
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(QColor(120,120,120,10));
//    painter->drawEllipse(-5, -6, 14, 14);
    // end hat shadow

	painter->save();

	painter->rotate(-90.0); 
	QPolygon pts;
    pts.setPoints( 3, -2,0,  2,0,  0,30 );
    QPolygon shadow;
    shadow.setPoints(3, -1,0, 1,0, 0,29);
	int degRotate=0;

    degRotate = (int)( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_value-m_minValue) );	 
	 
	painter->rotate( -degRotate );
    QRadialGradient haloGradient(0, 0, 20, 0, 0);
    haloGradient.setColorAt(0.0, QColor(255,120,120));
    haloGradient.setColorAt(1.0, QColor(200,20,20));
    QColor color=QColor(Qt::darkRed);
    color.setAlpha(90);
    painter->setPen(color);
	painter->setBrush(haloGradient);
	painter->drawConvexPolygon( pts );

    painter->setBrush(QColor(255,120,120));
    painter->drawConvexPolygon( shadow );

	painter->restore();
	
    // draw needle hat
    QLinearGradient linearGrad(QPointF(-7, -7), QPointF(14, 14));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(1, Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(linearGrad);
    painter->drawEllipse(-7, -7, 14, 14);

}


void QMeter::drawThresholdLine(QPainter *painter)
{
    if(!enableThreshold())
        return;

    painter->save();
    QPen pen;
    double thresholdAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_threshold-m_minValue) );
    pen.setWidth(3);

    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawArc(-25,-25,50,50,(int)m_startAngle*16,(int)(thresholdAngle-m_startAngle)*16);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawArc(-25,-25,50,50,(int)thresholdAngle*16,(int)(-thresholdAngle+m_endAngle)*16);
    painter->restore();

}


void QMeter::drawCoverGlass(QPainter *painter)
{
    painter->save();
    QLinearGradient linearGrad(QPointF(-15, -45), QPointF(90, 75));
    linearGrad.setColorAt(0, QColor(255,255,255,30));
    linearGrad.setColorAt(0.3, QColor(120,120,120,20));
    QBrush brush=QBrush(linearGrad);
    QPen pen;
    pen = QColor(0,0,0,0);
    pen.setBrush(brush);
    pen.setWidth(0);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(-45,-45,90,90);
    painter->restore();
}



void QMeter::drawLabel(QPainter *painter)
{
    painter->setPen(m_foreground);
    painter->setBrush(m_foreground);
    painter->setPen(m_foreground);
    QRectF labelRect=QRectF(-20,15,40,10);
    painter->drawText(labelRect,Qt::AlignCenter, m_label);
}


void QMeter::drawWarningWindow(QPainter *painter)
{
    if(enableWarningWindow())
    {

        QPen pen;

        double beginAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_beginWarningValue-m_minValue) );
        double endAngle =( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_endWarningValue-m_beginWarningValue-m_minValue) );

        pen.setWidth(2);

        pen.setColor(Qt::yellow);
        painter->setPen(pen);
        painter->drawArc(-25,-25,50,50,(int)beginAngle*16,(int)(endAngle-m_startAngle)*16);

    }
}

void QMeter::drawValidWindow(QPainter *painter)
{
    if(enableValidWindow())
    {

        QPen pen;

        double beginAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_beginValidValue-m_minValue) );
        double endAngle =( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_endValidValue-m_beginValidValue-m_minValue) );

        pen.setWidth(2);

        pen.setColor(Qt::green);
        painter->setPen(pen);
        painter->drawArc(-25,-25,50,50,(int)beginAngle*16,(int)(endAngle-m_startAngle)*16);

    }
}
