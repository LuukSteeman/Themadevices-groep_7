#pragma once
#include "../entity/damageStorage.hpp"
#include "rtos.hpp"
#include "transferController.hpp"
#include "hwlib.hpp"
#include "../boundary/usb.hpp"

class TransferController
{
  public:
    TransferController(DamageStorage &ds) : ds(ds){};
    void run(rtos::task_base* task)
    {
        while (hwlib::cin.getc() != '\n'){
            task->sleep(10);
        }
        USB::writeToUSB(ds);
    };

  private:
    DamageStorage &ds;
};