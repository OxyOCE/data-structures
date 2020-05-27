# Data Structures
A small collection of basic data structures and sorting algorithms designed for simplicity, learning and reference.

Master | Develop
------ | -------
[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=master)](https://travis-ci.org/OxyOCE/data-structures) | [![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=develop)](https://travis-ci.org/OxyOCE/data-structures)

To keep things simple, these data structures currently only support `int` for their data type.

## Array List
`array-list.c` is a dynamic array that scales its capacity according to demand.

**Pros**
* _O(1)_ append, get, set and delete from end
* Simple
* Contiguous memory allocation

**Cons**
* _O(n)_ insert and delete
* Uses more memory than is strictly necessary

**Features**
* **C** - Append, Insert
* **R** - Get
* **U** - Set
* **D** - Delete
* **Misc** - Automatic downscaling

## Sorting
### Quicksort
`quicksort.c` is one of the fastest comparison sorts for larger data sets, but can degrade to quadratic performance.

**Pros**
* Fast with _O(n log n)_ average case
* Decent memory footprint _O(log n)_
* Easily parallelisable

**Cons**
* Bad _O(n^2)_ worst case
* Not a stable sort

### Mergesort
`mergesort.c` is a fast, stable sort; but it uses double the memory footprint of the array it is sorting.

**Pros**
* Fast with _O(n log n)_ average case
* Stable sort
* Easily parallelisable

**Cons**
* Large _O(n)_ memory footprint
* Generally not as fast as quicksort due to the large memory copying overhead

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
