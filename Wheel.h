#pragma once
#pragma once

class Wheel {
private:
	int range = 6;
	//add playerRoll to do comparison in the take_turn function
	int playerRoll = 0;
protected:
	float bet = 0;
public:
	Wheel() {};
	Wheel(int r);
	int spin();
	float take_turn(float wager);

	float getBet() { return bet; }
	int getRange() { return range; }
	int getPlayerRoll() { return playerRoll; }

	void setBet(float b) { bet = b; }
	void setRange(int r) { range = r; }

	//add a setter for playerRoll
	void setPlayerRoll(int proll) { playerRoll = proll; };
};
