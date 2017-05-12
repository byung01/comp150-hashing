# Makefile
#
# Created by: Cecilie Uppard, Flora Liu, Bill Yung
#
# Used to compile the program that runs a hashtable with cuckoo hashing

CXX = clang++
CFLAGS = -g -Wall -Wextra

all: cuckoo_hashing clean

cuckoo_hashing: cuckoo.o hash_funcs.o cuckoo_main.o
	 ${CXX} ${CFLAGS} -o cuckoo_hashing cuckoo_main.o cuckoo.o hash_funcs.o

clean:
	rm -rf *.dSYM
	rm *.o

cuckoo_main.o: cuckoo_main.cpp
cuckoo.o: cuckoo.h cuckoo.cpp
hash_funcs.o: hash_funcs.h hash_funcs.cpp
