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

#include "qmeter.h"
#include "qmeterplugin.h"
#include "qmetertaskmenu.h"

#include <QtDesigner>
#include <QtPlugin>

QMeterPlugin::QMeterPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QMeterPlugin::initialize(QDesignerFormEditorInterface *formEditor)
{
    if (initialized)
        return;

    QExtensionManager *manager = formEditor->extensionManager();
    Q_ASSERT(manager != 0);

    manager->registerExtensions(new QMeterTaskMenuFactory(manager),
                                Q_TYPEID(QDesignerTaskMenuExtension));



    initialized = true;
}

bool QMeterPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QMeterPlugin::createWidget(QWidget *parent)
{
    return new QMeter(parent);
}

QString QMeterPlugin::name() const
{
    return "QMeter";
}

QString QMeterPlugin::group() const
{
    return "Lab Widgets";
}

QIcon QMeterPlugin::icon() const
{
    return QIcon(":qmeter.png");
}

QString QMeterPlugin::toolTip() const
{
    return "";
}

QString QMeterPlugin::whatsThis() const
{
    return "";
}

bool QMeterPlugin::isContainer() const
{
    return false;
}

QString QMeterPlugin::domXml() const
{
    return "<widget class=\"QMeter\" name=\"qMeter\">\n"
           " <property name=\"geometry\">\n"
           "  <rect>\n"
           "   <x>0</x>\n"
           "   <y>0</y>\n"
           "   <width>100</width>\n"
           "   <height>100</height>\n"
           "  </rect>\n"
           " </property>\n"
           " <property name=\"toolTip\" >\n"
           "  <string>Meter</string>\n"
           " </property>\n"
           " <property name=\"whatsThis\" >\n"
           "  <string>Meter widget</string>\n"
           " </property>\n"                         
           " <property name=\"minValue\" >\n"
           "  <double>0.0</double>\n"
           " </property>\n"                             
           " <property name=\"maxValue\" >\n"
           "  <double>100.0</double>\n"
           " </property>\n" 
           " <property name=\"threshold\" >\n"
           "  <double>100.0</double>\n"
           " </property>\n"                        
           " <property name=\"value\" >\n"
           "  <double>0.0</double>\n"
           " </property>\n"  
           " <property name=\"units\" >\n"
           "  <string>Km/h</string>\n"
           " </property>\n"     
           " <property name=\"startAngle\" >\n"
           "  <double>210.0</double>\n"
           " </property>\n" 
           " <property name=\"endAngle\" >\n"
           "  <double>-30.0</double>\n"
           " </property>\n"  
           " <property name=\"enableThreshold\" >\n"
           "  <bool>true</bool>\n"
           " </property>\n" 
           " <property name=\"enableNumericIndicator\" >\n"
           "  <bool>true</bool>\n"
           " </property>\n"                                           
           "</widget>\n";
}

QString QMeterPlugin::includeFile() const
{
    return "qmeter.h";
}

//Q_EXPORT_PLUGIN2(customwidgetplugin, QMeterPlugin)
