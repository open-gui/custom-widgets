/**********************************************************************************/
/*                                                                                */
/* Project Open-GUI                                                               */
/*                                                                                */
/* Copyright (c) by Paolo Sereno <paolo.sereno@open-gui.eu> All rights reserved.  */
/*                                                                                */
/* This library is free software; you can redistribute it and/or                  */
/* modify it under the terms of the GNU Lesser General Public                     */
/* License as published by the Free Software Foundation; either                   */
/* version 3.0 of the License, or (at your option) any later version.             */
/* This library is distributed in the hope that it will be useful,                */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of                 */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU               */
/* Lesser General Public License for more details.                                */
/* You should have received a copy of the GNU Lesser General Public               */
/* License along with this library.                                               */
/*                                                                                */
/**********************************************************************************/

#include <QColor>
#include <QtGlobal>
#include <QtGui>
#include <QPolygon>
#include <math.h>
#include "qcircularbar.h"
#include <QPainter>


#define PI 3.1415926535


void QCircularBar::drawCrown(QPainter *painter)
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
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawArc(rectangle, startAngle, spanAngle);
    painter->restore();

}


void QCircularBar::drawCoverGlass(QPainter *painter)
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


void QCircularBar::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setBrush(m_background);
    painter->drawEllipse(-45, -45, 90, 90);
    painter->restore();
}


void QCircularBar::drawTicks(QPainter *painter)
{
    painter->save();
    QPen pen=QPen(background());
    pen.setWidth(1);
    painter->setPen(pen);
    int nSteps=m_steps;
    painter->rotate(-m_startAngle) ;
    double angleStep=(-m_endAngle+m_startAngle)/m_steps;
    for ( int i=0; i<=nSteps;i++ )
    {        
        painter->drawLine(30,0,40,0 );
        painter->rotate( angleStep );
    }
    painter->restore();

    painter->save();
    pen.setWidth(1);
    painter->setPen(pen);
    double spanAngle=m_endAngle-m_startAngle;
    painter->drawArc(-28,-28,56,56, m_startAngle*16, spanAngle*16);
    painter->restore();

}

void QCircularBar::drawThresholdLine(QPainter *painter)
{
    QPen pen;

    double thresholdAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_threshold-m_minValue) );
    pen.setWidth(2);

//    pen.setColor(Qt::green);
//    painter->setPen(pen);
//    painter->drawArc(-40,-40,80,80,(int)m_startAngle*16,(int)(thresholdAngle-m_startAngle)*16);

    if(isEnabled())
        pen.setColor(Qt::red);
    else
        pen.setColor(Qt::gray);
    painter->setPen(pen);
    painter->drawArc(-40,-40,80,80,(int)thresholdAngle*16,(int)(-thresholdAngle+m_endAngle)*16);

}

void QCircularBar::drawCircularBar(QPainter *painter)
{
    painter->save();
    double valueAngle = ( m_startAngle+((m_endAngle-m_startAngle)/(m_maxValue-m_minValue))*(m_value-m_minValue));
    QRadialGradient haloGradientw(0, 0, 49, 0, 0);
    QColor color;

    if(isEnabled())
        color = foreground();
    else
        color=Qt::gray;

    haloGradientw.setColorAt(0.7, color);
    haloGradientw.setColorAt(0.9, Qt::black);
    QBrush brush=QBrush(haloGradientw);
    QPen pen = QPen(brush,barSize());
    painter->setPen(pen);
    painter->drawArc(-35,-35,70,70,(int)(m_startAngle*16),(int)((valueAngle-m_startAngle)*16));

    painter->restore();

    if(thresholdEnabled())
    {
//        if(value()>threshold())
//        {
//            painter->save();
//            double thresholdAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_threshold-m_minValue) );
//            QRadialGradient haloGradientT(0, 0, 49, 0, 0);
//            haloGradientT.setColorAt(0.7, Qt::red);
//            haloGradientT.setColorAt(0.9, Qt::black);
//            brush=QBrush(haloGradientT);
//            pen = QPen(brush,4);
//            painter->setPen(pen);
//            painter->drawArc(-35,-35,70,70,(int)(thresholdAngle*16),(int)((valueAngle-thresholdAngle)*16));
//            //painter->drawArc(-35,-35,70,70,(int)(m_startAngle*16),(int)((valueAngle-m_startAngle)*16));
//            painter->restore();
//        }
    }

}


void QCircularBar::drawLabel(QPainter *painter)
{
    painter->save();
/*    QFont font;
    font.setPixelSize(10);
    font.setBold(true);
    setFont(font)*/;
    if(isEnabled())
    {
        painter->setBrush(m_foreground);
        painter->setPen(m_foreground);
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->setPen(Qt::gray);
    }
    QRectF labelRect=QRectF(-15,20,30,20);
    painter->drawText(labelRect,Qt::AlignCenter, m_label);
    painter->restore();
}

