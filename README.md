# COMP 150 Final Project: Hashing Algorithms
## Collaborators: Cecilie Uppard, Flora Liu, Bill Yung

---

### Table of Contents:
1. Hopscotch Hashing
2. Cuckoo Hashing
3. Comparison of Hopscotch and Cuckoo Performance
4. Performance Analysis and Improvements
5. Bibliography

---

### 1. Hopscotch Hashing

Hopscotch hashing is an alternative hashing algorithm originally proposed by Maurice Herlihy, Nir Shavit and Moran Tzafrir. A main advantage of hopscotch hashing is that this algorithm guarantees a small number of contiguous lookups as table density increases. For our project, we implemented the insert and search operations of hopscotch hashing. The delete operation was not implemented nor timed for analysis, because it follows a similar method as searching.

**How it works:** To resolve colllisions, hopscotch hashing uses open addressing and a reordering scheme. Each bucket in the hash data structure has a neighborhood of size H. The neighborhood of a bucket B is the bucket itself and the (H-1) following buckets after it. Hopscotch hashing ensures that data will always be found within the neighborhood of the original bucket it was hashed to. In the worst case, only H lookups are necessary to find an entry.

**Insertion:** 
1. Hash the value to get the hash key, which is used to determine the position (bucket B) which will be used to store the value in the hash table.
2. If B is empty, store the value in bucket B.
3. Else, linear probe for the next empty bucket.
4. If an empty bucket, E, is found in the neighborhood of B, store the value in E.
5. Else, search for an empty bucket within the neighborhood of B. This is done via a reordering sceheme of swapping bucket(s) that exist between B and E. Start by looking for a bucket from the (H-1) buckets preceding E that includes E in their neighborhoods. 
6. If a bucket T is found, swap E and T. Repeat step 5 until the next T is in the neighborhood of B.

**Query:**
1. Hash the value to retrieve the bucket B.
2. Starting from B, scan through the next (H-1) buckets to look for the value.

**Link to implementation:** [here](https://github.com/byung01/comp150-hashing/tree/master/hopscotch-hashing)

### 2. Cuckoo Hashing

Cuckoo hashing is another alternative hashing algorithm first described by Rasmus Pagh and Flemming Friche Rodler in 2001. The most significant advantage of the algorithm is that it ensures constant lookup time amortized. For our project, we implemented the insert and search operations of hopscotch hashing. The delete operation was also not implemented nor timed for analysis.

**How it works:** 
To resolve colllisions, cuckoo hashing uses open addressing in two tables. Each key will hash to one position in each table, using two different hashing functions. In the case of a collision, the algorithm evicts the already placed key and replaces it in its second location. This method repeats until all keys are placed in open cells. The method might result in an infinite loop, in the case that keys keep hashing to already occupied cells. Therefore, a maximum number of recursions is set, and when it is reached the tables are expanded and all keys are rehashed. 

**Insertion:** 
1. Hash a key, A, to the first position in the first table
2. If the cell is unoccupied, place the A in cell.
3. Else, evict the occupying key, B, place A in cell, and hash B to its second location in the second table

**Query:**
1. Hash a word
2. If not found in cell, hash key with second hashing function, to look in second table

**Link to implementation:** [here](https://github.com/byung01/comp150-hashing/tree/master/cuckoo_hashing)

### 3. Comparison of Hopscotch and Cuckoo Performance

To find out whether hopscotch hashing or cuckoo hashing results in better performance, we ran tests to compare the space and time required for insertion and query for each algorithm. It is critical that a hash table can deliver the constant time peformance. So for time comparison, we simply used a timer measured in miliseconds. For space comparison, we calculated the load factor, which is *n / m* where *n* is the number of keys in the table and *m* is the table size.

**Insertion:**

| Number of input    |     Time            |   Space   |
| ------------------ |:-------------------:| ---------:|
|                    | Hopscotch | Cuckoo  |           |
|                    | --------- | ------- |           |                    
|      1000          |     0.5   |   0.5   |           |
|      10000         |     1.0   |   1.0   |           |
|      100000        |     1.5   |   1.5   |           |                    
|      10000000      |     2.0   |   2.0   |           |

**Query:**

| Number of input    |   Hopscotch   |   Cuckoo  |
| ------------------ |:-------------:| ---------:|
|                    |               |           |
|                    |               |           |                    
|                    |               |           |
|                    |               |           |
|                    |               |           |                    
|                    |               |           |

### 4. Performance Analysis and Improvements

### 5. Bibliography

- Herlihy, Shavit and Tzafrir. "Hopscotch Hashing". 2008. 
