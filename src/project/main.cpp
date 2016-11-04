#include "entity/damageStorage.hpp"
#include "entity/Damage.hpp"

int main()
{
	int length = 1;
	Damage TransferArray[length];
	damageStorage d;
	d.addDamage(10, 3);
	d.getDamage(&TransferArray, 1);
	return 0;
}