#include "Player.h"
#include "Wheel.h"
#include "HardWheel.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	//game level selection
	std::cout << "Would you like to play the game on hard mode? (Y/N)" <<endl;
	char i;
	std::cin >> i;

	//the range of wheel
	std::cout << "Enter the number of values you wish the wheel to have:" <<endl;
	int r;
	std::cin >> r;
	

	std::cout << "Enter the amount of money you wish to start with:" <<endl;
	float m;
	std::cin >> m;
	Player p = Player(m);

	Wheel w = Wheel(r);
	HardWheel z = HardWheel(r);

	//set the bet
	std::cout << "Enter the amount of money you wish to bet: " <<endl;
	float b;
	std::cin >> b;
	w.setBet(b);
	z.setBet(b);

	if (i == 'Y' || i == 'y') {
		//player's first roll
		int player_result = 0;
		int playerRoll = z.spin();
		std::cout << "You rolled a " << playerRoll << std::endl;
		z.setPlayerRoll(playerRoll);
		int conOrStop = 1;
		while (conOrStop == 1 && !(p.isBankrupt())) {
			float playerChoice;
			do {
				std::cout << "Enter 1 to keep the same wager\n";
				std::cout << "Enter 2 to double the wager\n";
				std::cout << "Enter 0.5 to halve the wager\n";
				std::cin >> playerChoice;
				if (playerChoice != 1 && playerChoice != 2 && playerChoice != 0.5) {
					std::cout << "Invalid Input. Please enter a valid number\n";
				}
			} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 0.5);

			p.setMoney(p.getMoney() + z.take_turn(playerChoice));
			std::cout << p.to_string();

			if (p.isBankrupt()) {
				std::cout << "The game is over\n";
				return 0;
			}
			int conOrStop;
			do {
				std::cout << "Enter 1 to continue the game\n";
				std::cout << "Enter 2 to stop the game\n";
				std::cin >> conOrStop;
				if (conOrStop != 2 && conOrStop != 1) {
					std::cout << "Invalid Input. Please enter a valid number\n";
				}
			} while (conOrStop != 2 && conOrStop != 1);

			if (conOrStop == 2) {
				std::cout << "The game is over\n";
				return 0;
			}
		}
	}

	else {

		int playerRoll = w.spin();
		std::cout << "You rolled a " << playerRoll << std::endl;
		w.setPlayerRoll(playerRoll);
		int conOrStop = 1;

		while (conOrStop == 1 && !(p.isBankrupt())) {
			float playerChoice;
			do {
				std::cout << "Enter 1 to keep the same wager\n";
				std::cout << "Enter 2 to double the wager\n";
				std::cout << "Enter 0.5 to halve the wager\n";
				std::cin >> playerChoice;
				if (playerChoice != 1 && playerChoice != 2 && playerChoice != 0.5) {
					std::cout << "Invalid Input. Please enter a valid number\n";
				}
			} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 0.5);

			p.setMoney(p.getMoney() + w.take_turn(playerChoice));
			std::cout << p.to_string();

			if (p.isBankrupt()) {
				std::cout << "The game is over\n";
				return 0;
			}
			int conOrStop;
			do {
				std::cout << "Enter 1 to continue the game\n";
				std::cout << "Enter 2 to stop the game\n";
				std::cin >> conOrStop;
				if (conOrStop != 2 && conOrStop != 1) {
					std::cout << "Invalid Input. Please enter a valid number\n";
				}
			} while (conOrStop != 2 && conOrStop != 1);

			if (conOrStop == 2) {
				std::cout << "The game is over\n";
				return 0;
			}
		}

		return 0;
	}
}