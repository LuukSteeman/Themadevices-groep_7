#include <hwlib.hpp>
#include <rtos.hpp>

#include "entity/damageStorage.hpp"
#include "controllers/transferController.hpp"

class X : rtos::task<>
{
private:
  void main()
  {
    DamageStorage ds;

    ds.addDamage(10, 3);
    ds.addDamage(5, 4);
    ds.addDamage(6, 5);

    TransferController t(ds);
    t.run(this);
    while (1);
  }
};

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);
  X x;
  rtos::run();
  return 0;
}