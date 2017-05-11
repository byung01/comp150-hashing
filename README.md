# COMP 150 Final Project: Hashing Algorithms
## Collaborators: Cecilie Uppard, Flora Liu, Bill Yung

### Hopscotch Hashing

Hopscotch hashing is an alternative hashing algorithm originally proposed by Maurice Herlihy, Nir Shavit and Moran Tzafrir. A main advantage of hopscotch hashing is that this algorithm guarantees a small number of continguous lookups as table density increases. For our project, we implemented the insert and search operations of hopscotch hashing. The delete operation was not implemented nor timed for analysis, because it follows a similar method as searching.

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

**Link to implementation:** [here](https://github.com/byung01/comp150-hashing/tree/hopscotch-hashing/hopscotch-hashing)

### Cuckoo Hashing
