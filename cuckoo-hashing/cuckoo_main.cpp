/*
 *  hopscotch_hashing.h
 *
 *  Authors: Bill Yung, Flora Liu, Cecilie Uppard
 *  Description: Main function to run our version of the hopscotch hashtable
 */

#include "cuckoo.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void usage_abort() {
    cerr << "Aborted(): terminated!" << endl
         << "Usage: ./cuckoo_hashing [filepath]" << endl
         << "       where [filepath] is a valid path to a text file of strings" << endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage_abort();
    }
    
    Cuckoo c;
    string word;
    ifstream input;
    clock_t t1, t2;

    input.open(argv[1]);

    if (!input.is_open()) {
        cerr << "Unable to open file!" << endl;
        usage_abort();
    }

    t1 = clock();
    while (input >> word) {
        c.insert(word, 1, 0);
    }
    t1 = clock() - t1;
    input.close();


    input.open(argv[1]);
    t2 = clock();
    while (input >> word) {
        c.search(word);
    }
    t2 = clock() - t2;
    input.close();

    c.print();
    cout << "It took " << ((float)t1 / CLOCKS_PER_SEC) << " seconds for insertion" << endl;
    cout << "It took " << ((float)t2 / CLOCKS_PER_SEC) << " seconds for searching" << endl;


    return 0;
}
