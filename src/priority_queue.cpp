#include "priority_queue.h"

Priotity_Queue::Priotity_Queue(int d)
{
	if (d <= 0)
		throw
		exception("D must be positive");
	heap = new D_heap(0, 1);
}

Priotity_Queue::Priotity_Queue(const Priotity_Queue& queue)
{
	heap = new D_heap(*queue.heap);
}

Priotity_Queue::~Priotity_Queue()
{
	delete heap;
}

int Priotity_Queue::GetSize() const
{
	return heap->GetSize();
}

D_heap Priotity_Queue::GetHeap() const
{
	D_heap heap(*heap);
	return heap;
}

int Priotity_Queue::operator==(const Priotity_Queue& queue) const
{

	return *heap == *queue.heap;
}

int Priotity_Queue::operator!=(const Priotity_Queue& queue) const 
{

	return heap != queue.heap;
}

int Priotity_Queue::IsEmpty() const
{
	if (heap->GetSize() == 0)
		return 1;
	return 0;
}

int Priotity_Queue::IsFull() const
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

void Priotity_Queue::Pop()
{
	if (IsEmpty())
		throw
		exception("Priority queue is empty");
	heap->RemoveMin();
}


void Priotity_Queue::Push(const KeyType& key)
{
	heap->PushKey(key);
}


KeyType Priotity_Queue::Back() const
{
	if (IsEmpty())
		throw 
		exception("Priority queue is empty");
	KeyType tmp = heap->GetKey(0);
	return tmp;
}
