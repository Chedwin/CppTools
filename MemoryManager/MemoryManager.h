#ifndef MEMORY_H
#define MEMORY_H

class IMemoryManager
{
public:
	virtual ~IMemoryManager();

	virtual void* allocate(size_t) = 0;
	virtual void free(void*) = 0;
};

void* operator new(size_t a_size);
void operator delete(void* a_ptr);

void* operator new[] (size_t a_size);
void operator delete[] (void* a_array);

void* operator new(size_t a_size, IMemoryManager& a_memoryManager);
void operator delete(void* a_ptr, IMemoryManager& a_memoryManager);

#endif // !MEMORY_H
