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
SOURCES := transmitterctrl.cpp IRMessage.cpp

# header files in this project
HEADERS := transmitter.hpp transmitterctrl.hpp IRMessage.hpp

# other places to look for files for this project
SEARCH  := boundary/ controllers/ applicationLogic/ entity/

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
