/*
 *  hopscotch_hashing.h
 *
 *  Authors: Bill Yung, Flora Liu, Cecilie Uppard
 *  Description: Main function to run our version of the hopscotch hashtable
 */

#include "hopscotch_hashing.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void usage_abort() {
    cerr << "Aborted(): terminated!" << endl
         << "Usage: ./hopscotch_hashing [filepath]" << endl
         << "       where [filepath] is a valid path to a text file of strings" << endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage_abort();
    }
    
    Hopscotch_Hashtable hh;
    string word;
    ifstream input;
    clock_t t1, t2;

    input.open(argv[1]);

    if (!input.is_open()) {
        cerr << "Unable to open file!" << endl;
        usage_abort();
    }

    /* Timing insertion for hopscotch hashing */
    t1 = clock();
    while (input >> word) {
        hh.insert(word);
    }
    t1 = clock() - t1;
    input.close();

    /* Timing searching for hopscotch hashing */
    input.open(argv[1]);
    t2 = clock();
    while (input >> word) {
        hh.search(word);
    }
    t2 = clock() - t2;
    input.close();

    hh.print();
    cout << "It took " << ((float)t1 / CLOCKS_PER_SEC) << " seconds for insertion" << endl;
    cout << "It took " << ((float)t2 / CLOCKS_PER_SEC) << " seconds for searching" << endl;


    return 0;
}
