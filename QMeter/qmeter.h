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

#ifndef QMETER_H
#define QMETER_H

 
#include <Qt>
#include <QWidget>
//#include <QtDesigner/QDesignerExportWidget>


#include <QPropertyAnimation>

class QColor;

/*!
  \brief QMeter is a custom widget plugin to display values. It consists of a scale and a needle
  to show the value within a lower and an upper limit.
  The angle associated to the limits in the widget scale can be modified by appropriate slots.
  A threshold limit can be enabled to handle alarm signals coherent with the input value. 
  Once installed in Qt designer, right click on the widget and select HelpQMeter...,
  the associated help dialog will be displayed to show more details about the widget. 
  \image html qmeter.jpg 
  
*/
class QMeter : public QWidget
{
 Q_OBJECT
	Q_ENUMS(errorCode);
	Q_PROPERTY(double value READ value WRITE setValue);
	Q_PROPERTY(double minValue READ minValue WRITE setMinValue);
	Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue);
	Q_PROPERTY(double threshold READ threshold WRITE setThreshold);
	Q_PROPERTY(int precision READ precision WRITE setPrecision);
	Q_PROPERTY(QString units READ units WRITE setUnits);
    Q_PROPERTY(QString label READ label WRITE setLabel);
    Q_PROPERTY(int steps READ steps WRITE setSteps);
	Q_PROPERTY(double startAngle READ startAngle WRITE setStartAngle);
	Q_PROPERTY(double endAngle READ endAngle WRITE setEndAngle);	
	Q_PROPERTY(QColor foreground READ foreground WRITE setForeground);
	Q_PROPERTY(QColor background READ background WRITE setBackground);
	Q_PROPERTY(bool enableThreshold READ enableThreshold WRITE setThresholdEnabled);
    Q_PROPERTY(double beginValidValue READ beginValidValue WRITE setBeginValidValue);
    Q_PROPERTY(double endValidValue READ endValidValue WRITE setEndValidValue);
    Q_PROPERTY(bool enableValidWindow READ enableValidWindow WRITE setEnableValidWindow);
    Q_PROPERTY(double beginWarningValue READ beginWarningValue WRITE setBeginWarningValue);
    Q_PROPERTY(double endWarningValue READ endWarningValue WRITE setEndWarningValue);
    Q_PROPERTY(bool enableWarningWindow READ enableWarningWindow WRITE setEnableWarningWindow);
	Q_PROPERTY(bool enableNumericIndicator READ enableNumericIndicator WRITE setNumericIndicatorEnabled);
	
public: 
/*!
   \brief ErrorCode : This enum represents the code returned by the error signal
*/
    enum ErrorCode {MaxValueError=1,MinValueError,ThresholdError,TargetError,PrecisionError,ColorError,UnitsEmpty,OutOfRange};

/*!
  \brief Constructor
  \param parent Parent Widget
*/    
    QMeter(QWidget *parent = 0);
/*!
  \return The current displayed value
*/    
    double value() const { return m_value; }

/*!
  \return The minimum widget scale value 
*/           
    double minValue() const { return m_minValue; }

/*!
  \return The maximum widget scale value 
*/               
    double maxValue() const { return m_maxValue; }

/*!
  \return The threshold 
*/              
    double threshold() const { return m_threshold; }

/*!
  \return The beginValidValue
*/
    double beginValidValue() const { return m_beginValidValue; }

/*!
  \return The endValidValue
*/
    double endValidValue() const { return m_endValidValue; }


    /*!
      \return The beginWarningValue
    */
        double beginWarningValue() const { return m_beginWarningValue; }

    /*!
      \return The endWarningValue
    */
        double endWarningValue() const { return m_endWarningValue; }


/*!
  \return The number of decimals displayed in the widget scale 
*/               
    int precision() const { return m_precision; }

/*!
  \return The measurement unit string 
*/               
	QString units()const { return m_units; }

/*!
  \return The Label
*/
    QString label()const { return m_label; }
/*!
  \return The number of steps in the widget scale 
*/           	
	int steps() const { return m_steps; }

/*!
  \return The starting angle associated to the minimum value for the widget scale 
*/           	
	double startAngle() const { return m_startAngle; }

/*!
  \return The end angle associated to the minimum value for the widget scale 
*/           		
    double endAngle() const { return m_endAngle; }

/*!
  \return The foreground color used for the widget 
*/           	    
    QColor foreground() const { return m_foreground; }

/*!
  \return The background color used for the widget 
*/           	        
    QColor background() const { return m_background; }

/*!
  \return The enableThreshold flag 
*/           	        
    bool enableThreshold() const { return m_thresholdEnabled; }

/*!
      \return The enableValidWindow
*/
bool enableValidWindow() const { return m_enableValidWindow; }

/*!
      \return The enableWarningWindow
*/
bool enableWarningWindow() const { return m_enableWarningWindow; }


/*!
  \return The enableNumericIndicator flag 
*/
bool enableNumericIndicator() const { return m_numericIndicatorEnabled; }


signals:

/*!
  \signals This signal is emitted to report an error condition.
*/  
    void errorSignal(int);
/*!
  \signals This signal reports a value true when the input value exceeds for the
           first time the threshould limit and reports a value false when the input
           value decreases under the threshold limit. That means errorSignal is emitted
           only one time (with true argument) when the input passes from a value < threshold to a value > threshold
           and only one time (with false argument) when the input decreases under the
           threshold limit.
*/           	            
    void thresholdAlarm(bool);

          	            
    
public slots:
/*!
  \slots This slot is used to set QMeter value
*/ 
	void setValue(double);
/*!
  \slots This is an overloaded member function, provided for convenience. 
*/	
	void setValue(int);
/*!
  \slots This slot is used to set the lower limit of the QMeter scale.
*/	
	void setMinValue(double);
/*!
  \slots This is an overloaded member function, provided for convenience. 
*/	
	void setMinValue(int);
/*!
  \slots This slot is used to set the upper limit of the QMeter scale.
*/	
	void setMaxValue(double);
/*!
  \slots This is an overloaded member function, provided for convenience. 
*/	
	void setMaxValue(int);	
/*!
  \slots This slot is used to set the threshold limit. See
  \ref thresholdAlarm for more info.
*/	
	void setThreshold(double);
/*!
  \slots This is an overloaded member function, provided for convenience. 
*/	
	void setThreshold(int);
/*!
  \slots This slot is used to set the number of decimal digits for the QMeter scale
  and QMeter numerical value.
*/			
    void setPrecision(int);
/*!
  \slots This slot is used to set the measurement units displyed in the QMeter widget.
*/    	
	void setUnits(QString);

 /*!
  \slots This slot is used to set the label in the QMeter widget.
 */
    void setLabel(QString);

/*!
  \slots This slot is used to set the number of spets in the QMeter scale.
*/	
	void setSteps(int);
/*!
  \slots This represents the starting angle correspondign to the lower limit for the QMeter scale.
  Positive and negative angles can be used.
*/	
	void setStartAngle(double);
/*!
  \slots This represents the end angle corresponding to the upper limit for the QMeter scale.
  Positive and negative angles can be used.
*/	
	void setEndAngle(double);
/*!
  \slots This slot is used to set the widget foreground color.
*/	
	void setForeground(QColor);
/*!
  \slots This slot is used to set the widget background color.
*/	
	void setBackground(QColor);
/*!
  \slots This slot allows to enable the threshold management. See
  \ref thresholdAlarm for more info.
*/	
    void setThresholdEnabled(bool);
/*!
  \slots Thi slot allows to enable the numerical value display
*/    
    void setNumericIndicatorEnabled(bool);


    void setValueWithSpringEffect(int value);


    void setBeginValidValue(double);
    void setEndValidValue(double);
    void setEnableValidWindow(bool);

    void setBeginWarningValue(double);
    void setEndWarningValue(double);
    void setEnableWarningWindow(bool);

protected:
    double m_value;
    double m_maxValue, m_minValue;
    int m_precision;
    void thresholdManager();
    void paintEvent(QPaintEvent *event);
            
    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawTicks(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawUnits(QPainter *painter);
    void drawNeedle(QPainter *painter);
    void drawThresholdLine(QPainter *painter);
    void drawNumericValue(QPainter *painter);
    void drawCoverGlass(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawValidWindow(QPainter *painter);
    void drawWarningWindow(QPainter *painter);
    
	QString m_units;
    QString m_label;
	int m_steps;
	double m_startAngle,m_endAngle;
	double m_threshold;
    bool m_thresholdFlag;
    bool m_enableValidWindow;
    double m_beginValidValue, m_endValidValue;    
    bool m_enableWarningWindow;
    double m_beginWarningValue, m_endWarningValue;
	bool m_thresholdEnabled;
	bool m_numericIndicatorEnabled;
	
	QColor m_foreground;
	QColor m_background;

    QPropertyAnimation m_valAnimation;

};

#endif
