#include "entity/damageStorage.hpp"
#include "entity/Damage.hpp"
#include <hwlib.hpp>

int main()
{
	DamageStorage d;
	d.addDamage(10, 3);
    d.addDamage(5, 4);
    d.addDamage(6, 5);
    for (int i=0;i<3;i++){
    	Damage damageEntity = d.getDamage(i);
    	hwlib::cout << damageEntity.getDamageAmount();
        hwlib::cout << damageEntity.getPlayerID();
    }
}