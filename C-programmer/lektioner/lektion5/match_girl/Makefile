# Variabler (makroer)
CC = gcc
CFLAGS = -ansi -pedantic -Wall -O

# Det endelige program
match-girl: match-girl.c char-graphics.o char-graphics.h
	$(CC) $(CFLAGS) match-girl.c char-graphics.o -o match-girl

# Hvordan man laver objektfilen
char-graphics.o: char-graphics.c char-graphics.h
	$(CC) $(CFLAGS) -c char-graphics.c

# Ryd op
clean:
	rm -f *.o match-girl
