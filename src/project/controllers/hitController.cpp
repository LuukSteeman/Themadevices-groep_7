#include "hitController.hpp"
HitController::HitController(Speakercontroller &sp, DamageStorage &ds, Receiver &rs, Player &play) : task((char *)"HitController"),
                                                                                                     hitchannel(this, "Channel for hits"),
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
        hwlib::cout << play.getPlayerID() << "," << message.getId() << "\n";
        if (play.getPlayerID() != message.getId())
        {
            int damage = GunLogic::calcDamage(message.getData());
            play.updateHP(1);
            hwlib::cout << damage;
            ds.addDamage(1, message.getId());
            sp.add(100);
        }
    }
    sp.set_frequency(2500);
    sp.add(5000);
}