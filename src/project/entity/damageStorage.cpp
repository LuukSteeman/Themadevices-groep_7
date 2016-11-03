#include "damageStorage.hpp"


void damageStorage::addDamage(int damageAmount, int playerID){
	if (currentLength < 100){
		damageArray[currentLength] = Damage(damageAmount, playerID);
		currentLength++;
	}
}

void damageStorage::getDamage(Damage* TransferArray, int Length){
	if(Length<=currentLength){
		for(int i=0;i<Length;i++, TransferArray++){
			*TransferArray = damageArray[i];
		}
	}
}