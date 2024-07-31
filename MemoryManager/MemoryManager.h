#ifndef MEMORY_H
#define MEMORY_H

class IMemoryManager
{
public:
	virtual ~IMemoryManager();

	virtual void* AllocateMem(size_t) = 0;
	virtual void FreeMem(void*) = 0;
};

#define MEMORY_OPERATOR_OVERLOADS(alignment) \
	void* operator new(size_t a_size); \
	void* operator new[] (size_t a_size); \
	void* operator new(size_t a_size, IMemoryManager& a_memoryManager); \
	void operator delete(void* a_ptr); \
	void operator delete[] (void* a_array); \
	void operator delete(void* a_ptr, IMemoryManager& a_memoryManager); \

#endif // !MEMORY_H
