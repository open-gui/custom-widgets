

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
