CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJETS = plateau.o faction.o interface.o carte.o main.o

oriieflamme : $(OBJETS)
	$(CC) -o $@ $^

%.o : %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf *.o