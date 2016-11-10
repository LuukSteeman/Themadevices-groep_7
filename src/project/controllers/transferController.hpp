#pragma once
#include "../entity/damageStorage.hpp"
#include "rtos.hpp"
#include "transferController.hpp"
#include "hwlib.hpp"
#include "../boundary/usb.hpp"
#include "../interfaces/keypadListener.hpp"

/*
    Transfer controller can be run by running run and giving it a task
*/
class TransferController : public rtos::task<>, public KeypadListener
{

  private:
  DamageStorage &ds;
  rtos::flag startTransfer;
   /**
        Run the transfer controller.
        This waits for a '\n'to be received and then sends data over serial
    */
    void main()
    {
        wait(startTransfer);
        do
        {
            while (!hwlib::cin.char_available())
            {
                sleep(10 * rtos::us);
            }
        } while (hwlib::cin.getc() != '\n');
        USB::writeToUSB(ds);
        suspend();
    };
  public:
    /**
    Create a transfer controller
    @param ds Reference to damage storige which should be transfered
    */
    TransferController(DamageStorage &ds) : task((char*)"transferController"),ds(ds),startTransfer(this){};

    void keyPressed(char key){
        if(key == 'D'){
            hwlib::cout << " wanting to transfer ";
            startTransfer.set();
        }
    }
    
};