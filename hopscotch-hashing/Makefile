# Makefile
#
# Created by: Cecilie Uppard, Flora Liu, Bill Yung
#
# Used to compile the program that runs a hashtable with hopscotch hashing

CXX = clang++
CFLAGS = -g -Wall -Wextra

all: hopscotch_hashing clean

hopscotch_hashing: hopscotch_hashing.o hash_funcs.o hopscotch_main.o
	${CXX} ${CFLAGS} -o hopscotch_hashing hopscotch_main.o \
		hopscotch_hashing.o hash_funcs.o

clean:
	rm -rf *.dSYM
	rm *.o

hopscotch_main.o: hopscotch_main.cpp
hopscotch_hashing.o: hopscotch_hashing.h hopscotch_hashing.cpp
hash_funcs.o: hash_funcs.h hash_funcs.cpp
