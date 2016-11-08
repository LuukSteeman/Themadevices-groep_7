#include "hitController.hpp"
#include "gunLogic.hpp"
HitController::HitController(Speakercontroller &sp, DamageStorage &ds, Receiver &rs, Player &play) : sp(sp),
                                                                                                     hitchannel(this, "Channel for hits"),
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

        //check for not self
        int damage = getDamageAmount(message.getData());
        pl.updateHP(damage);
        // hwlib::cout << pl;
        ds.addDamage(damage, message.getId());
        sp.add(10);
    };
}