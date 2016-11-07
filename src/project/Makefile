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
SOURCES := controllers/oled_controller.cpp drawables/text.cpp

# header files in this project
HEADERS := controllers/oled_controller.hpp interface/gui.hpp drawables/text.hpp boundary/oled.hpp

# other places to look for files for this project
SEARCH  := 

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
