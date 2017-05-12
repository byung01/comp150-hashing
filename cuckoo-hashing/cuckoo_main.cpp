#include "cuckoo.h"
#include <iostream>
#include <fstream>

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


    input.open(argv[1]);

    if (!input.is_open()) {
        cerr << "Unable to open file!" << endl;
        usage_abort();
    }

    while (input >> word) {
        c.insert(word, 1, 0);
    }
    
    input.close();
    
    c.print();

    return 0;
}

