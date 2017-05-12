//
// Cuckoo hashing implementation
// COMP150 
//

#include "cuckoo.h"
#include "hash_funcs.h"

#define MAXELEM 1
#define NUMHASH 2
#define MAXREC 15

Cuckoo::Cuckoo() {

	size = MAXELEM;
	maxrec = MAXREC;

	hashTable = new string*[NUMHASH];

	for (int i = 0; i < NUMHASH; i++) {
		hashTable[i] = new string[size];
	}

    for (int i = 0; i < NUMHASH; i++)
        for (int j = 0; j < size; j++)
            hashTable[i][j] = "";
}

Cuckoo::~Cuckoo() {

	for (int i = 0; i < NUMHASH; i++) {
        delete [] hashTable[i];
	}

    delete [] hashTable;
}


void Cuckoo::insert(string key, int tablenum, int rec) {

	// unsuccessful insertion, rehash
	if (rec == maxrec) {
		expand();
		return;
	}

	unsigned long hash_key;

	switch (tablenum) {

		case 1: hash_key =  hash2(key);
		case 2: hash_key =  hash1(key);
	}

	int index = hash_key % size;

	// check if key is already in table
	if (hashTable[tablenum - 1][index] == key) return;

	// insert into table
	if (hashTable[tablenum - 1][index] != "") {
		// save evicted key
		string evicted = hashTable[tablenum - 1][index];
		// place new key in cell
		hashTable[tablenum - 1][index] = key;
		int newtablenum;
		(tablenum == 1) ? newtablenum = 2 : newtablenum = 1;
		insert(evicted, newtablenum, rec + 1);
	}
	else {
		hashTable[tablenum - 1][index] = key;
	}
}

string Cuckoo::search(string key) {

	unsigned long hash_key; 
	int index;

	hash_key = hash2(key);
	index = hash_key % size;

	if(hashTable[1][index] == key) {
		return key;
	}
	else {
		hash_key = hash1(key);
		index = hash_key % size;
		if (hashTable[0][index] == key) {
			return key;
		}
		else {
			return "";
		}
	}
}

void Cuckoo::expand() {

    string **old_hash_table = hashTable;
    size *= 2;
    hashTable = new string*[NUMHASH];

	for (int i = 0; i < NUMHASH; i++) {
		hashTable[i] = new string[size];
	}

	// init all cells
    for (int i = 0; i < NUMHASH; i++) {
        for (int j = 0; j < size; j++) {
            hashTable[i][j] = "";
        }
    }

    // rehash
    for (int i = 0; i < NUMHASH; i++) {
        for (int j = 0; j < (size/2); j++) {
        	if (old_hash_table[i][j] != "") {
        		//cout << old_hash_table[i][j] << "\n";
            	insert(old_hash_table[i][j], 1, 0);
        	}
        }
    }

    for (int i = 0; i < NUMHASH; i++) {
        delete [] old_hash_table[i];
    }

    delete [] old_hash_table;


}

void Cuckoo::print() {
	cout << "Table:" << endl;

	for (int i = 0; i < NUMHASH; i++) {
		for (int j = 0; j < size; j++) {
			(hashTable[i][j] == "") ?
				cout << " - ":
				cout << " " << hashTable[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}






