#ifndef SHOOTCTRL_HPP
#define SHOOTCTRL_HPP

#include "keypadListener.hpp"
#include "rtos.hpp"
#include "transmitterctrl.hpp"

class shootctrl : public keypadListener
{
private:
    transmitterctrl & trans;
    char button;
public:
    shootctrl(transmitterctrl & trans);
    run();
}

#endif //SHOOTCTRL_HPP