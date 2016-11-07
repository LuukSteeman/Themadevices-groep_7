#include "damageStorage.hpp"

void DamageStorage::addDamage(int damageAmount, int playerID){
	if (currentLength < 100){
		damageArray[currentLength] = Damage(damageAmount, playerID);
		currentLength++;
	}
}

Damage& DamageStorage::getDamage(int index){
	return damageArray[index];
}