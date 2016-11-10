#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

SOURCES  := messageLogic.cpp keypad.cpp oled_controller.cpp playerID.cpp receiver.cpp speaker.cpp speakercontroller.cpp usb.cpp hitController.cpp keypadHandler.cpp receiverHandler.cpp shootCtrl.cpp transferController.cpp transmitterctrl.cpp damageStorage.cpp game.pb.c pb_common.c pb_decode.c pb_encode.c
# header files in this project

HEADERS := bitTools.hpp gunLogic.hpp messageLogic.hpp oled.hpp oled_controller.hpp keypad.hpp playerID.hpp receiver.hpp speaker.hpp speakercontroller.hpp transmitter.hpp usb.hpp hitController.hpp keypadHandler.hpp receiverHandler.hpp shootCtrl.hpp transferController.hpp transmitterctrl.hpp Damage.hpp damageStorage.hpp Player.hpp keypadListener.hpp receiverListener.hpp game.pb.h pb.h pb_common.h pb_decode.h pb_encode.h


# other places to look for files for this project
SEARCH  := boundary/ controllers/ interface/ applicationLogic/ entity/ interfaces/ nanopb/ drawables/ 

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
