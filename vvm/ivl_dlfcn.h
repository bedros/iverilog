#ifndef __ivl_dlfcn_H
#define __ivl_dlfcn_H
/*
 * Copyright (c) 2001 Stephen Williams (steve@icarus.com)
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
#ident "$Id: ivl_dlfcn.h,v 1.5 2002/08/12 01:35:06 steve Exp $"
#endif

#if defined(__MINGW32__)
# include <windows.h>
# include <stdio.h>
typedef void * ivl_dll_t;
#elif defined(HAVE_DLFCN_H)
# include  <dlfcn.h>
typedef void* ivl_dll_t;
#elif defined(HAVE_DL_H)
# include  <dl.h>
typedef shl_t ivl_dll_t;
#endif

#if defined(__MINGW32__)
inline ivl_dll_t ivl_dlopen(const char *name)
{ return (void *)LoadLibrary(name); }

inline void *ivl_dlsym(ivl_dll_t dll, const char *nm)
{ return (void *)GetProcAddress((HINSTANCE)dll,nm);}

inline void ivl_dlclose(ivl_dll_t dll)
{ (void)FreeLibrary((HINSTANCE)dll);}

inline const char *dlerror(void)
{ static char s[30]; sprintf(s,"DLError:%ld", GetLastError()); return s;}

#elif defined(HAVE_DLFCN_H)
inline ivl_dll_t ivl_dlopen(const char*name)
{ return dlopen(name,RTLD_LAZY); }

inline void* ivl_dlsym(ivl_dll_t dll, const char*nm)
{ return dlsym(dll, nm); }

inline void ivl_dlclose(ivl_dll_t dll)
{ dlclose(dll); }

#elif defined(HAVE_DL_H)
inline ivl_dll_t ivl_dlopen(const char*name)
{ return shl_load(name, BIND_IMMEDIATE, 0); }

inline void* ivl_dlsym(ivl_dll_t dll, const char*nm)
{
      void*sym;
      int rc = shl_findsym(&dll, nm, TYPE_PROCEDURE, &sym);
      return (rc == 0) ? sym : 0;
}

inline void ivl_dlclose(ivl_dll_t dll)
{ shl_unload(dll); }

inline const char*dlerror(void)
{ return strerror( errno ); }
#endif

/*
 * $Log: ivl_dlfcn.h,v $
 * Revision 1.5  2002/08/12 01:35:06  steve
 *  conditional ident string using autoconfig.
 *
 * Revision 1.4  2002/01/23 04:54:38  steve
 *  Load modules with RTLD_LAZY
 *
 * Revision 1.3  2001/05/22 02:14:47  steve
 *  Update the mingw build to not require cygwin files.
 *
 * Revision 1.2  2001/05/20 15:09:40  steve
 *  Mingw32 support (Venkat Iyer)
 *
 * Revision 1.1  2001/03/16 01:44:34  steve
 *  Add structures for VPI support, and all the %vpi_call
 *  instruction. Get linking of VPI modules to work.
 *
 * Revision 1.1  2001/01/14 17:12:59  steve
 *  possible HP/UX portability support.
 *
 */
#endif
