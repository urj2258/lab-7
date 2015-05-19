#Makefile for memoryLeak
#
#Used to make the memoryLeak program used for Lab 08 of CSCE155E/251k
#Created by Tony Schneider on 2/17/2012
#Last Modified by Tony Schneider on 2/17/2012

CC = gcc
CCFLAGS = -lm -Iinclude
all: memLeak

memLeak: memLeak.o ithOrder.o
	$(CC) $(CCFLAGS) obj/memLeak.o obj/ithOrder.o -o memLeak

memLeak.o: src/memLeak.c 
	@mkdir -p obj
	$(CC) $(CCFLAGS) -c src/memLeak.c -o obj/$@

ithOrder.o: src/ithOrder.c include/ithOrder.h
	@mkdir -p obj
	$(CC) $(CCFLAGS) -c src/ithOrder.c -o obj/$@

clean:
	rm -rf obj/*o memLeak