#include "pch.h"

#include "MemoryManager.h"

IMemoryManager::~IMemoryManager() {}

class MemoryManager : public IMemoryManager
{
public:
	MemoryManager();
	~MemoryManager() override;

	void* AllocateMem(size_t a_size) override;
	void FreeMem(void* a_ptr) override;

	void Expand();
	void CleanUp();

private:
	struct Block
	{
		Block* pNext = nullptr;
	};

	Block* pHead = nullptr;
};

static MemoryManager memManager; // Exclusive to this translation unit

/*** Memory Manager ***/

MemoryManager::MemoryManager()
	: IMemoryManager()
	, pHead(nullptr)
{
	Expand();
}

MemoryManager::~MemoryManager()
{
	CleanUp();
}

void MemoryManager::Expand()
{

}

void MemoryManager::CleanUp()
{

}

void* MemoryManager::AllocateMem(size_t a_size)
{
	return nullptr;
}

void MemoryManager::FreeMem(void* a_ptr)
{

}

/*** new delete operator overloads ***/

void* operator new(size_t a_size)
{
	return memManager.AllocateMem(a_size);
}

void operator delete(void* a_ptr)
{
	memManager.FreeMem(a_ptr);
}

void* operator new[](size_t a_size)
{
	return memManager.AllocateMem(a_size);
}

void operator delete[](void* a_array)
{
	memManager.FreeMem(a_array);
}

void* operator new(size_t a_size, MemoryManager& a_memoryManager)
{
	return memManager.AllocateMem(a_size);
}

void operator delete(void* a_ptr, MemoryManager& a_memoryManager)
{
	memManager.FreeMem(a_ptr);
}