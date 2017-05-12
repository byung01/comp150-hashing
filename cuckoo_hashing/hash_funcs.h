/*
 *  hash_funcs.h
 *  
 *  Names: Cecilie Uppard, Flora Liu, Bill Yung
 *  Purpose: Implemented our own hash function to to minimize the collisions
 *
 */

#ifndef HASH_FUNCS
#define HASH_FUNCS

#include <iostream>

#define PRIME_A 1627
#define PRIME_B 28921
#define PRIME_C 2473
#define PRIME_D 47653

unsigned long hash1(std::string);
unsigned long hash2(std::string);

#endif
