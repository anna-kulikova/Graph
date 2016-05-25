#include "priority_queue.h"

Queue_on_heap::Queue_on_heap(int arity)
{
	if (arity < 0)
		throw
		exception("Arity must be plural");
	heap = new D_heap(arity, 0);
}


void Queue_on_heap::Pop()
{
	if (IsEmpty())
		throw
		exception("Queue is empty");
	heap->RemoveMin();
}


int Queue_on_heap::IsEmpty()
{
	return heap->GetCount() == 0;
};


void Queue_on_heap::Push(const KeyType arity)
{
	heap->Push(arity);
	heap->Sort();
}


KeyType Queue_on_heap::Top()
{
	if (IsEmpty())
		throw
		exception("Queue is empty");
	return heap->GetKey(0)->pr;
}

////////////////////////////////////////////////////////////////////////////////


class Queue_on_tree : public Priority_Queue
{
private:
	bst *tree;
public:
	Queue_on_tree();
	virtual ~Queue_on_tree()
	{
		delete tree;
	}
	virtual void Push(const KeyType a)
	{
		Node *tmp = new Node(a);
		tree->Push(tree->root, tmp);
	}
	virtual void Pop()
	{
		tree->Remove(tree->root, tree->root->key);
	}
	virtual int IsEmpty()
	{
		return tree->GetSize() == 0;
	}
	virtual KeyType Top()
	{
		return tree->root->balance;
	}
	virtual int GetSize()
	{
		return tree->GetSize();
	}
	int operator==(const Queue_on_tree&)const;
};


Queue_on_tree::Queue_on_tree()
{
	tree = new bst;
}


int Queue_on_tree::operator==(const Queue_on_tree& a)const
{
	return *tree == *a.tree;
}


//////////////////////////////////////////////////////////////////

class Queue_on_table : public Priority_Queue
{
private:
	SortTable *table;
	int s;
public:
	Queue_on_table(int);
	~Queue_on_table();
	void Push(KeyType a);
	void Pop();
	KeyType Top();
	int IsEmpty();
	int GetSize();
};


Queue_on_table::Queue_on_table(int arity)
{
	if (arity < 0)
		throw
		exception("Arity must be plural");
	table = new SortTable(arity);
	s = 0;
}


Queue_on_table::~Queue_on_table()
{
	delete table;
}


void Queue_on_table::Push(KeyType a)
{
	table->Push(s, a);
	s++;
}


void Queue_on_table::Pop()
{
	if (IsEmpty())
		throw
		exception("Queue is empty");
	table->Remove(table->Min()->GetKey());
	s--;
}


KeyType Queue_on_table::Top()
{
	return table->Min()->GetData();
}


int Queue_on_table::GetSize()
{
	return table->GetCount();
}


int Queue_on_table::IsEmpty()
{
	if (table->GetCount() == 0)
		return 1;
	return 0;
}


class Create_Queue
{
public:
	static bool CreateQueue(Priority_Queue*&, const int, const int);
};


bool Create_Queue::CreateQueue(Priority_Queue*& q, const int a, const int b)
{
	if (a == 1)
	{
		q = new Queue_on_heap(b);
		return true;
	}
	if (a == 2)
	{
		q = new Queue_on_tree();
		return true;
	}
	if (a == 3)
	{
		q = new Queue_on_table(b);
		return true;
	}
	return false;
}

