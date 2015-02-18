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

#include "qcircularbar.h"
#include "qcircularbarplugin.h"
#include "qcircularbartaskmenu.h"

#include <QtDesigner>
#include <QtPlugin>

QCirularBarPlugin::QCirularBarPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QCirularBarPlugin::initialize(QDesignerFormEditorInterface *formEditor)
{
    if (initialized)
        return;

    QExtensionManager *manager = formEditor->extensionManager();
    Q_ASSERT(manager != 0);

    manager->registerExtensions(new QCircularBarTaskMenuFactory(manager),
                                Q_TYPEID(QDesignerTaskMenuExtension));



    initialized = true;
}

bool QCirularBarPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QCirularBarPlugin::createWidget(QWidget *parent)
{
    return new QCircularBar(parent);
}

QString QCirularBarPlugin::name() const
{
    return "QCircularBar";
}

QString QCirularBarPlugin::group() const
{
    return "Lab Widgets";
}

QIcon QCirularBarPlugin::icon() const
{
    return QIcon(":qcircularbar.png");
}

QString QCirularBarPlugin::toolTip() const
{
    return "";
}

QString QCirularBarPlugin::whatsThis() const
{
    return "";
}

bool QCirularBarPlugin::isContainer() const
{
    return false;
}

QString QCirularBarPlugin::domXml() const
{
    return "<widget class=\"QCircularBar\" name=\"qCircularBar\">\n"
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

QString QCirularBarPlugin::includeFile() const
{
    return "qcircularbar.h";
}

//Q_EXPORT_PLUGIN2(customwidgetplugin, QMeterPlugin)
