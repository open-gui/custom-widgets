#include "dialogqcircularbar.h"
#include "ui_dialogqcircularbar.h"

DialogQCircularBar::DialogQCircularBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogQCircularBar)
{
    ui->setupUi(this);
}

DialogQCircularBar::~DialogQCircularBar()
{
    delete ui;
}
