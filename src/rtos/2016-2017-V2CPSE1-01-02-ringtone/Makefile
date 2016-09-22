#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

Ringtone = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6"
#Ringtone = "generator/Star Wars - Force Theme.txt"

.PHONY: ringtone

ringtone: generator/ringtone.h
		
generator/ringtone.h: generator/generator2 Makefile
	./generator/generator2 $(Ringtone) > generator/ringtone.h

generator/generator2: generator/main2.cpp
	g++ -std=c++11 generator/main2.cpp -o generator/generator2
# source files in this project (main.cpp is automatically assumed)
SOURCES :=

# header files in this project
HEADERS := generator/ringtone.h

# other places to look for files for this project
SEARCH  := 

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
