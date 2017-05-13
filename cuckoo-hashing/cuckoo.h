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
	int capacity;
	int maxrec;
	int times_expanded;
	double total_load_factor_percentage;
	void insertKey(string key, int tablenum, int rec);
};

