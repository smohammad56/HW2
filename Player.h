#pragma once
#include <string>

class Player {
private:
	float curr_money;

public:
	Player() { curr_money = 100; }
	Player(float m) { curr_money = m; }
	float getMoney() { return curr_money; }
	void setMoney(float m) { curr_money = m; }
	void addMoney(float m) { curr_money -= m; }
	bool isBankrupt() { return curr_money <= 0; }
	std::string to_string() { return "You currently have a balance of: $" + std::to_string(curr_money) + "\n"; }
};
