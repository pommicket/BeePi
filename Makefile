CC=gcc
CFLAGS=-lm
default: beepi
beepi: main.c
	$(CC) $(CFLAGS) -o beepi main.c
