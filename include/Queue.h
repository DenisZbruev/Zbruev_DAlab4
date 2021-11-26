#pragma once
#include "Typeelem.h"
#define MaxSizeQueue 100
class Queue
{
	Typeelem* pMem;
	int size;
	int count;
	int first;
	int last;
public:
	Queue(int size_ = 0);
	Queue(const Queue& tmp);
	Queue& operator= (const Queue& tmp);
	/*~Queue()
	{
		delete[]pMem;
	}*/
	bool IsEmpty()
	{
		return count == 0;                //да если пусто, иначе нет
	}
	bool IsFull()
	{
		return count == size;
	}
	void Put(Typeelem tmp);
	Typeelem Get();
	int GetSize()
	{
		return size;
	}
	int GetCount()
	{
		return count;
	}
};