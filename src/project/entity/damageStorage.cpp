#include "damageStorage.hpp"

void damageStorage::addDamage(int damageAmount, int playerID){
	if (currentLength < 100){
		damageArray[currentLength] = Damage(damageAmount, playerID);
		currentLength++;
	}
}

Damage& damageStorage::getDamage(int index){
	return damageArray[index];
}