/*
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/entity/damageStorage.hpp:16: warning: argument 'The' of command @param is not found in the argument list of DamageStorage::addDamage(int damageAmount, int playerID)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/entity/damageStorage.hpp:16: warning: argument 'the' of command @param is not found in the argument list of DamageStorage::addDamage(int damageAmount, int playerID)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/entity/damageStorage.hpp:19: warning: The following parameters of DamageStorage::addDamage(int damageAmount, int playerID) are not documented:
  parameter 'damageAmount'
  parameter 'playerID'
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/entity/damageStorage.hpp:21: warning: argument 'The' of command @param is not found in the argument list of DamageStorage::getDamage(int index)
/home/Robert/SCHOOL/2015-2016/Themadevices-groep_7/src/project/entity/damageStorage.hpp:23: warning: The following parameters of DamageStorage::getDamage(int index) are not documented:
  parameter 'index'
*/

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
	Damage damageArray[100];
public:
	//! Called when a player takes damage. Creates a Damage object and puts it in the damageArray
	//! @param The amount of damage the player took
	//! @param the playerID of the shooter
	void addDamage(int damageAmount, int playerID);
	
	//! Returns a reference to a Damage object
	//! @param The index of the Damage object you want to return
	Damage& getDamage(int index);
};

#endif // DAMAGESTORAGE_HPP
