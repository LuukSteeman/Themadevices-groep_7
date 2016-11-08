#include <hwlib.hpp>
#include <rtos.hpp>
#include "messageLogic.hpp"
#include "speakercontroller.hpp"
#include "damageStorage.hpp"
#include "receiverListener.hpp"
#include "gunLogic.hpp"
#include "Player.hpp"


class HitController : public rtos::task<>, public ReceiverListener
{
public:
    HitController(Speakercontroller& sp,DamageStorage& ds,Receiver& rs,Player& play);
    void msgReceived(MessageLogic msg);
private:
    Speakercontroller& sp;
    DamageStorage& ds;
    Player& play;
};