# Data Structures
A small collection of simple data structures, sorting algorithms and searching algorithms. Explained and tested for learning and reference.

Master | Develop
------ | -------
[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=master)](https://travis-ci.org/OxyOCE/data-structures) | [![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=develop)](https://travis-ci.org/OxyOCE/data-structures)

To keep things simple, these data structures currently only support `int` for their data type.

## Array List
`array-list.c` is a dynamic array that scales its capacity according to demand.

**Pros**
* _O(1)_ append and delete from end, get and set from anywhere
* Can use binary search
* Simple
* Contiguous memory allocation

**Cons**
* _O(n)_ insert and delete from start and within
* Uses more memory than is strictly necessary

**Operations**
* **Mutators** - Append, Insert, Set, Delete
* **Accessors** - Get, Find
* **Utility** - Sort, Reverse
* **Misc** - Automatic downscaling

## Linked List
`linked-list.c` implements a doubly linked list. A good choice if you need to insert at both the start and the end of a list.

**Pros**
* All mutators are _O(1)_ on the start or the end of a list
* Can be merge sorted in _O(1)_ space

**Cons**
* All mutators are _O(n)_ within a list
* All accessors are _O(n)_
* Somewhat complex implementation

**Operations**
* **Mutators** - Append, Insert, Set, Delete
* **Accessors** - Get, Find
* **Utility** - Sort, Reverse

## Stack
`stack.c` is a last in first out abstract data type based on an array list. It has three main operations: push, pop and peek.

**Pros**
* All operations are _O(1)_
* Easily implemented from array list

**Cons**
* Not many - an array list is one of the best ways to implement a stack

**Operations**
* **Mutators** - Push
* **Accessors** - Pop, Peek

## Sorting
### Heapsort
`heapsort.c` is a fast in-place sort, but it is not suited to a parallel implementation.

**Pros**
* Fast with _O(n log n)_ average case
* In-place sort (i.e. memory footprint _O(1)_)

**Cons**
* Not a stable sort
* Not suited to a parallel implementation

### Mergesort
`mergesort.c` is a fast, stable sort; but it uses double the memory footprint of the array it is sorting.

**Pros**
* Fast with _O(n log n)_ average case
* Stable sort
* Easily parallelisable

**Cons**
* Large _O(n)_ memory footprint
* Generally not as fast as quicksort due to the large memory copying overhead

### Insertion Sort
`simple-algorithms.c` implements insertion sort. A simple algorithm that works well on small data sets.

**Pros**
* Performs better than many _O(n log n)_ sorts on small datasets (n < ~20)
* Stable sort
* In-place sort (i.e. memory footprint _O(1)_)

**Cons**
* With _O(n^2)_ time complexity, it quickly becomes terrible for larger datasets

### Quicksort
`quicksort.c` is one of the fastest comparison sorts for larger data sets, but can degrade to quadratic performance.

**Pros**
* Fast with _O(n log n)_ average case
* Decent memory footprint _O(log n)_
* Easily parallelisable

**Cons**
* Bad _O(n^2)_ worst case
* Not a stable sort

## Searching
`simple-algorithms.c` implements both linear search and binary search.

Algorithm | Pro | Con
--------- | --- | ---
**Linear Search** | Can operate on unsorted lists | _O(n)_
**Binary Search** | _O(log n)_ | List must be sorted prior

## Misc
**Memory Allocation**

`mem.c` provides basic error handling for the `malloc` and `realloc` functions and helps prevents code duplication.

**Common Functions**

`common.c` contains simple functions that are shared across multiple files.
