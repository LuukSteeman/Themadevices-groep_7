#include <hwlib.hpp>
#include <rtos.hpp>

#include "entity/damageStorage.hpp"

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  DamageStorage ds;

  ds.addDamage(10, 3);
  ds.addDamage(5, 4);
  ds.addDamage(6, 5);

  
  return 0;
}