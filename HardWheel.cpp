#include "HardWheel.h"
#include <random>
#include <exception>
#include <iostream>

class InvalidInputException : public std::exception {
public: static const char* what() { return "InvalidInputException: Please enter a valid input"; }
};


HardWheel::HardWheel(int r) {
	if (getRange() < 6 || getRange() > 20) {
		InvalidInputException ex;
		throw ex;
	}
	setRange(r);
}

float HardWheel::take_turn(float wager) {
	int house_roll = spin();
	std::cout << "The House rolled a " << house_roll << '\n';

	if (house_win_count == 2 && getRange() > 6) {
		setRange(getRange() - 1);
		std::cout << "The House has won twice in a row! The wheel's range is now " << getRange() << '\n';
	}

	if (wager == 1) {
		if (house_roll > getPlayerRoll()) {
			house_win_count++;
			return -bet;
		}
		else {
			house_win_count = 0;
			setRange(getRange() + 1);
			std::cout << "The House has lost! The wheel's range is now " << getRange() << '\n';
			return bet;
		}
	}
	else if (wager == 2) {
		int house_roll2 = spin();
		std::cout << "The house rolled a " << house_roll2 << " for its second roll\n";
		if (house_roll > getPlayerRoll() || house_roll2 > getPlayerRoll()) {
			house_win_count++;
			return -(bet * 2);
		}
		else {
			house_win_count = 0;
			setRange(getRange() + 1);
			std::cout << "The House has lost! The wheel's range is now " << getRange() << '\n';
			return bet * 2;
		}
	}
	else if (wager == .5) {
		int house_roll2 = spin();
		std::cout << "The house rolled a " << house_roll2 << " for its second roll\n";
		if (house_roll > getPlayerRoll() && house_roll2 > getPlayerRoll()) {
			house_win_count++;
			return -(bet * .5);
		}
		else {
			house_win_count = 0;
			setRange(getRange() + 1);
			std::cout << "The House has lost! The wheel's range is now " << getRange() << '\n';
			return (bet * .5);
		}
	}
	else {
		InvalidInputException ex;
		throw ex;
	}

}
