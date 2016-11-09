///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#include "damageStorage.hpp"

void DamageStorage::addDamage(int damageAmount, int playerID)
{
    if (currentLength < 100)
    {
        damageArray[currentLength] = DamageEntity(damageAmount, playerID);
        currentLength++;
    }
}

DamageEntity& DamageStorage::getDamage(int index)
{
    return damageArray[index];
}
