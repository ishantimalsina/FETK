### ##########################################################################
### SG = < Socket Graphics >
### Copyright (C) 1994-- Michael Holst
### 
### This library is free software; you can redistribute it and/or
### modify it under the terms of the GNU Lesser General Public
### License as published by the Free Software Foundation; either
### version 2.1 of the License, or (at your option) any later version.
### 
### This library is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
### Lesser General Public License for more details.
### 
### You should have received a copy of the GNU Lesser General Public
### License along with this library; if not, write to the Free Software
### Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
### 
### rcsid="$Id: Makefile.am,v 1.29 2010/08/09 19:02:06 fetk Exp $"
### ##########################################################################

## ###########################################################################
## File:    Makefile.am
##
## Purpose: Automatically generate Makefile.in for autoconf using automake.
##
## Notes:   The final makefile produced by autoconf will use the following:
##
##     COMPILE = $(CC) $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS)
##     LINK = $(CC) $(CFLAGS) $(LDFLAGS) -o $@
##
## Author:  Michael Holst
## ###########################################################################

AUTOMAKE_OPTIONS = no-dependencies
SUFFIXES = .y .l .H .h .m .C .cc .c .f .java .o
always_built_SUBDIRS =
SUBDIRS = $(always_built_SUBDIRS) . @vtst@

if EXISTS_MOTIF
MOTIF_BINS = sg
else
MOTIF_BINS =
endif

bin_PROGRAMS     = mcsg ${MOTIF_BINS} tilesg

mcsg_SOURCES     = main.c
mcsg_LDADD       = @sg_lib@ @maloc_lib@ @glw_lib@ @glu_lib@ @gl_lib@ @motif_lib@ @x_lib@ @rl_lib@ @liberty_lib@ @socket_lib@ @nsl_lib@ @thread_lib@ @objc_lib@ @math_lib@ @zfence_lib@ @profile_lib@

sg_SOURCES       = main.c
sg_LDADD         = @sg_lib@ @maloc_lib@ @glw_lib@ @glu_lib@ @gl_lib@ @motif_lib@ @x_lib@ @rl_lib@ @liberty_lib@ @socket_lib@ @nsl_lib@ @thread_lib@ @objc_lib@ @math_lib@ @zfence_lib@ @profile_lib@

tilesg_SOURCES   = tilesg.c
tilesg_LDADD     = @x_lib@ @liberty_lib@ @socket_lib@ @nsl_lib@ @thread_lib@ @objc_lib@ @math_lib@ @zfence_lib@ @profile_lib@

INCLUDES         = @sg_inc@ @maloc_inc@
AM_CFLAGS        = @profile@ @wall_pedantic_ansi@

