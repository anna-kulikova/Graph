#pragma once
#include <iostream>
#include "d-heap.h"

class Priotity_Queue
{

	D_heap* heap;
public:
	Priotity_Queue(int d = 3);
	Priotity_Queue(const Priotity_Queue&);
	~Priotity_Queue(void);
	int GetSize(void) const;
	D_heap GetHeap(void) const;
	int  operator==(const Priotity_Queue&) const;
	int  operator!=(const Priotity_Queue&) const;
	int  IsEmpty(void) const;
	int  IsFull(void) const;
	void  Pop(void);
	void  Push(const KeyType&);
	KeyType Back(void) const;
	friend std::ostream& operator<< (std::ostream& out, const Priotity_Queue& queue)
	{
		out << queue.heap;
		return out;
	}
};

