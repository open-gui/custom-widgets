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

#include <QtDesigner>
#include <QtGui>
#include <QMessageBox>

#include "qcircularbar.h"

#include "qcircularbartaskmenu.h"
#include "dialogqcircularbar.h"

QCircularBarTaskMenu::QCircularBarTaskMenu(QCircularBar *tic, QObject *parent)
    : QObject(parent)
{
    qCircularBar = tic;

    editStateAction = new QAction(tr("Help QCircularBar..."), this);
    connect(editStateAction, SIGNAL(triggered()), this, SLOT(editState()));
}

void QCircularBarTaskMenu::editState()
{
   DialogQCircularBar d;
// QMeterPropertiesDialog d(0);
   d.exec();
	//qMeter->setValue(12);
    
}

QAction *QCircularBarTaskMenu::preferredEditAction() const
{
    return editStateAction;
}

QList<QAction *> QCircularBarTaskMenu::taskActions() const
{
    QList<QAction *> list;
    list.append(editStateAction);
    return list;
}

QCircularBarTaskMenuFactory::QCircularBarTaskMenuFactory(QExtensionManager *parent)
    : QExtensionFactory(parent)
{
}

QObject *QCircularBarTaskMenuFactory::createExtension(QObject *object,
                                                   const QString &iid,
                                                   QObject *parent) const
{
    if (iid != Q_TYPEID(QDesignerTaskMenuExtension))
        return 0;

    if (QCircularBar *tic = qobject_cast<QCircularBar*>(object))
        return new QCircularBarTaskMenu(tic, parent);

    return 0;
}
