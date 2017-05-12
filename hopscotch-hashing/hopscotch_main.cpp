/*
 *  hopscotch_hashing.h
 *
 *  Authors: Bill Yung, Flora Liu, Cecilie Uppard
 *  Description: Main function to run our version of the hopscotch hashtable
 */

#include "hopscotch_hashing.h"
#include <iostream>
#include <fstream>

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

    input.open(argv[1]);

    if (!input.is_open()) {
        cerr << "Unable to open file!" << endl;
        usage_abort();
    }

    while (input >> word) {
        hh.insert(word);
    }
    
    input.close();

    hh.print();

    return 0;
}
