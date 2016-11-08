#include "hitController.hpp"

HitController::HitController(Speakercontroller& sp,DamageStorage& ds,Receiver& rs,Player& play):
sp(sp),
ds(ds),
play(play)
{
    rs.addReceiverListener(this);
}