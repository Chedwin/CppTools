#ifndef MEMORY_H
#define MEMORY_H

void* operator new(size_t aSize);
void operator delete(void* apPtrToBeDeleted);

#endif MEMORY_H
