# Data Structures
A small collection of basic data structures and sorting algorithms designed for simplicity, learning and reference.

Master|Develop
------|-------
[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=master)](https://travis-ci.org/OxyOCE/data-structures)|[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=develop)](https://travis-ci.org/OxyOCE/data-structures)

To keep things simple, these data structures currently only support `int` for their data type.

### Memory Allocation
`mem.c` provides basic error handling for the `malloc` and `realloc` functions and helps prevents code duplication.

### Array List
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

### Sorting and Searching
`sort-and-search.c` contains implementations for various sorting and searching algorithms.

**Sorting**
* None yet

**Searching**
* **Linear Search** - _O(n)_ - can operate on unsorted lists
* **Binary Search** - _O(log n)_ - list must be sorted
