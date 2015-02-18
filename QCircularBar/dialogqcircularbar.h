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
