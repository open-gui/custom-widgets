#ifndef DIALOGQMETER_H
#define DIALOGQMETER_H

#include <QDialog>

namespace Ui {
class DialogQMeter;
}

class DialogQMeter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQMeter(QWidget *parent = 0);
    ~DialogQMeter();

private:
    Ui::DialogQMeter *ui;
};

#endif // DIALOGQMETER_H
