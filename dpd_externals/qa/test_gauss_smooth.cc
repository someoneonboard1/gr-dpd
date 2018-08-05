/* -*- c++ -*- */
/* 
 * Copyright 2016 
 * Srikanth Pagadarai <srikanth.pagadarai@gmail.com>
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

#include <iostream>
#include <fstream>
#include <string> 
#include <dpd_externals/gauss_smooth.h>
#include <dpd_externals/almost_equals_zero.h>

using namespace std;

void read_from_file(string file_name, int N, double *out) {
  ifstream ins(file_name);  
  string line;
  double value;
  int ii = 0;
  
  while (std::getline(ins, line)) {
    stringstream ss(line);

    while (ss >> value) {
      out[ii] = value;
      ii++;
    }        
  }  
}

int main(void) {
  int len;
  double *in_re, *in_im, *out_re, *out_im;
  string oct_str, suffix;
  string in_re_fn, in_im_fn, out_re_fn, out_im_fn;

  /* Test 1 */
  len = 200;
  suffix = "test1";
  oct_str = "./test_gauss_smooth.m " + to_string(len) + " " + suffix;
  system( oct_str.c_str() );

  // read real part of input
  in_re = (double *)malloc(len*sizeof(double));
  in_re_fn = "in_re_" + suffix + ".txt"; 
  read_from_file(in_re_fn, len, in_re);
  
  // read imag part of input
  in_im = (double *)malloc(len*sizeof(double));
  in_im_fn = "in_im_" + suffix + ".txt"; 
  read_from_file(in_im_fn, len, in_im);

  // read real part of output
  out_re = (double *)malloc(len*sizeof(double));
  out_re_fn = "out_re_" + suffix + ".txt"; 
  read_from_file(out_re_fn, len, out_re);
  
  // read imag part of output
  out_im = (double *)malloc(len*sizeof(double));
  out_im_fn = "out_im_" + suffix + ".txt"; 
  read_from_file(out_im_fn, len, out_im);

  // call gauss_smooth() with the same input as octave function call 
  gr_complexd in1[len], out1[len];
  gr_complexd sr1[10];
  for (int ii = 0; ii < len; ii++)
  {
    in1[ii] = gr_complexd(in_re[ii], in_im[ii]); 
    sr1[0] = in1[ii];
    gauss_smooth(sr1, out1[ii]);
  }

  // check if outputs are equal
  int test1_pass = 1;
  for (int kk = 0; kk < len; kk++) {
    if (     ( !almost_equals_zero( std::abs(out1[kk].real()-out_re[kk]), 3 ) ) || ( !almost_equals_zero( std::abs(out1[kk].imag()-out_im[kk]), 3 ) )     ) {
      test1_pass = 0;       
      break;
    }
  }

  if (test1_pass)
    std::cout << "gauss_smooth(): Test 1 Passed." << std::endl;
  else
    std::cerr << "gauss_smooth(): Test 1 Failed." << std::endl;

  /* Test 2 */
  len = 15;
  suffix = "test2";
  oct_str = "./test_gauss_smooth.m " + to_string(len) + " " + suffix;
  system( oct_str.c_str() );

  // read real part of input
  in_re = (double *)malloc(len*sizeof(double));
  in_re_fn = "in_re_" + suffix + ".txt"; 
  read_from_file(in_re_fn, len, in_re);
  
  // read imag part of input
  in_im = (double *)malloc(len*sizeof(double));
  in_im_fn = "in_im_" + suffix + ".txt"; 
  read_from_file(in_im_fn, len, in_im);

  // read real part of output
  out_re = (double *)malloc(len*sizeof(double));
  out_re_fn = "out_re_" + suffix + ".txt"; 
  read_from_file(out_re_fn, len, out_re);
  
  // read imag part of output
  out_im = (double *)malloc(len*sizeof(double));
  out_im_fn = "out_im_" + suffix + ".txt"; 
  read_from_file(out_im_fn, len, out_im);

  // call gauss_smooth() with the same input as octave function call 
  gr_complexd in2[len], out2[len];
  gr_complexd sr2[10];
  for (int ii = 0; ii < len; ii++)
  {
    in2[ii] = gr_complexd(in_re[ii], in_im[ii]);   
    sr2[0] = in2[ii];
    gauss_smooth(sr2, out2[ii]);    
  }

  // check if outputs are equal
  int test2_pass = 1;
  for (int kk = 0; kk < len; kk++) {
    if (     ( !almost_equals_zero( std::abs(out2[kk].real()-out_re[kk]), 3 ) ) || ( !almost_equals_zero( std::abs(out2[kk].imag()-out_im[kk]), 3 ) )     ) {
      test2_pass = 0;       
      break;
    }
  }

  if (test2_pass)
    std::cout << "gauss_smooth(): Test 2 Passed." << std::endl;
  else
    std::cerr << "gauss_smooth(): Test 2 Failed." << std::endl;

  /* Test 3 */
  len = 150;
  suffix = "test3";
  oct_str = "./test_gauss_smooth.m " + to_string(len) + " " + suffix;
  system( oct_str.c_str() );

  // read real part of input
  in_re = (double *)malloc(len*sizeof(double));
  in_re_fn = "in_re_" + suffix + ".txt"; 
  read_from_file(in_re_fn, len, in_re);
  
  // read imag part of input
  in_im = (double *)malloc(len*sizeof(double));
  in_im_fn = "in_im_" + suffix + ".txt"; 
  read_from_file(in_im_fn, len, in_im);

  // read real part of output
  out_re = (double *)malloc(len*sizeof(double));
  out_re_fn = "out_re_" + suffix + ".txt"; 
  read_from_file(out_re_fn, len, out_re);
  
  // read imag part of output
  out_im = (double *)malloc(len*sizeof(double));
  out_im_fn = "out_im_" + suffix + ".txt"; 
  read_from_file(out_im_fn, len, out_im);

  // call gauss_smooth() with the same input as octave function call 
  gr_complexd in3[len], out3[len];
  gr_complexd sr3[10];
  for (int ii = 0; ii < len; ii++)
  {
    in3[ii] = gr_complexd(in_re[ii], in_im[ii]);   
    sr3[0] = in3[ii];
    gauss_smooth(sr3, out3[ii]);    
  }

  // check if outputs are equal
  int test3_pass = 1;
  for (int kk = 0; kk < len; kk++) {
    if (     ( !almost_equals_zero( std::abs(out3[kk].real()-out_re[kk]), 3 ) ) || ( !almost_equals_zero( std::abs(out3[kk].imag()-out_im[kk]), 3 ) )     ) {
      test3_pass = 0;       
      break;
    }
  }

  if (test3_pass)
    std::cout << "gauss_smooth(): Test 3 Passed." << std::endl;
  else
    std::cerr << "gauss_smooth(): Test 3 Failed." << std::endl;

  return 0;
}
