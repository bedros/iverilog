#ifndef __vvm_vvm_calltf_H
#define __vvm_vvm_calltf_H
/*
 * Copyright (c) 1998-1999 Stephen Williams (steve@icarus.com)
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
#ident "$Id: vvm_calltf.h,v 1.6 2002/08/12 01:35:06 steve Exp $"
#endif

# include  "vvm.h"
# include  <string>


/*
 * This function loads a vpi module by name.
 */
extern void vvm_set_module_path(const char*path);
extern void vvm_load_vpi_module(const char*path);


/*
 * $Log: vvm_calltf.h,v $
 * Revision 1.6  2002/08/12 01:35:06  steve
 *  conditional ident string using autoconfig.
 *
 * Revision 1.5  2000/02/23 02:56:56  steve
 *  Macintosh compilers do not support ident.
 *
 * Revision 1.4  1999/11/28 18:05:37  steve
 *  Set VPI_MODULE_PATH in the target code, if desired.
 *
 * Revision 1.3  1999/10/28 00:47:25  steve
 *  Rewrite vvm VPI support to make objects more
 *  persistent, rewrite the simulation scheduler
 *  in C (to interface with VPI) and add VPI support
 *  for callbacks.
 *
 * Revision 1.2  1999/08/15 01:23:56  steve
 *  Convert vvm to implement system tasks with vpi.
 *
 * Revision 1.1  1998/11/09 23:44:11  steve
 *  Add vvm library.
 *
 */
#endif
