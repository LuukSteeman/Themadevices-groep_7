#ifndef DAMAGESTORAGE_HPP
#define DAMAGESTORAGE_HPP
#include "Damage.hpp"

//! Damage Storage Class

class damageStorage
{
private:
	//! An integer that keeps track of how many objects are stored in the array
	int currentLength = 0;
	
	//! An array that can contain up to 100 Damage objects, since the player can never take more than 100 hits before dying
	Damage damageArray[100];
public:
	//! Called when a player takes damage. Creates a Damage object and puts it in the damageArray
	void addDamage(int damageAmount, int playerID);
	
	//! Given array is filled with Damage Objects from the damageStorage
	/*! Function is given the pointer to the start of the TransferArray.
	 *  Loops through [Length] amount of times copying objects from the damageStorage array to the TransferArray
	 *  Length may never be greater than currentLength since there will be no valid data in those indexes
	 */
	void getDamage(Damage *TransferArray, int Length);
	
};

#endif // DAMAGESTORAGE_HPP
