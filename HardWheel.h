#pragma once
#include "Wheel.h"

class HardWheel : public Wheel {
private:
	int house_win_count = 0;
	float wager = 0;

public:
	HardWheel(int r);
	float take_turn(float wager); //equivalent to spin
	int getHouseWinCount() { return house_win_count; }
};