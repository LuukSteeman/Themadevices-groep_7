#ifndef PLAYER_HPP
#define PLAYER_HPP

//! Player Entity Class

class Player
{
private:
	//! The amount of health the player has
	int hitPoints;

	//! The player's chosen weapon, which is used to calculate damage and rate of fire
	int weaponID;

    //! The player's unique ID
	int playerID;
public:
	//! An constuctor without parameters that initializes hitPoints at a value of 100
	Player(){hitPoints = 100;};
	
	//! Update the player's health by subtracting the amount of damage taken
	//! @param damage The amount of damage the player took
	void updateHP(int damage){hitPoints -= damage;};

	//! Returns the player's current hitPoints
	int getHP(){return hitPoints;};

	//! Set the player's weapon
	//! @param The weapon ID chosen on the keypad
	void setWeapon(int weapon){if (weapon >0 && weapon<10){weaponID = weapon;}};

	//! Returns the ID of the player's chosen weapon
	int getWeapon(){return weaponID;};

	//! Sets the player ID
    //! @param receivedID The ID the SetupController receives from the PlayerID class
	void setPlayerID(int receivedID){playerID = receivedID;};

    //! Returns the player ID
	int getPlayerID(){return playerID;};
};

#endif // PLAYER_HPP