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
#include "compass_widget.h"
#include <qwt_dial_needle.h>
#include <qwt_compass.h>
#include <qwt_compass_rose.h>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QMap>

namespace qwt5_to_qwt6
{
  //----------------------------------------------------------------------------
  compass_widget::compass_widget(QWidget * parent):
    m_compass(nullptr),
    m_current_seq_number(nullptr)
  {
    QVBoxLayout * l_layout = new QVBoxLayout(this);
    m_current_seq_number = new QLCDNumber();
    m_current_seq_number->setDigitCount(9);
    l_layout->addWidget(m_current_seq_number);

    m_compass = new QwtCompass(this);
    m_compass->setLineWidth(4);
    m_compass->setFrameShadow(QwtCompass::Sunken);

#if QWT_VERSION >= 0x060000
    QwtCompassScaleDraw *l_scale_draw = new QwtCompassScaleDraw();
    //    l_scale_draw->setRadius(400);
#endif // QWT_VERSION >= 0x060000


    unsigned int l_mode = 2;
    if (l_mode == 0)
      {
	m_compass->setMode(QwtCompass::RotateNeedle);
#if QWT_VERSION >= 0x060000
	m_compass->setScale(36, 5);
	// Stepping is now defined by qwt_abstract_slider
	m_compass->setSingleSteps(0);
#else
	m_compass->setScale(36, 5, 0);
#endif // QWT_VERSION >= 0x060000
      }
    else if (l_mode == 1)
      {
	m_compass->setMode(QwtCompass::RotateScale);
	m_compass->setScale(360, 0);
      }
    else if (l_mode == 2)
      {
	m_compass->setMode(QwtCompass::RotateNeedle);

	char * l_note_names[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
	QMap< double, QString > l_notes;
#if QWT_VERSION >= 0x060000
	m_compass->setScale(11, 2);
	// Stepping is now defined by qwt_abstract_slider
	m_compass->setSingleSteps(30);

	for (int i = 0; i < 12; i++)
	  {
	    l_notes[i] = l_note_names[i];
	  }
	l_scale_draw->setLabelMap(l_notes);
#else
	m_compass->setScale(11, 2, 30);
	for (int i = 0; i < 12; i++)
	  {
	    l_notes[i * 30] = l_note_names[i];
	  }
	m_compass->setLabelMap(l_notes);
#endif // QWT_VERSION >= 0x060000
      }

#if QWT_VERSION >= 0x060000
    l_scale_draw->enableComponent( QwtAbstractScaleDraw::Ticks, true );
    l_scale_draw->enableComponent( QwtAbstractScaleDraw::Labels, true );
    l_scale_draw->enableComponent( QwtAbstractScaleDraw::Backbone, true );
    l_scale_draw->setTickLength( QwtScaleDiv::MinorTick,10);
    l_scale_draw->setTickLength( QwtScaleDiv::MediumTick,20);
    l_scale_draw->setTickLength( QwtScaleDiv::MajorTick,30);
    m_compass->setScaleDraw(l_scale_draw);
#else
    m_compass->setScaleTicks(1, 1, 3);
#endif // QWT_VERSION >= 0x060000

    m_compass->setNeedle(new QwtCompassMagnetNeedle(QwtCompassMagnetNeedle::ThinStyle));
    m_compass->setValue(0.0);



    connect(m_compass, SIGNAL(valueChanged(double)), m_current_seq_number , SLOT(display(double)));

    l_layout->addWidget(m_compass);

    //    m_compass->setReadOnly(true);
    m_compass->show();

  }

}
//EOF
