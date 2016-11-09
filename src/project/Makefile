#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
#SOURCES := speaker.cpp speakercontroller.cpp receiver.cpp receiverHandler.cpp messageLogic.cpp damageStorage.cpp transmitterctrl.cpp transferController.cpp usb.cpp game.pb.c pb_encode.c pb_common.c hitController.cpp shootCtrl.cpp keypadHandler.cpp keypad.cpp
SOURCES  := messageLogic.cpp keypad.cpp playerID.cpp receiver.cpp speaker.cpp speakercontroller.cpp usb.cpp hitController.cpp keypadHandler.cpp receiverHandler.cpp shootCtrl.cpp transferController.cpp transmitterctrl.cpp damageStorage.cpp game.pb.c pb_common.c pb_decode.c pb_encode.c
# header files in this project
#HEADERS := speaker.hpp receiver.hpp receiverListener.hpp Damage.hpp messageLogic.hpp damageStorage.hpp transmitter.hpp transmitterctrl.hpp  transferController.hpp usb.hpp pb_common.h pb_encode.h game.pb.h pb.h Player.hpp hitController.hpp shootCtrl.hpp gunLogic.hpp keypadHandler.hpp keypad.hpp keypadListener.hpp

HEADERS := bitTools.hpp gunLogic.hpp messageLogic.hpp keypad.hpp playerID.hpp receiver.hpp speaker.hpp speakercontroller.hpp transmitter.hpp usb.hpp hitController.hpp keypadHandler.hpp receiverHandler.hpp shootCtrl.hpp transferController.hpp transmitterctrl.hpp Damage.hpp damageStorage.hpp Player.hpp keypadListener.hpp receiverListener.hpp game.pb.h pb.h pb_common.h pb_decode.h pb_encode.h

# other places to look for files for this project
SEARCH  := boundary/ controllers/ applicationLogic/ entity/ interfaces/ nanopb/

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
