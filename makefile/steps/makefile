# IDIR=../include
CC=gcc
CFLAGS=-I ../include
SRC=src
ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: ./m.c ../include/hellofunc.h
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: ./obj/*.o
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ 