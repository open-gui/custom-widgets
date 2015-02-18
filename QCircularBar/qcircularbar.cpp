#include "qcircularbar.h"


#include <QtGlobal>
#include <QtGui>
#include <QPainter>
#include <QFont>

/*!
  \mainpage QCircularBar - A custom widget plugin for Qt 4.x

  The QMeter widget is a custom widget plugin for Qt Designer.\n
  It requires the Qt GUI library from Troll Tech AS.

  \image html qmeter.jpg

  \section homepage Project page
  The QMeter page is hosted at
    <a href="http://www.sereno-online.com/qt4lab/qmeter">sereno-online.com</a>

  \section license License
    QMeter is distributed under the terms of the \ref GPL v2.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation version 2 of the license
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the
    Free Software Foundation, Inc.,
    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

  \section downloads Downloads
   You can download QMeter at <a href="http://www.qt-apps.org">Qt-apps.org</a>.

  \section credits Credits:
  \par Author:
    P. Sereno

*/


QCircularBar::QCircularBar(QWidget *parent)
    : QWidget(parent)
{

   m_lcd = new QLCDNumber(this);
   setPrecision(0);
   setSteps(20);
   setBarSize(5);
   setMinimumSize(QSize(80,80));
   setStartAngle(225);
   setEndAngle(-45);
   setForeground(QColor(0, 166, 8));
   setBackground(Qt::black);
   setThresholdEnabled(false);
   setNumericIndicatorEnabled(true);
   int r,g,b;
   r=foreground().red();
   g=foreground().green();
   b=foreground().blue();
   QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
   m_lcd->setStyleSheet(style);
   m_lcd->setSegmentStyle(QLCDNumber::Flat);
   m_autodigits=false;
   setMinValue(0);
   setMaxValue(100);
   setDigitCount(5);
   setValue(0);
   setLabel("Label");
   setThreshold(80);
   setCircularBarEnabled(true);
   setCoverGlassEnabled(true);
   setEnabled(true);
}



QCircularBar::~QCircularBar()
{
    delete m_lcd;
}


int QCircularBar::digits(int val)
{
    int digits = 0;
       if (val <= 0) digits = 1; // remove this line if '-' counts as a digit
       while (val) {
           val /= 10;
           digits++;
       }
       return digits;
}

void QCircularBar::setBarSize(int barSize)
{
    m_barSize=barSize;
    update();
}

void QCircularBar::setValue(double value)
{

    if(!isEnabled())
        return;

    if(value>m_maxValue)
    {
        m_value=m_maxValue;
        emit errorSignal(OutOfRange);
    }
    else
        if(value<m_minValue)
        {
            m_value=m_minValue;
            emit errorSignal(OutOfRange);
        }
        else
        {
            m_value=value;
            if(m_autodigits)
                m_lcd->setDigitCount(digits(value));
            if(m_lcd)
            {
                //QString val = QString( "%1" ).arg(m_value,0,'f',m_precision);
                m_lcd->display(m_value);
            }
        }

    if(thresholdEnabled())
    {
        thresholdManager();

        if(value>=threshold())
        {
            QString style=QString("background-color: transparent; color: rgb(200,0,0);");
            m_lcd->setStyleSheet(style);

        }
        else
        {
            int r,g,b;
            r=foreground().red();
            g=foreground().green();
            b=foreground().blue();
            QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
            m_lcd->setStyleSheet(style);
        }

    }
    else
    {
        int r,g,b;
        r=foreground().red();
        g=foreground().green();
        b=foreground().blue();
        QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
        m_lcd->setStyleSheet(style);
    }

    update();

}


int QCircularBar::digitCount() const
{
    if(m_lcd)
        return m_lcd->digitCount();
    else
        return 0;
}

void QCircularBar::setValue(int value)
{
   setValue((double)value);
   update();
}

void QCircularBar::setMinValue(double value)
{
   m_minValue=value;
   update();
}

void QCircularBar::setMinValue(int value)
{
  setMinValue((double)value);
}


void QCircularBar::setMaxValue(double value)
{
    if(value > m_minValue)
    {
        m_maxValue=value;
        update();
    }
    else
        emit errorSignal(MaxValueError);
}


void QCircularBar::setMaxValue(int value)
{
  setMaxValue((double)value);
}


void QCircularBar::setThreshold(double value)
{
    if(value > m_minValue && value < m_maxValue)
    {
        m_threshold=value;
        m_thresholdEnabled=true;
        update();
    }
    else
        emit errorSignal(ThresholdError);
}


void QCircularBar::setThreshold(int value)
{
  setThreshold((double)value);
}



void QCircularBar::setPrecision(int precision)
{
   m_precision=precision;
   update();
}


void QCircularBar::setLabel(QString label)
{
    m_label=label;
    update();
}


void QCircularBar::setDigitCount(int n_digits)
{
    if(n_digits>0)
    {
        if (m_lcd)
            m_lcd->setDigitCount(n_digits);
    }
    else
            m_autodigits=true;
}


void QCircularBar::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_lcd->setGeometry(width()/2-width()/4,height()/2-height()/6,width()/2,height()/3);
}

void QCircularBar::changeEvent(QEvent *event)
{
    if(!isEnabled())
    {
        QString style=QString("background-color: transparent; color: rgb(200,200,200);");
        m_lcd->setStyleSheet(style);
        update();
    }
    else
        setValue(value());
}

void QCircularBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2,side, side);
    painter.setWindow(-50, -50, 100, 100);

    drawBackground(&painter);
    if(circularBarEnabled())
        drawCircularBar(&painter);

    drawTicks(&painter);
    if(coverGlassEnabled())
        drawCoverGlass(&painter);
    drawLabel(&painter);
    drawCrown(&painter);
    if(thresholdEnabled())
        drawThresholdLine(&painter);

}



void QCircularBar::setCoverGlassEnabled(bool enable)
{
    m_coverGlassEnabled=enable;
    update();
}

void QCircularBar::setSteps(int nSteps)
{
    if(nSteps>1)
    {
        m_steps=nSteps;
        update();
    }
    else
        nSteps=1;
}

void QCircularBar::setStartAngle(int value)
{
    m_startAngle=value;
    update();
}

void QCircularBar::setEndAngle(int value)
{
    m_endAngle=value;
    update();
}


void QCircularBar::setForeground(QColor newForeColor)
{
    m_foreground=newForeColor;


    int r,g,b;
    r=foreground().red();
    g=foreground().green();
    b=foreground().blue();
    QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    m_lcd->setStyleSheet(style);


    update();
}

void QCircularBar::setBackground(QColor newBackColor)
{
    m_background=newBackColor;


    int r,g,b;
    r=foreground().red();
    g=foreground().green();
    b=foreground().blue();
    QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    m_lcd->setStyleSheet(style);

    update();
}


void QCircularBar::thresholdManager()
{
    // m_thresholdFlag is used to avoid signals at each setValue
    if(m_value > m_threshold /*&& !m_thresholdFlag*/)
    {
//     m_thresholdFlag=true;
     emit thresholdAlarm(true);
    }
    else
     if(m_value < m_threshold /*&& m_thresholdFlag*/)
     {
//      m_thresholdFlag=false;
      emit thresholdAlarm(false);
     }
}


void QCircularBar::setThresholdEnabled(bool enable)
{
  m_thresholdEnabled=enable;
  update();
}

void QCircularBar::setNumericIndicatorEnabled(bool enable)
{
  m_numericIndicatorEnabled=enable;
  m_lcd->setVisible(enable);
  update();
}


void QCircularBar::setCircularBarEnabled(bool enable)
{
    m_circularBarEnabled=enable;
    update();
}

