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

#include <QtDesigner>
#include <QtGui>
#include <QMessageBox>

#include "qmeter.h"

#include "qmetertaskmenu.h"
#include "dialogqmeter.h"

QMeterTaskMenu::QMeterTaskMenu(QMeter *tic, QObject *parent)
    : QObject(parent)
{
    qMeter = tic;

    editStateAction = new QAction(tr("Help QMeter..."), this);
    connect(editStateAction, SIGNAL(triggered()), this, SLOT(editState()));
}

void QMeterTaskMenu::editState()
{
   DialogQMeter d;
// QMeterPropertiesDialog d(0);
   d.exec();
	//qMeter->setValue(12);
    
}

QAction *QMeterTaskMenu::preferredEditAction() const
{
    return editStateAction;
}

QList<QAction *> QMeterTaskMenu::taskActions() const
{
    QList<QAction *> list;
    list.append(editStateAction);
    return list;
}

QMeterTaskMenuFactory::QMeterTaskMenuFactory(QExtensionManager *parent)
    : QExtensionFactory(parent)
{
}

QObject *QMeterTaskMenuFactory::createExtension(QObject *object,
                                                   const QString &iid,
                                                   QObject *parent) const
{
    if (iid != Q_TYPEID(QDesignerTaskMenuExtension))
        return 0;

    if (QMeter *tic = qobject_cast<QMeter*>(object))
        return new QMeterTaskMenu(tic, parent);

    return 0;
}
