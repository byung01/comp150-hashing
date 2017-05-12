#include "hash_funcs.h"

using namespace std;

unsigned long hash1(string word) {
    unsigned long hash = 0;

    for (int i = 0; i < (int)word.length(); i++) {
        hash = (hash * PRIME_A) ^ ((int)word[i] * PRIME_B);
    }

    return hash;
}

unsigned long hash2(string word) {
    unsigned long hash = 0;

    for (int i = 0; i < (int)word.length(); i++) {
        hash = (hash * PRIME_C) ^ ((int)word[i] * PRIME_D);
    }

    return hash;
}   
