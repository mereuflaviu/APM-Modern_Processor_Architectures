//Mereu Ioan Flaviu  333CC

#include "sumator-tb.h"
#include <iostream>
#pragma HLS WAVE

int main() {
    ap_uint<16> a = 10;
    ap_uint<16> b = 5;
    ap_uint<16> sum = 0;
    ap_uint<1> cin = 0;
    ap_uint<1> cout = 0;

    adder(a, b, cin, sum, cout);

    std::cout << "Test1: ";
    std::cout << "Am adunat a=" << a << ", am adunat b=" << b << ", suma este sum=" << sum  << std::endl;

    if (sum == a + b) {
        std::cout << "      PASSED" << std::endl;
    } else {
        std::cout << "      FAILED" << std::endl;
    }

    a = 9;
    b = 4;
    sum = 0;
    cin = 0;
    cout = 0;

    adder(a, b, cin, sum, cout);

    std::cout << "Test2: ";
    std::cout << "Am adunat a=" << a << ", am adunat b=" << b << ", suma este sum=" << sum  << std::endl;

    if (sum == a + b) {
        std::cout << "      PASSED" << std::endl;
    } else {
        std::cout << "      FAILED" << std::endl;
    }

    a = 10;
    b = 20;
    sum = 0;
    cin = 0;
    cout = 0;

    adder(a, b, cin, sum, cout);

    std::cout << "Test3: ";
    std::cout << "Am adunat a=" << a << ", am adunat b=" << b << ", suma este sum=" << sum  << std::endl;

    if (sum == a + b) {
        std::cout << "      PASSED" << std::endl;
    } else {
        std::cout << "      FAILED" << std::endl;
    }

    return 0;
}
