/* -*- C -*- */
// Copyright (C) 2010 Johan Hake
// Licensed under the GNU LGPL Version 2.1.
//
// First added:  2010-08-06
// Last changed: 2010-08-11
//
// ===========================================================================
// Main SWIG directive file for GAMer 
// ===========================================================================

%module (package="gamer") cgamer

// Code included verbatim into the header section of the generated wrapper code
%{
#include <gamer/gamer.h>
#define PY_ARRAY_UNIQUE_SYMBOL PyDOLFIN
#include <numpy/arrayobject.h>
%}


// Code included verbatim into the generated wrapper where the Python module
//  gets initialized
%init%{
import_array();
%}

// Include general SWIG directives
%include <exception.i>

// Generate docstrings
%feature("autodoc", "0");

// Include gamer typemaps
%include "gamer_typemaps.i"

// Apply SWIG directives before reading the header files
%include "pre.i"

// Include the interface of GAMer
%include "biom.i"

// Apply SWIG directives after reading the header files
%include "post.i"

