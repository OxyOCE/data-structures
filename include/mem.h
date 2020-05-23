#ifndef MEM_H_
#define MEM_H_

#include <stddef.h>

extern void *emalloc(size_t s);
extern void *erealloc(void *ptr, size_t s);

#endif
