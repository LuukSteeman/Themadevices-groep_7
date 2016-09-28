#include "IRSend.hpp"

IRSend::IRSend(){
    ir = hwlib::target::d2_36kHz();
}

void IRSend::sendBit(bool bit){
    ir.set(true);
    sleep(bit?1600 US : 800US);
    ir.set(false);
    sleep(bit?800 US : 1600US);
};