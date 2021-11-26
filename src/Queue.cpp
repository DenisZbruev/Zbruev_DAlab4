#include "Queue.h"
Queue::Queue(int size_)
{
	if ((size_ < 0) || (size_ > MaxSizeQueue))
	{
		throw "uncorrect size of queue";
	}
	size = size_;
	first = -1;
	last = 0;
	count = 0;
	pMem = new Typeelem[size];
}
Queue::Queue(const Queue& tmp)
{
	size = tmp.size;
	first = tmp.first;
	last = tmp.last;
	count = tmp.count;
	pMem = new Typeelem[size];
	for (int i = 0; i < size; i++)
	{
		pMem[i] = tmp.pMem[i];
	}
}
Queue& Queue::operator= (const Queue& tmp)
{
	if (size != 0)
	{
		delete[]pMem;
	}
	size = tmp.size;
	count = tmp.count;
	pMem = new Typeelem[size];
	for (int i = 0; i < size; i++)
	{
		pMem[i] = tmp.pMem[i];
	}
	first = tmp.first;
	last = tmp.last;
	return *this;
}
void Queue::Put(Typeelem tmp)
{
	if (!IsFull())
	{
		if (count == 0)
		{
			first = 0;
			last = 1;
			pMem[0] = tmp;
			count++;
		}
		else
		{
			if (last < size)
			{
				pMem[last++] = tmp;
				count++;
			}
			else
			{
				pMem[0] = tmp;
				count++;
				last = 1;
			}
		}
	}
	else
	{
		throw "queue is full";
	}
}
Typeelem Queue::Get()
{
	if(IsEmpty())
	{
	throw "queue is empty";
	}
	Typeelem res;
	if (count > 0)
	{
		res = pMem[first];
		count--;
		if (count == 0)
		{
			first = -1;
			last = 0;

		}
		else
		{
			if (first == size - 1)
			{
				first = 0;
			}
			else
			{
				first++;
			}
		}
	}
	return res;
}