
#include "properties_dialog.h"
#include <QDialog>
#include <QFile> 
#include <QDesktopServices>
#include <QUrl>

QMeterPropertiesDialog::QMeterPropertiesDialog (QWidget *parent)
    :QDialog(parent)
{
    setupUi(this); 
    setFixedSize(size());
    qMeter->setThresholdEnabled(true);
    qMeter->setNumericIndicatorEnabled(true);
    connect(urlLabel,SIGNAL(linkActivated(QString)),this,SLOT(callBrowser(QString)));
   
}


void QMeterPropertiesDialog::callBrowser(QString url)
{
QDesktopServices::openUrl(QUrl(url));
	
}
