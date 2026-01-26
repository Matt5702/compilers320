#**************************************
# Makefile
#
# Makefile for lab3 calc compiler
#
# Author: Generated Makefile
#
# Date: Jan. 25, 2026
#

COPTS=-Wall -g -c -O0 -std=c++11
OBJS=main.o \
	 parse.o \
	 utils.o \
	 calclex.o

all: calc

clean:
	rm -f $(OBJS)
	rm -f *.o
	rm -f calclex.c
	rm -f calc
	rm -f out.xml
	rm -f out2.xml

.c.o:
	g++ $(COPTS) $? -o $@

.cpp.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp lex.h parse.h
	g++ $(COPTS) main.cpp -o main.o

parse.o: parse.cpp parse.h lex.h utils.h
	g++ $(COPTS) parse.cpp -o parse.o

utils.o: utils.cpp utils.h lex.h
	g++ $(COPTS) utils.cpp -o utils.o

calclex.c: calc.l
	flex -o calclex.c calc.l

calclex.o: calclex.c
	g++ $(COPTS) -Wno-sign-compare calclex.c -o calclex.o

calc: $(OBJS)
	g++ $(OBJS) -o calc
