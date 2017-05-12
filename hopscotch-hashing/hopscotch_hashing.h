/*
 *  hopscotch_hashing.h
 *
 *  Authors: Bill Yung, Flora Liu, Cecilie Uppard
 *  Description: Interface for the implementation of a Circular HashTable
 */

#ifndef HOPSCOTCH_HASHING
#define HOPSCOTCH_HASHING

#include <iostream>

/* Defining the neighborhood length */
#define H 64

class Hopscotch_Hashtable {
private:
    struct Data {
        std::string word;
        int og_index;
    };

    Data *hash_table;
    int size;
    int capacity;
    
    /*
     *  Helper functions for insertion
     */
    void addToTable(Data d, int index);
    int findBlankSpot(int og_index);
    int searchNeighborhood(Data d, int blank_index);
    void swapSpots(int spot, int empty);
    bool isInNeighborhood(int og_index, int i);
    void expand();


    double times_expanded;
    double total_load_factor_percentage;

public:
    Hopscotch_Hashtable();
    ~Hopscotch_Hashtable();
    std::string search(std::string);
    void insert(std::string);
    void print();
};

#endif
