#include "hitController.hpp"
#include "gunLogic.hpp"
HitController::HitController(Speakercontroller &sp, DamageStorage &ds, Receiver &rs, Player &play) : hitchannel(this, "Channel for hits"),
                                                                                                     sp(sp),
                                                                                                     ds(ds),
                                                                                                     play(play)
{
    // rs.addReceiverListener(this);
}

void HitController::msgReceived(MessageLogic msg)
{
    // sp.add(10);
    // hitchannel.write(msg);
}

void HitController::main()
{
    while (1)
    {
        // hitchannel.read();
        //check for not self
        // int damage = getDamageAmount(message.getData());
        // pl.updateHP(damage);
        // // hwlib::cout << pl;
        // ds.addDamage(damage, message.getId());
        sleep(100000000);
    };
}