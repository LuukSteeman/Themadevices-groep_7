#pragma once
#include "../entity/damageStorage.hpp"
#include "rtos.hpp"
#include "transferController.hpp"
#include "hwlib.hpp"
#include "../boundary/usb.hpp"

/*
    Transfer controller can be run by running run and giving it a task
*/
class TransferController
{
  public:
    /**
    Create a transfer controller
    @param ds Reference to damage storige which should be transfered
    */
    TransferController(DamageStorage &ds) : ds(ds){};

    /**
        Run the transfer controller.
        This waits for a '\n'to be received and then sends data over serial
        @param task The task in which this controller is run.
    */
    void run(rtos::task_base *task)
    {
        do
        {
            while (!hwlib::cin.char_available())
            {
                task->sleep(10 * rtos::us);
            }
        } while (hwlib::cin.getc() != '\n');
        USB::writeToUSB(ds);
    };

  private:
    DamageStorage &ds;
};