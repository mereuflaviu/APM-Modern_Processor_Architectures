//Mereu Ioan Flaviu  333CC

#ifndef SUMATOR_H
#define SUMATOR_H

#include <ap_int.h>

// Function for calculating the sum on 4 bits, with propagate (P) and generate (G)
void compute_partial_sum(ap_uint<4> a, ap_uint<4> b, ap_uint<1> cin, ap_uint<4>& sum, ap_uint<1>& P, ap_uint<1>& G);

// Main function for the 16-bit adder
void adder(ap_uint<16> a, ap_uint<16> b, ap_uint<1> cin, ap_uint<16>& sum, ap_uint<1>& cout);

#endif // SUMATOR_H
