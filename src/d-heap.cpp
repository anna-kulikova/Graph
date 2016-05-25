#include "d-heap.h"

Dist::Dist(int a, KeyType d)
{
	v = a;
	pr = d;
}


D_heap::D_heap(const int d1, const int size)
{
	if (d1 <= 0)
		throw
		exception("D must be positive");
	if (size < 0)
		throw
		exception("Size can't be negative");
	if (size > MAX_HEAP)
		throw
		exception("Out of borders");
	d = d1;
	count = size;
	keys = new Priority*[MAX_HEAP];
}


D_heap::D_heap(const D_heap &heap)
{
	d = heap.d;
	count = heap.count;
	keys = new Priority*[MAX_HEAP];
	for (int i = 0; i <= count - 1; i++)
		keys[i] = heap.keys[i];
}


D_heap::~D_heap()
{
	delete[]keys;
}


int D_heap::GetParent(int heap)
{
	int p;
	return p = (heap - 1) / d;
}


void D_heap::Swap(const int i, const int j)
{
	if ((i > count - 1) || (j > count - 1))
		throw
		exception("Out of borders");
	if ((i < 0) || (j < 0))
		throw
		exception("Indexes can't be negative");
	Priority *tmp = new Priority;
	tmp->pr = keys[i]->pr;
	keys[i]->pr = keys[j]->pr;
	keys[j]->pr = tmp->pr;
}


void D_heap::SiftUp(int i)
{
	if (i > count - 1)
		throw
		exception("Out of borders");
	int p = GetParent(i);
	while ((p >= 0) && (keys[p]->pr > keys[i]->pr))
	{
		if (p == 0)
		{
			Swap(i, p);
			return;
		}
		Swap(i, p);
		i = p;
		p = GetParent(i);
	}
}


int D_heap::MinChild(int i)
{
	if (i*d + 1> count - 1)
		return -1;

	int minc = i*d + 1;
	int maxc;
	if (i*d + d < count - 1)
		maxc = i*d + d;
	else maxc = count - 1;
	for (int j = minc; j <= maxc; j++)
		if (keys[j]->pr < keys[minc]->pr)
			minc = j;
	return minc;
}


void D_heap::SiftDown(int i)
{
	if (i > count)
		throw
		exception("Out of borders");
	int c = MinChild(i);
	while ((c != -1) && (keys[c]->pr < keys[i]->pr))
	{
		Swap(c, i);
		i = c;
		c = MinChild(i);
	}
}


void D_heap::RemoveMin()
{
	keys[0] = keys[count - 1];
	count--;
	SiftDown(0);
}


void D_heap::Remove(int i)
{
	if (i >= count)
		throw
		exception("Out of borders");
	Swap(i, count - 1);
	count--;
	if (keys[i]->pr < keys[GetParent(i)]->pr)
		SiftUp(i);
	else SiftDown(i);
}


void D_heap::Push(KeyType i)
{
	Priority* tmp2 = new Priority;
	tmp2->pr = i;
	count++;
	if (count > MAX_HEAP)
		throw
		exception("Out of borders");
	Priority** tmp = new Priority*[MAX_HEAP];
	for (int j = 0; j < count - 1; j++)
		tmp[j] = keys[j];
	tmp[count - 1] = tmp2;
	keys = tmp;
}


void D_heap::Heapify()
{
	if (count == 0)
		throw
		exception("Heap is empty");
	for (int i = count - 1; i >= 0; i--)
		SiftDown(i);
}


int D_heap::operator==(const D_heap& heap)const
{
	if (heap.count != count)
		return 0;
	for (int i = 0; i < heap.count; i++)
		if (keys[i]->pr != heap.keys[i]->pr)
			return 0;
	return 1;
}


void D_heap::GetHeap()
{
	int level = 0, tmp = 0;
	while (tmp < count)
	{
		tmp += pow(d, level);
		level++;
	}
	int k = 1, z = 0;
	cout << keys[0]->pr << endl;
	for (int i = 1; i < level;i++)
	{
		for (int j = k; (j<k + pow(d, i)) && (j < count); j++)
			cout << keys[j]->pr;
		cout << endl;
		if (k + pow(d, i) > count)
			k = count;
		else k += pow(d, i);
	}
}


D_heap& D_heap::operator=(const D_heap& a)
{
	d = a.d;
	count = a.count;
	for (int i = 0;i<count;i++)
		keys[i] = a.keys[i];
	return *this;
}


int D_heap::GetCount()
{
	return count;
}


Priority* D_heap::GetKey(int i)
{
	return keys[i];
}


void D_heap::Sort()
{
	int tmp = count;
	for (int i = count - 1; i > 0; i--)
		Remove(0);
	count = tmp;
	tmp = 0;
	int tmp2 = count - 1;
	while (tmp <= tmp2)
	{
		Swap(tmp2, tmp);
		tmp++;
		tmp2--;
	}
}