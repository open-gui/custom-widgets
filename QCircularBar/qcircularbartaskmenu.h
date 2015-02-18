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

#ifndef QMETERTASKMENU_H
#define QMETERTASKMENU_H

#include <QDesignerTaskMenuExtension>
#include <QExtensionFactory>

class QAction;
class QExtensionManager;
class QCircularBar;

class QCircularBarTaskMenu : public QObject, public QDesignerTaskMenuExtension
{
    Q_OBJECT
    Q_INTERFACES(QDesignerTaskMenuExtension)

public:
    QCircularBarTaskMenu(QCircularBar *tic, QObject *parent);

    QAction *preferredEditAction() const;
    QList<QAction *> taskActions() const;

private slots:
    void editState();

private:
    QAction *editStateAction;
    QCircularBar *qCircularBar;
};

class QCircularBarTaskMenuFactory : public QExtensionFactory
{
    Q_OBJECT

public:
    QCircularBarTaskMenuFactory(QExtensionManager *parent = 0);

protected:
    QObject *createExtension(QObject *object, const QString &iid, QObject *parent) const;
};

#endif
