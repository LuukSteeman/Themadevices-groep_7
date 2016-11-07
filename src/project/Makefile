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
SOURCES := boundary/speaker.cpp boundary/speakercontroller.cpp boundary/receiver.cpp controllers/receiverHandler.cpp entity/damageStorage.cpp nanopb/pb_common.c nanopb/pb_decode.c nanopb/pb_encode.c nanopb/game.pb.c boundary/usb.cpp controllers/transferController.cpp

# header files in this project
HEADERS := boundary/speaker.hpp boundary/speakercontroller.cpp boundary/receiver.hpp interfaces/receiverListener.hpp entity/Damage.hpp entity/damageStorage.hpp pb_common.h pb_decode.h pb_encode.h game.pb.h pb.h boundary/usb.hpp controllers/transferController.hpp

# other places to look for files for this project
SEARCH  := nanopb/

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
