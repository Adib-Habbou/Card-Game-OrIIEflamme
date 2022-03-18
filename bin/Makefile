CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJETS = main.o carte.o faction.o plateau.o interface.o

oriieflamme : $(OBJETS)
	$(CC) -o $@ $^

%.o : %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf *.o