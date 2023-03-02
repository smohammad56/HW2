#include "Wheel.h"
#include <random>
#include <exception>
#include <iostream>

class InvalidInputException : public std::exception {
public: static const char* what() { return "InvalidInputException: Please enter a valid input"; }
};


Wheel::Wheel(int r) {
	if (range < 6 || range > 20) {
		InvalidInputException ex;
		throw ex;
	}
	range = r;
}

int Wheel::spin() {
	return (rand() % (range)) + 1;
}


float Wheel::take_turn(float wager) {
	int house_roll = spin();
	std::cout << "The House rolled a " << house_roll << '\n';

	if (wager == 1) {
		if (house_roll > playerRoll) {
			return -bet;
		}
		else {
			return bet;
		}
	}
	else if (wager == 2) {
		int house_roll2 = spin();
		std::cout << "The house rolled a " << house_roll2 << " for its second roll\n";
		if (house_roll > playerRoll || house_roll2 > playerRoll) {
			return -(bet * 2);
		}
		else {
			return bet * 2;
		}
	}
	else if (wager == .5) {
		int house_roll2 = spin();
		std::cout << "The house rolled a " << house_roll2 << " for its second roll\n";
		if (house_roll > playerRoll && house_roll2 > playerRoll) {
			return -(bet * .5);
		}
		else {
			return bet * .5;
		}
	}
	else {
		InvalidInputException ex;
		throw ex;
	}

}
