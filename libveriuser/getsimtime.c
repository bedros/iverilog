/* vi:sw=6
 * Copyright (c) 2002 Michael Ruff (mruff at chiaro.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifdef HAVE_CVS_IDENT
#ident "$Id: getsimtime.c,v 1.2 2002/08/12 01:35:02 steve Exp $"
#endif

#include  <vpi_user.h>

/*
 * tf_getlongtime implemented using VPI interface
 */
int tf_getlongtime(int *hightime)
{
      s_vpi_time time;
      vpi_get_time (0 /* NULL */, &time);
      *hightime = time.high;
      return time.low;
}

/* Alias for commercial simulators */
int tf_getlongsimtime(int *hightime) \
      __attribute__ ((weak, alias ("tf_getlongtime")));

/*
 * $Log: getsimtime.c,v $
 * Revision 1.2  2002/08/12 01:35:02  steve
 *  conditional ident string using autoconfig.
 *
 * Revision 1.1  2002/05/31 18:25:51  steve
 *  Add tf_getlongtime (mruff)
 *
 */
