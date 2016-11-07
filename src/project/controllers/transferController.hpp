#include "../entity/damageStorage.hpp"
#include "rtos.hpp"
#include "transferController.hpp"
#include "hwlib.hpp"
#include "../boundry/usb.hpp"

class TransferController
{
  public:
    TransferController(DamageStorage &ds) : ds(ds);
    template <typename T>
    void run(rtos::task<T> task)
    {
        while (hwlib::cin.getc() != '\n'){
            task.sleep(10);
        }
        USB::writeToUSB(ds);
    };

  private:
    DamageStorage &ds;
};