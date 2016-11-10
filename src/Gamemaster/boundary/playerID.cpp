#include "playerID.hpp"
#include <hwlib.hpp>
namespace target = hwlib::target;

int PlayerID::getID()
{
    //create input pins
    auto out0 = target::pin_oc(target::pins::d42);
    auto out1 = target::pin_oc(target::pins::d43);
    auto out2 = target::pin_oc(target::pins::d44);
    auto out3 = target::pin_oc(target::pins::d45);
    auto out4 = target::pin_oc(target::pins::d46);
    auto out5 = target::pin_oc(target::pins::d47);
    auto out6 = target::pin_oc(target::pins::d48);

    //create output pins
    auto in0 = target::pin_in(target::pins::d49);
    auto in1 = target::pin_in(target::pins::d50);
    auto in2 = target::pin_in(target::pins::d51);
    auto in3 = target::pin_in(target::pins::d52);
    auto in4 = target::pin_in(target::pins::d53);


    auto out_port = hwlib::port_oc_from_pins(out0, out1, out2, out3, out4, out5, out6);
    auto in_port = hwlib::port_in_from_pins(in0, in1, in2, in3, in4);
    auto matrix = hwlib::matrix_of_switches(out_port, in_port);

    //loop trough all possible pin configurations and return id
    for (int x = 0; x < 7; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (matrix.switch_is_closed_at(x, y))
            {
                return (x + 1 + (y * 7));
            }
        }
    }
    //no id found return 0
    return 0;
}