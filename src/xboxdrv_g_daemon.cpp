/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2011 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "xboxdrv_g_daemon.hpp"

#include "xboxdrv_daemon.hpp"

/* will create xboxdrv_g_daemon_get_type and set xboxdrv_g_daemon_parent_class */
G_DEFINE_TYPE(XboxdrvGDaemon, xboxdrv_g_daemon, G_TYPE_OBJECT)

static GObject *
xboxdrv_g_daemon_constructor (GType                  gtype,
                              guint                  n_properties,
                              GObjectConstructParam *properties)
{
  GObject *obj;

  {
    /* Always chain up to the parent constructor */
    GObjectClass *parent_class;  
    parent_class = G_OBJECT_CLASS (xboxdrv_g_daemon_parent_class);
    obj = parent_class->constructor (gtype, n_properties, properties);
  }
  
  return obj;
}

static void
xboxdrv_g_daemon_class_init (XboxdrvGDaemonClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->constructor = xboxdrv_g_daemon_constructor;
}

static void
xboxdrv_g_daemon_init (XboxdrvGDaemon *self)
{
  /* initialize the object */
  /* update the object state depending on constructor properties */
  self->daemon = NULL;
}

XboxdrvGDaemon*
xboxdrv_g_daemon_new(XboxdrvDaemon* daemon)
{
  XboxdrvGDaemon* self = static_cast<XboxdrvGDaemon*>(g_object_new(XBOXDRV_TYPE_G_DAEMON, NULL));

  self->daemon = daemon;

  return self;
}

void
xboxdrv_g_daemon_status(XboxdrvGDaemon* self)
{
  self->daemon->status();
}

/* EOF */
