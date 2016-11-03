#ifndef DAMAGE_HPP
#define DAMAGE_HPP

//! Damage Entity Class

class Damage
{
private:
	//! The amount of damage the player took based on the shooter's weapon
	int damageAmount;
	
	//! The ID of the shooter
	int playerID;
public:
	//! Creates a Damage object with the given parameters
	Damage(int damageAmount, int playerID):damageAmount(damageAmount), playerID(playerID){};
	
	//! Returns the damageAmount
	int getDamageAmount(){return damageAmount;};
	
	//! Returns the playerID
	int getPlayerID(){return playerID;};
};

#endif // DAMAGE_HPP