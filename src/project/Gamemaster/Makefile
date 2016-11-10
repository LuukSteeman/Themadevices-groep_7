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
SOURCES  := messageLogic.cpp keypad.cpp keypadHandler.cpp transmitterctrl.cpp gamemasterctrl.cpp
# header files in this project

HEADERS := bitTools.hpp messageLogic.hpp keypad.hpp transmitter.hpp keypadHandler.hpp transmitterctrl.hpp keypadListener.hpp gamemasterctrl.hpp

# other places to look for files for this project
SEARCH  := ../boundary/ ../controllers/ ../applicationLogic/ ../entity/ ../interfaces/ ../nanopb/

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../../
include $(BMPTK)Makefile.due
