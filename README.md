# Data Structures
A small collection of basic data structures and sorting algorithms designed for simplicity, learning and reference.

Master|Develop
------|-------
[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=master)](https://travis-ci.org/OxyOCE/data-structures)|[![Build Status](https://travis-ci.org/OxyOCE/data-structures.svg?branch=develop)](https://travis-ci.org/OxyOCE/data-structures)

To keep things simple, these data structures currently only support `int` for their data type.

### Memory Allocation
`mem.c` provides basic error handling for the `malloc` and `realloc` functions and helps prevents code repetition.

### Array List
`array-list.c` is a dynamic array that upscales its capacity according to demand.

**Pros**
* _O(1)_ append and access
* Simple
* Contiguous memory allocation

**Cons**
* _O(n)_ insert and delete
* Uses more memory than is strictly necessary

**Current Features**
* Append
* Get
* Pop

**Planned Features**
* Insert
* Delete
* Reverse
* Sort
* Automatic downscaling
