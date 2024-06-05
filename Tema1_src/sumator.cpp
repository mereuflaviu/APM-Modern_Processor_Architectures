//Mereu Ioan Flaviu  333CC

#include "sumator.h"
#include <iostream>
#include <ap_int.h>


void compute_partial_sum(ap_uint<4> a, ap_uint<4> b, ap_uint<1> cin, ap_uint<4>& sum, ap_uint<1>& P, ap_uint<1>& G) {
    ap_uint<4> g, p, c;

    g = a & b;
    p = a | b;

    c[0] = g[0] | (p[0] & cin);
    c[1] = g[1] | (p[1] & g[0]) | (p[1] & p[0] & cin);
    c[2] = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & cin);

    G = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]) | (p[3] & p[2] & p[1] & g[0]);
    P = p[3] & p[2] & p[1] & p[0];

    sum[0] = a[0] ^ b[0] ^ cin;
    sum[1] = a[1] ^ b[1] ^ c[0];
    sum[2] = a[2] ^ b[2] ^ c[1];
    sum[3] = a[3] ^ b[3] ^ c[2];
}

// Main function for the 16-bit adder
void adder(ap_uint<16> a, ap_uint<16> b, ap_uint<1> cin, ap_uint<16>& sum, ap_uint<1>& cout) {
#pragma HLS INTERFACE mode=ap_ctrl_none port=return
#pragma HLS INTERFACE mode=ap_none port=a
#pragma HLS INTERFACE mode=ap_none port=b
#pragma HLS INTERFACE mode=ap_none port=cin
#pragma HLS INTERFACE mode=ap_none port=sum
#pragma HLS INTERFACE mode=ap_none port=cout
#pragma HLS PIPELINE II=1

	ap_uint<4> p[4], g[4];
	ap_uint<4> partial_sum;
	ap_uint<1> auxP, auxG;

	compute_partial_sum(a.range(3, 0), b.range(3, 0), cin, partial_sum, auxP, auxG);
	sum.range(3, 0) = partial_sum;
	p[0] = auxP;
	g[0] = auxG;

	compute_partial_sum(a.range(7, 4), b.range(7, 4), g[0] | (p[0] & cin), partial_sum, auxP, auxG);
	sum.range(7, 4) = partial_sum;
	p[1] = auxP;
	g[1] = auxG;

	compute_partial_sum(a.range(11, 8), b.range(11, 8), g[1] | (p[1] & g[0]) | (p[1] & p[0] & cin), partial_sum, auxP, auxG);
	sum.range(11, 8) = partial_sum;
	p[2] = auxP;
	g[2] = auxG;

	compute_partial_sum(a.range(15, 12), b.range(15, 12), g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & cin), partial_sum, auxP, auxG);
	sum.range(15, 12) = partial_sum;
	p[3] = auxP;
	g[3] = auxG;

	cout = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]) | (p[3] & p[2] & p[1] & g[0]) | (p[3] & p[2] & p[1] & p[0] & cin);
}

