
CC=gcc
CFLAGS=-c -Wall -D_REENTRANT $(ADDITIONALFLAGS)
ULFIUS_LOCATION=../../src
LIBS=-lc -lulfius -lyder -lorcania -ljansson -L$(ULFIUS_LOCATION)

all: flwdREST

clean:
	rm -f *.o flwdREST

debug: ADDITIONALFLAGS=-DDEBUG -g -O0

debug: flwdREST

libulfius.so:
	cd $(ULFIUS_LOCATION) && $(MAKE) debug

flwdREST.o: flwdREST.c
	$(CC) $(CFLAGS) flwdREST.c -DDEBUG -g -O0

flwdREST: libulfius.so flwdREST.o
	$(CC) -o flwdREST flwdREST.o $(LIBS)

test: flwdREST
	LD_LIBRARY_PATH=$(ULFIUS_LOCATION):${LD_LIBRARY_PATH} ./flwdREST
