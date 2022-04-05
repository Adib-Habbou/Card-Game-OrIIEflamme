CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJETS = obj/main.o obj/carte.o obj/faction.o obj/plateau.o obj/interface.o obj/structure.o

oriieflamme : $(OBJETS)
	$(CC) -o $@ $^

obj/%.o : src/%.c  headers/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

test.o : src/test.c
	$(CC) $(CFLAGS) -o $@ -c $<

test : $(OBJETS) obj/test.o
	$(CC) -o $@ $^ -lcunit
