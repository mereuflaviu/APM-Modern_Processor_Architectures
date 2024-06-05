//Mereu Ioan Flaviu 333CC
#include <iostream>
#include "Vending_machine.h"


using namespace std;

void money_in(bool in_5, bool in_10, bool in_25) {

	bool out_drink, in_thanks, rest_5, rest1_10, rest2_10;

	vending_machine(in_5, in_10, in_25, in_thanks, out_drink, rest_5, rest1_10, rest2_10);

	cout << "intra 5 = " << in_5 << ", intra 10 = " << in_10 << ", intra 25 = " << in_25 << ", in_thanks = " << in_thanks << endl;
	cout << "out_drink = " << out_drink << ", rest bancnota 5 = " << rest_5 << ", rest bancnota1 10 = " << rest1_10 << ", rest bancnota2 10 = " << rest2_10 << endl;
	cout << endl;
}

void press_thanks() {

	bool out_drink, in_thanks = 1, rest_5, rest1_10, rest2_10;

	vending_machine(0, 0, 0, in_thanks, out_drink, rest_5, rest1_10, rest2_10);

	cout << "in_5 = 0, in_10 = 0, in_25 = 0, in_thanks = " << in_thanks << endl << "S-a apasat THANK YOU!!!" << endl;
	cout << "out_drink = " << out_drink << ", rest bancnota 5 = " << rest_5 << ", rest bancnota1 10 = " << rest1_10 << ", rest bancnota2 10 = " << rest2_10 << endl;
	cout << endl;
}

void vending_machine(bool in_5, bool in_10, bool in_25, bool in_thanks, bool& out_drink, bool& rest_5, bool& rest1_10, bool& rest2_10) {

#pragma HLS INTERFACE ap_none port=in_5
#pragma HLS INTERFACE ap_none port=in_10
#pragma HLS INTERFACE ap_none port=in_25
#pragma HLS INTERFACE ap_none port=in_thanks
#pragma HLS INTERFACE ap_none port=out_drink
#pragma HLS INTERFACE ap_none port=rest_5
#pragma HLS INTERFACE ap_none port=rest1_10
#pragma HLS INTERFACE ap_none port=rest2_10
#pragma HLS INTERFACE ap_ctrl_none port=return

	static State current_state;
	State next_state = current_state;

	bool out_drink_ok;
	bool out_5, out1_10, out2_10;


	switch (current_state) {

	case in0:
		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_5)
			next_state = in5;
		else if (in_10)
			next_state = in10;
		else if (in_25)
			next_state = in25;
		else
			next_state = in0;
		break;

	case in5:
		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_5)
			next_state = in10;
		else if (in_10)
			next_state = in15;
		else if (in_25)
			next_state = in30;
		else
			next_state = in5;
		break;

	case in10:
		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_5)
			next_state = in15;
		else if (in_10)
			next_state = in20;
		else if (in_25)
			next_state = in35;
		else
			next_state = in10;
		break;

	case in15:
		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_5)
			next_state = in20;
		else if (in_10)
			next_state = in25;
		else if (in_25)
			next_state = in40;
		else
			next_state = in15;
		break;

	case in20:
		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_5)
			next_state = in25;
		else if (in_10)
			next_state = in30;
		else if (in_25)
			next_state = in45;
		else
			next_state = in20;
		break;

	case in25:
		out_drink_ok = 1;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		next_state = thanks;
		break;

	case in30:

		out_drink_ok = 1;
		out_5 = 1; out1_10 = 0; out2_10 = 0;

		next_state = thanks;
		break;

	case in35:

		out_drink_ok = 1;
		out_5 = 0; out1_10 = 1; out2_10 = 0;

		next_state = thanks;
		break;

	case in40:

		out_drink_ok = 1;
		out_5 = 1; out1_10 = 1; out2_10 = 0;

		next_state = thanks;
		break;

	case in45:

		out_drink_ok = 1;
		out_5 = 0; out1_10 = 1; out2_10 = 1;

		next_state = thanks;
		break;

	case thanks:

		out_drink_ok = 0;
		out_5 = 0; out1_10 = 0; out2_10 = 0;

		if (in_thanks == 1)
			next_state = in0;
		else
			next_state = thanks;
		break;

	default:
		return;
	}

	current_state = next_state;

	rest_5 = out_5;
	rest1_10 = out1_10;
	rest2_10 = out2_10;
	out_drink = out_drink_ok;
	

}
