/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DPD_EXTERNALS_GIVENS_ROTATE_H
#define INCLUDED_DPD_EXTERNALS_GIVENS_ROTATE_H

#include <armadillo>
#include <complex>

typedef std::complex<float> gr_complex;
using namespace arma;

void givens_rotate(const cx_fmat & in, cx_fmat & out);

#endif /*INCLUDED_DPD_EXTERNALS_GIVENS_ROTATE_H*/
