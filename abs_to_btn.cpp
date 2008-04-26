/*  $Id$
**   __      __ __             ___        __   __ __   __
**  /  \    /  \__| ____    __| _/_______/  |_|__|  | |  |   ____
**  \   \/\/   /  |/    \  / __ |/  ___/\   __\  |  | |  | _/ __ \
**   \        /|  |   |  \/ /_/ |\___ \  |  | |  |  |_|  |_\  ___/
**    \__/\  / |__|___|  /\____ /____  > |__| |__|____/____/\___  >
**         \/          \/      \/    \/                         \/
**  Copyright (C) 2007 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation; either version 2
**  of the License, or (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
** 
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
**  02111-1307, USA.
*/

#include <boost/bind.hpp>
#include "abs_to_btn.hpp"

AbsToBtn::AbsToBtn(int threshold)
  : threshold(threshold)
{
  abs_port_in.push_back(new AbsPortIn("AbsToBtn-In", 0, 0, 
                                      boost::bind(&AbsToBtn::on_abs, this, _1)));

  btn_port_out.push_back(new BtnPortOut("AbsToBtn-Out-0"));
  btn_port_out.push_back(new BtnPortOut("AbsToBtn-Out-1"));
}

void
AbsToBtn::on_abs(AbsPortOut* port)
{
  if (abs(port->get_state() > threshold))
    {
      if (port->get_state() > 0)
        {
          btn_port_out[0]->set_state(true);
          btn_port_out[1]->set_state(false);
        }
      else
        {
          btn_port_out[0]->set_state(false);
          btn_port_out[1]->set_state(true);
        }
    }
  else
    {
      btn_port_out[0]->set_state(false);
      btn_port_out[1]->set_state(false);
    }
}

void
AbsToBtn::update(float delta)
{
}

/* EOF */
