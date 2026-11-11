CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
all: test_liste
test_liste: liste.o test_liste.o
    $(CC) $(CFLAGS) liste.o test_liste.o -o test_liste
liste.o: liste.c liste.h
    $(CC) $(CFLAGS) -c liste.c -o liste.o
test_liste.o: test_liste.c liste.h
    $(CC) $(CFLAGS) -c test_liste.c -o test_liste.o
test: test_liste
    ./test_liste
clean:
    rm -f *.o test_liste
