//
// Cuckoo hashing implementation
// COMP150 
//

#include <stdio.h>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

class Cuckoo {
public:
	Cuckoo();
	~Cuckoo();
	void insert(string key, int tablenum, int rec);
	string search(string key);
	void expand();
	void print();

private:
	string **hashTable;
	int size;
	int maxrec;
};

