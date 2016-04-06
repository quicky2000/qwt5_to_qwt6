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

    double l_min = 0.0;
    double l_max = 10000.0;
#if QWT_VERSION >= 0x060000
  m_time_slider = new QwtSlider(Qt::Horizontal,this);
  m_time_slider->setScalePosition(QwtSlider::NoScale);
  // To define background style for Qwt slider there are some setters to control display of groove and trough
  //m_time_slider->setBackgroundStyle(QwtSlider::BgBoth) ;
  // Ensure that both Groove and Trough are displayed as it was the case with Qwt 5.x
  m_time_slider->setGroove(true);
  m_time_slider->setTrough(true);

  // Due to changes in Qwt desing it seems that the notion of range has been relaced by the notion of Scale defined in qwt_abstract_scale class
  //  m_time_slider->setRange(gdata->leftTime(), gdata->rightTime(), 1.0/10000.0, 1000);
  m_time_slider->setScale(l_min,l_max);

  // the parameters defining how the slider behave inside the scale is now defined in class qwt_abstract_slider 
  double l_range_wdith = ( l_min < l_max ? l_max - l_min : l_min - l_max);
  unsigned int l_nb_steps = ((unsigned int)(l_range_wdith * 10000.0));
  m_time_slider->setTotalSteps(l_nb_steps);
  m_time_slider->setPageSteps(1000);

  // Graphical parameters
  // setThumbWidth and setThumbLength has been replaced by setHandleSize
  m_time_slider->setHandleSize(QSize(60,20));

  // Don't know how to deal with margins in Qwt 6.x

#else
#if QWT_VERSION >= 0x050000
  m_time_slider = new QwtSlider(this, Qt::Horizontal, QwtSlider::NoScale, QwtSlider::BgBoth);
#else
  m_time_slider = new QwtSlider(this, Qt::Horizontal, QwtSlider::None, QwtSlider::BgBoth);
#endif
    m_time_slider->setThumbWidth(20);
    m_time_slider->setThumbLength(60);
    m_time_slider->setMargins(2, 2);
    m_time_slider->setRange(l_min,l_max, 1.0/10000.0, 1000);
#endif // QWT_VERSION >= 0x060000

    m_time_slider->setTracking(true);
    m_time_slider->setBorderWidth(4);
    m_time_slider->setMinimumWidth(200);
    //m_time_slider->setScaleMaxMinor(4);
    //m_time_slider->setScaleMaxMajor(8);
    //m_time_slider->scaleDraw()->setMargin(0, 0);
    m_time_slider->setWhatsThis("Drag the time slider to move back and forward through the sound file");

    connect(m_time_slider, SIGNAL(valueChanged(double)), m_current_seq_number , SLOT(display(double)));

    l_layout->addWidget(m_time_slider);

    m_time_slider->setValue(500.0);
  }

}
//EOF
