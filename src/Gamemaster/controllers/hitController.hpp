#include <hwlib.hpp>
#include <rtos.hpp>
#include "messageLogic.hpp"
#include "speakercontroller.hpp"
#include "receiverListener.hpp"
#include "Player.hpp"
#include "receiver.hpp"
#include "damageStorage.hpp"
#include "gunLogic.hpp"

class HitController : public rtos::task<>, public ReceiverListener
{
public:
    HitController(Speakercontroller& sp,DamageStorage& ds,Receiver& rs,Player& play);
    void msgReceived(MessageLogic msg);
    void main();
    rtos::channel<MessageLogic, 1> hitchannel;
private:
    Speakercontroller& sp;
    DamageStorage& ds;
    Player& play;
};