#include <iostream>
#include "damageStorage.hpp"
#include "Damage.hpp"

int main()
{
	int length = 1;
	Damage TransferArray[length];
	damageStorage d;
	d.addDamage(10, 3);
	std::cout << d.getDamage(TransferArray*, 1);
	return 0;
}