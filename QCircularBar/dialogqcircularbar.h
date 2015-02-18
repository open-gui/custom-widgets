#ifndef DIALOGQMETER_H
#define DIALOGQMETER_H

#include <QDialog>

namespace Ui {
class DialogQCircularBar;
}

class DialogQCircularBar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQCircularBar(QWidget *parent = 0);
    ~DialogQCircularBar();

private:
    Ui::DialogQCircularBar *ui;
};

#endif // DIALOGQMETER_H
