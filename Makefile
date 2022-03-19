CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJETS = main.o

oriieflamme : $(OBJETS)
	$(CC) -o $@ $^

main.o : main.c carte.h faction.h interface.h plateau.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf *.o