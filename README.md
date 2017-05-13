# COMP 150 Final Project: Hashing Algorithms
## Collaborators: Cecilie Uppard, Flora Liu, Bill Yung

---

### Table of Contents:
1. Introduction
2. Hopscotch Hashing
3. Cuckoo Hashing
4. Testing Hopscotch and Cuckoo Performance
5. Results
6. Performance Analysis and Improvements
7. Further Reading

---
### 1. Introduction
What is hashing?
Hashmap
Hash Functions
Why are hashing algorithms important?

### 2. Hopscotch Hashing

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

### 3. Cuckoo Hashing

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

**Link to implementation:** [here](https://github.com/byung01/comp150-hashing/tree/master/cuckoo-hashing)

### 4. Testing Hopscotch and Cuckoo Performance

To find out whether hopscotch hashing or cuckoo hashing results in better performance, we ran tests to compare the space and time required for insertion and query for each algorithm. It is critical that a hash table can deliver the constant time peformance that we expect.

**Independent variables:** For testing, we ran the hopscotch and cuckoo algorithms over various sizes of inputs. In addition for hopscotch hashing, we also obtained results for H = 32 and H = 64 (H is the number of buckets in a neighborhood) because the range from 32 to 64 is the optimal range according to the original paper. 

**Controlled variables:** To ensure that our comparison is precise as possible, we used the same hash function for both the hopscotch and cuckoo algorithms. The input strings for each category were derived from an online source that originally contained 479K distinct words. In order to get more strings, we appended random characters to each original word to expand our list of inputs and make each input string distinct.

**Method:**
- For time comparison, we simply used a timer measuring in seconds.
- For space comparison, we wanted to know the table density. We calculated the load factor, which is *n / m* where *n* is the number of keys in the table and *m* is the table size. For accuracy, we decided to use the average load factor for each category of number of inputs. To accomplish this, we calculated the load factor before our table expanded and took the average over the number of expansions. For example, while inserting 10,000,000 inputs, our hopscotch hash table expanded 18 times with an average load factor of 88%. This average calculation will allow us to gain a more accurate representation of load factors and table densities in our analysis.

### 5. Results

**Insertion Times:**

| Number of inputs | Hopscotch (H = 32) | Hopscotch (H = 64) |     Cuckoo     |
|:----------------:|:------------------:|:------------------:|:--------------:|
| 100              | 0.00026 seconds    | 0.00026 seconds    | 0.00143 seconds|
| 1000             | 0.00209 seconds    | 0.00234 seconds    | 0.00605 seconds|
| 10,000           | 0.01854 seconds    | 0.01860 seconds    | 0.12808 seconds|
| 100,000          | 0.16238 seconds    | 0.16850 seconds    | 1.80150 seconds|
| 1,000,000        | 1.77407 seconds    | 1.96746 seconds    | 178.225 seconds|
| 10,000,000       | 17.9326 seconds    | 19.8266 seconds    | N/A            |

**Insertion Average Load Factors During Expansion:**

| Number of inputs | Hopscotch (H = 32) | Hopscotch (H = 64) | Cuckoo  |
|:----------------:|:------------------:|:------------------:|:-------:|
| 100              | 100.00%            | 100%               | 50.502% |
| 1000             | 96.372%            | 98.838%            | 30.482% |
| 10,000           | 96.481%            | 97.218%            | 20.945% |
| 100,000          | 94.217%            | 96.762%            | 20.393% |
| 1,000,000        | 89.286%            | 92.642%            | 16.784% |
| 10,000,000       | 88.277%            | 92.347%            | N/A     |

**Query Times:**

| Number of inputs | Hopscotch (H = 32) | Hopscotch (H = 64) |     Cuckoo     |
|:----------------:|:------------------:|:------------------:|:--------------:|
| 100              | 0.00015 seconds    | 0.00014 seconds    | 0.00015 seconds|
| 1000             | 0.00110 seconds    | 0.00151 seconds    | 0.00156 seconds|
| 10,000           | 0.00904 seconds    | 0.00917 seconds    | 0.01196 seconds|
| 100,000          | 0.09920 seconds    | 0.09714 seconds    | 0.12532 seconds|
| 1,000,000        | 0.98817 seconds    | 1.04526 seconds    | 1.13416 seconds|
| 10,000,000       | 11.9828 seconds    | 11.8209 seconds    | N/A            |

### 6. Performance Analysis and Improvements

**Observations for Insertion Times:** For both H = 32 and H = 64, the increase in insertion time for hopscotch hashing is linear (both the dataset and the time it took to insert increased by a factor of 10 each time). This performance is ideal, because there is no unreasonable increase in insertion time as inputs get exceptionally large. Hopscotch hashing with H = 32 takes less time than H = 64. H = 32 is faster, because the neighborhood is smaller, so we linear probe less and take less number of steps to get our value. 

**Observations for Insertion Average Load Factors During Expansion:** First of all, we were surprised by the average load factors resulting from our implementation of hopscotch hashing. For H = 32, the average load factor was 88% at 10 million inputs. For H = 64, the average load factor was 92% at 10 million inputs. This means that H = 64 allows more values to be added to our table with minimal expansions. The results from the average load factors proves that hashing via the hopscotch algorithm guarantees a higher table density. High table density is desirable for hash tables, as it ensures that the table is filled as much as possible before expanding. Thus, we waste less space and and operational time on expanding.

For the results of cuckoo hashing, we were disappointed to see that the load factor drastically decreases as the size of our inputs grow. 

**Observations for Query Times:** For hopscotch hashing, the query times also gave us expected behavior of linear time as we increased the dataset. For hopscotch hashing, H = 32 yields faster times than H = 64, because the neighborhood is smaller so we linear probe less for each search.

**Overall Conclusions:** We found that for hopscotch hashing, H = 32 is faster than H = 64 for each operation (insert and search). However, H = 64 provides a better load factor since our neighborhood has more buckets. Thus, there is a tradeoff between time and load factor for neighborhood size with hopscotch hashing.

**Improvements:** The results from these tests were only derived from our implementations, so it would be interesting to further this study by comparing our implementation of hopscotch and cuckoo with others' implementations (for example, using bitmap vs. linked list representations to represent neighborhoods). If we had more time, we would also compare our implementation of hashing algorithms to the C++ library's built-in hash structure. Furthermore, we would like to add a third table to our implementation of cuckoo hashing for performance analysis.

### 7. Further Reading

- Herlihy, Shavit and Tzafrir. ["Hopscotch Hashing"](http://people.csail.mit.edu/shanir/publications/disc2008_submission_98.pdf). Distributed Computing, 22nd International Symposium. September 24, 2008. Arachon, France.
- Pandiyan, Monteiro, and Hariesh. ["Hopscotch Hashing"](http://www.cs.nyu.edu/~lerner/spring11/proj_hopscotch.pdf). New York University. 
- Pagh and Rodler. ["Cuckoo Hashing"](http://resources.mpi-inf.mpg.de/departments/d1/teaching/ws14/AlgoDat/materials/cuckoo.pdf). BRICS, Department of Computer Science University of Aarhus. August 2001. Copenhagen, Denmark.

 