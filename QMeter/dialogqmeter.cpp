#include "dialogqmeter.h"
#include "ui_dialogqmeter.h"

DialogQMeter::DialogQMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogQMeter)
{
    ui->setupUi(this);
}

DialogQMeter::~DialogQMeter()
{
    delete ui;
}
