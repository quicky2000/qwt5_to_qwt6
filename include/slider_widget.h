/*    This file is part qwt5_to_qwt6
      Copyright (C) 2016  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#ifndef SLIDER_WIDGET_H
#define SLIDER_WIDGET_H

#include <QWidget>

class QwtSlider;
class QLCDNumber;

namespace qwt5_to_qwt6
{
  class slider_widget: public QWidget
  {
  Q_OBJECT
  public:
    slider_widget(QWidget * parent = nullptr);
  private:
    QwtSlider *m_time_slider;
    QLCDNumber * m_current_seq_number;
  };

}
#endif // SLIDER_WIDGET_H
//EOF
