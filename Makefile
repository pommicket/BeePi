CC=gcc
default: beepi
beepi: main.c
	$(CC) -o beepi main.c
