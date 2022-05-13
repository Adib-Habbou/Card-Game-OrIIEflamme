CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -gstabs
OBJETS = obj/main.o obj/carte.o obj/faction.o obj/plateau.o obj/interface.o obj/structure.o

bin/oriieflamme : $(OBJETS)
	$(CC) -pg -o $@ $^

obj/%.o : src/%.c  headers/%.h
	$(CC) $(CFLAGS) -pg -o $@ -c $<

obj/test.o : src/test.c
	$(CC) $(CFLAGS) -o $@ -c $<

test : $(OBJETS) obj/test.o
	$(CC) -o $@ $^ -lcunit

clean:
	rm -rf obj/*.o
