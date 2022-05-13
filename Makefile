CC = gcc `sdl2-config --cflags --libs`
CFLAGS = -Wall -Wextra -std=c99 
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_ttf
OBJETS = obj/sdl.o obj/interface.o obj/carte.o obj/faction.o obj/plateau.o obj/structure.o obj/pile.o obj/list_dynamic.o obj/main.o

bin/oriieflamme : $(OBJETS)
	$(CC) $^ $(LDFLAGS) -L. -o $@ 

obj/%.o : src/%.c  headers/%.h
	$(CC) $(CFLAGS) -o $@ -c $<

test.o : src/test.c
	$(CC) $(CFLAGS) -o $@ -c $<

test : $(OBJETS) obj/test.o
	$(CC) -o $@ $^ -lcunit

clean:
	rm -rf obj/*.o

.PHONY : clean
