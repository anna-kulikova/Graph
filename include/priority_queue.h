#pragma once

#include "d-heap.h"
#include "binary_search_tree.h"
#include "table.h"
#include "sort_table.h"

typedef int KeyType;

class Priority_Queue
{
public:
	Priority_Queue(void) {};
	virtual ~Priority_Queue() {};
	virtual void Push(const KeyType) = 0;
	virtual void Pop() = 0;
	virtual int IsEmpty() = 0;
	virtual int GetSize() = 0;
	virtual KeyType Top() = 0;
};


class Queue_on_heap : public Priority_Queue
{
private:
	D_heap *heap;
public:
	Queue_on_heap(int);
	virtual ~Queue_on_heap()
	{ 
		delete heap;
	}
	void Push(const KeyType);
	void Pop();
	KeyType Top();
	int IsEmpty();
	virtual int GetSize() 
	{
		return heap->GetCount();
	}
};


