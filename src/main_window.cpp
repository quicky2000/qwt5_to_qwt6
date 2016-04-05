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
#include "main_window.h"
#include "slider_widget.h"

namespace qwt5_to_qwt6
{
  //----------------------------------------------------------------------------
  main_window::main_window(void):
    m_slider_widget(nullptr)
  {
    m_slider_widget = new slider_widget(this);
    setCentralWidget(m_slider_widget);
  }

}
//EOF
