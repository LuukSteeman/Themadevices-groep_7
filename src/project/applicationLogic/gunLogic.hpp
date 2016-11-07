#ifndef GUNLOGIC_HPP
#define GUNLOGIC_HPP

//! The application logic for calculating the damage and time between shots

//! Returns the delay between shots in ms
int calcShootDelay(int weaponID){
	return (weaponID * 200);
}

//! Returns the amount of damage the player took
int calcDamage(int weaponID){
	return (weaponID * 5);
}

#endif // GUNLOGIC_HPP
