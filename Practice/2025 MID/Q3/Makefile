CC = gcc
CFLAGS = -Wall -std=c11

all: temperature_converter

temperature_converter: main.o convert.o
	$(CC) $(CFLAGS) -o temperature_converter main.o convert.o

main.o: main.c temperature.h
	$(CC) $(CFLAGS) -c main.c
	
convert.o: convert.c temperature.h
	$(CC) $(CFLAGS) -c convert.c
	
clear:
	rm -f *.o temperature_converter
