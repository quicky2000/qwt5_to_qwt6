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
#include "slider_widget.h"
#include <qwt_slider.h>
#include <QLCDNumber>
#include <QVBoxLayout>

namespace qwt5_to_qwt6
{
  //----------------------------------------------------------------------------
  slider_widget::slider_widget(QWidget * parent):
    m_time_slider(nullptr),
    m_current_seq_number(nullptr)
  {
    QVBoxLayout * l_layout = new QVBoxLayout(this);
    m_current_seq_number = new QLCDNumber();
    m_current_seq_number->setDigitCount(9);
    l_layout->addWidget(m_current_seq_number);

    m_time_slider = new QwtSlider(this, Qt::Horizontal, QwtSlider::NoScale, QwtSlider::BgBoth);
    m_time_slider->setThumbWidth(20);
    m_time_slider->setThumbLength(60);
    m_time_slider->setMargins(2, 2);
    m_time_slider->setRange(0.0,10000.0, 1.0/10000.0, 1000);

    m_time_slider->setValue(500.0);
    m_time_slider->setTracking(true);
    m_time_slider->setBorderWidth(4);
    m_time_slider->setMinimumWidth(200);
    //m_time_slider->setScaleMaxMinor(4);
    //m_time_slider->setScaleMaxMajor(8);
    //m_time_slider->scaleDraw()->setMargin(0, 0);
    m_time_slider->setWhatsThis("Drag the time slider to move back and forward through the sound file");

    connect(m_time_slider, SIGNAL(valueChanged(double)), m_current_seq_number , SLOT(display(double)));

    l_layout->addWidget(m_time_slider);
  }

}
//EOF
