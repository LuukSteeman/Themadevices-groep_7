///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#ifndef GUNLOGIC_HPP
#define GUNLOGIC_HPP

//! The application logic for calculating the damage and time between shots

//! Returns the delay between shots in ms
//! @param weaponID The ID of the weapon used to shoot
int calcShootDelay(int weaponID)
{
    return (weaponID * 200);
}

//! Returns the amount of damage the player took
//! @param weaponID The ID of the weapon used to shoot
int calcDamage(int weaponID)
{
    return (weaponID * 5);
}

#endif // GUNLOGIC_HPP
