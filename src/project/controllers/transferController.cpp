///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#include "transferController.hpp"

TransferController::TransferController(DamageStorage & ds) :
ds(ds)
{}

void TransferController::run(rtos::task_base * task)
{
    do
    {
        while (!hwlib::cin.char_available())
        {
            task->sleep(10 * rtos::us);
        }
    } while (hwlib::cin.getc() != '\n');
    USB::writeToUSB(ds);
}
