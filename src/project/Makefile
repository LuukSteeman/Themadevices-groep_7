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
SOURCES := speaker.cpp speakercontroller.cpp receiver.cpp receiverHandler.cpp messageLogic.cpp damageStorage.cpp transmitterctrl.cpp 

# header files in this project
HEADERS := speaker.hpp speakercontroller.cpp receiver.hpp receiverListener.hpp messageLogic.hpp damageStorage.hpp transmitter.hpp transmitterctrl.hpp 

# other places to look for files for this project
SEARCH  := boundary/ controllers/ applicationLogic/ entity/ interfaces/ 

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
