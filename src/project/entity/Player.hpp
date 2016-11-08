#ifndef PLAYER_HPP
#define PLAYER_HPP

//! Player Entity Class

class Player
{
private:
	//! The amount of health the player has, starting at 100
	int hitPoints;

	//! The player's chosen weapon, which is used to calculate damage and rate of fire
	int weaponID;
public:
	//! An constuctor without parameters that initializes hitPoints at a value of 100
	Player(){hitPoints = 100;};
	
	//! Update the player's health by subtracting the amount of damage taken
	//! @param damage The amount of damage the player took
	void updateHP(int damage){hitPoints -= damage;};

	//! Set the player's weapon
	//! @param The weapon ID chosen on the keypad
	void setWeapon(int weapon){weaponID = weapon;};

	//! Returns the ID of the player's chosen weapon
	int getWeapon(){return weaponID;};
};

#endif // PLAYER_HPP