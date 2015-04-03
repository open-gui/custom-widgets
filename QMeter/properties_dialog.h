

#ifndef PROPDIALOG_H
#define PROPDIALOG_H
#include "ui_properties.h"


class QMeterPropertiesDialog : public QDialog, public Ui::propertiesDialog
{
 Q_OBJECT
 
 public:
 QMeterPropertiesDialog (QWidget* =0);

public slots:
 void callBrowser(QString);

};
#endif
