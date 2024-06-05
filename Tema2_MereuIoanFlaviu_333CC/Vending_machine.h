//Mereu Ioan Flaviu 333CC
#pragma once

enum State {
	in0,
	in5,
	in10,
	in15,
	in20,
	in25,
	in30,
	in35,
	in40,
	in45,
	thanks
};


void press_thanks(); 
void money_in(bool in_5, bool in_10, bool in_25);
void vending_machine(bool in_5, bool in_10, bool in_25, bool in_thanks, bool& out_drink, bool& rest_5, bool& rest1_10, bool& rest2_10);
