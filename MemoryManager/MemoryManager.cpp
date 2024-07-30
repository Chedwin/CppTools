#include "pch.h"

#include "MemoryManager.h"

IMemoryManager::~IMemoryManager() {}

class MemoryManager : public IMemoryManager
{
public:
	~MemoryManager() override;

	void* allocate(size_t a_size) = 0;
	void free(void* a_ptr) = 0;
};

///////////////////////////////////////////

MemoryManager::~MemoryManager()
{

}

void* MemoryManager::allocate(size_t a_size)
{
	return nullptr;
}

void MemoryManager::free(void* a_ptr)
{

}

///////////////////////////////////////////

void* operator new(size_t aSize)
{
	return nullptr;
}

void operator delete(void* a_ptr)
{

}

void* operator new[](size_t a_size)
{
	return nullptr;
}

void operator delete[](void* a_array)
{

}

void* operator new(size_t a_size, MemoryManager& a_memoryManager)
{
	return nullptr;
}

void operator delete(void* a_ptr, MemoryManager& a_memoryManager)
{

}