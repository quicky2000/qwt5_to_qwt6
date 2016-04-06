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
#include "wheel_widget.h"
#include <qwt_wheel.h>
#include <QLCDNumber>
#include <QVBoxLayout>

namespace qwt5_to_qwt6
{
  //----------------------------------------------------------------------------
  wheel_widget::wheel_widget(QWidget * parent):
    m_wheel(nullptr),
    m_current_seq_number(nullptr)
  {
    QVBoxLayout * l_layout = new QVBoxLayout(this);
    m_current_seq_number = new QLCDNumber();
    m_current_seq_number->setDigitCount(9);
    l_layout->addWidget(m_current_seq_number);

    m_wheel = new QwtWheel(this);
    m_wheel->setOrientation(Qt::Vertical);
    m_wheel->setWheelWidth(14);

#if QWT_VERSION >= 0x060000
    m_wheel->setRange(1.6,5.0);
    m_wheel->setSingleStep(0.001);
    // Use 1000 value for multiplicator so that PageStep has size 1
    m_wheel->setPageStepCount(1000);
#else
    m_wheel->setRange(1.6, 5.0, 0.001, 1);
#endif // QWT_VERSION >= 0x060000

    connect(m_wheel, SIGNAL(valueChanged(double)), m_current_seq_number , SLOT(display(double)));

    l_layout->addWidget(m_wheel);

    m_wheel->setValue(3.2);

  }

}
//EOF
