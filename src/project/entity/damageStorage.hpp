#ifndef DAMAGESTORAGE_HPP
#define DAMAGESTORAGE_HPP
#include "Damage.hpp"

//! Damage Storage Class

class DamageStorage
{
private:
	//! An integer that keeps track of how many objects are stored in the array
	int currentLength = 0;
	
	//! An array that can contain up to 100 Damage objects, since the player can never take more than 100 hits before dying
	DamageEntity damageArray[100];
public:
	//! Called when a player takes damage. Creates a Damage object and puts it in the damageArray
	//! @param The amount of damage the player took
	//! @param the playerID of the shooter
	void addDamage(int damageAmount, int playerID);
	
	//! Returns a reference to a Damage object
	//! @param The index of the Damage object you want to return
	DamageEntity& getDamage(int index);
};

#endif // DAMAGESTORAGE_HPP
