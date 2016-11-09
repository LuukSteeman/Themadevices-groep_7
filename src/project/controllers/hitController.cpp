#include "hitController.hpp"
HitController::HitController(Speakercontroller &sp, DamageStorage &ds, Receiver &rs, Player &play) : hitchannel(this, "Channel for hits"),
                                                                                                     sp(sp),
                                                                                                     ds(ds),
                                                                                                     play(play)
{
    rs.addReceiverListener(this);
}

void HitController::msgReceived(MessageLogic msg)
{
    hitchannel.write(msg);
}

void HitController::main()
{
    while (1)
    {
        MessageLogic message = hitchannel.read();
        // if (play.getId() != message.getId())
        // {

            int damage = GunLogic::calcDamage(message.getData());
            play.updateHP(damage);
            hwlib::cout << play.getHP();
            ds.addDamage(damage, message.getId());
            sp.add(100);
        // }
    }
}