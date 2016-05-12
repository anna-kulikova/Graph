#include "priority_queue.h"

Priority_Queue::Priority_Queue(int d)
{
	if (d <= 0)
		throw
		exception("D must be positive");
	heap = new D_heap(0, 1);
}

Priority_Queue::Priority_Queue(const Priority_Queue& queue)
{
	heap = new D_heap(*queue.heap);
}

Priority_Queue::~Priority_Queue()
{
	delete heap;
}

int Priority_Queue::GetSize() const
{
	return heap->GetSize();
}

D_heap Priority_Queue::GetHeap() const
{
	D_heap heap(*heap);
	return heap;
}

int Priority_Queue::operator==(const Priority_Queue& queue) const
{

	return *heap == *queue.heap;
}

int Priority_Queue::operator!=(const Priority_Queue& queue) const 
{

	return heap != queue.heap;
}

int Priority_Queue::IsEmpty() const
{
	if (heap->GetSize() == 0)
		return 1;
	return 0;
}

int Priority_Queue::IsFull() const
{
	KeyType* tmp;
	try
	{
		tmp = new KeyType();
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

void Priority_Queue::Pop()
{
	if (IsEmpty())
		throw
		exception("Priority queue is empty");
	heap->RemoveMin();
}


void Priority_Queue::Push(const KeyType& key)
{
	heap->PushKey(key);
}


KeyType Priority_Queue::Back() const
{
	if (IsEmpty())
		throw 
		exception("Priority queue is empty");
	KeyType tmp = heap->GetKey(0);
	return tmp;
}
