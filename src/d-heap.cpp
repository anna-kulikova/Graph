#include "d-heap.h"

D_heap::D_heap(int keysize, int d)
{
	this->keysize = keysize;
	if (keysize <= 0)
		throw
		exception("Array can't be empty");
	heapsize = 0;
	this->d = d;
	if (d <= 0)
		throw
		exception("D must me plural");
	keys = new KeyType[keysize];
}

D_heap::~D_heap()
{
	delete[]keys;
	heapsize = 0;
	keysize = 0;
	d = 0;
}

D_heap::D_heap(const D_heap &tree)
{
	keysize = tree.keysize;
	heapsize = tree.heapsize;
	d = tree.d;
	keys = new KeyType[keysize];
	for (int i = 0; i < keysize; i++)
		keys[i] = tree.keys[i];
}

void D_heap::Swap(int i, int j)
{
	if ((i >= heapsize) || (i < 0) || (j >= heapsize) || (j < 0))
		throw
		exception("Out of borders");
	KeyType tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void D_heap::SiftDown(int i)
{
	if ((i >= heapsize) || (i < 0))
		throw
		exception("Out of borders");
	int c = MinChild(i);
	while (c != -1 && keys[c] < keys[i])
	{
		Swap(c, i);
		i = c;
		c = MinChild(i);
	}
}

void D_heap::SiftUp(int i)
{
	if (i == 0)
		return;
	if ((i >= heapsize) || (i < 0))
		throw
		exception("Out of borders");
	int p = (i - 1) / d;
	while (p > 0 && keys[p] > keys[i])
	{
		Swap(i, p);
		i = p;
		p = (i - 1) / d;
	}
}

int D_heap::MinChild(int i)
{
	int j, l, minc;
	j = i*d + 1;
	if (j > heapsize - 1)
		return -1;
	l = Min(i*d + d, heapsize - 1);
	minc = j;
	for (int k = j; k <= j; k++)
		if (keys[k] < keys[minc])
			minc = k;
	return minc;
}

void D_heap::RemoveMin()
{
	if (keysize == 0)
		throw
		exception("Heap is empty");
	KeyType minkey = keys[0];
	keys[0] = keys[heapsize - 1];
	heapsize--;
	SiftDown(0);
}

void D_heap::RemoveInd(int i)
{
	if ((i < 0) || (i >= keysize))
		throw
		exception("Out fo borders");
	KeyType key = keys[i];
	keys[i] = keys[heapsize - 1];
	heapsize--;
	SiftDown(i);
}

void D_heap::PushKey(const KeyType &k)
{
	if (heapsize == keysize)
		throw
		exception("Array is full");
	keys[heapsize++] = k;
	SiftUp(heapsize - 1);
}

void D_heap::Heapify()
{
	for (int i = heapsize - 1; i >= 0; i--)
		SiftDown(i);
}


int D_heap::Min(int i, int j)
{
	int m;
	for (int k = i; k < j; k++)
	{
		if (keys[k] < keys[k + 1])
			m = k;
		else
			m = k + 1;
	}
	return m;
}


KeyType* D_heap::GetKey(KeyType*& k) const
{
	k = new KeyType[heapsize];
	for (int i = 0; i < heapsize; i++)
		k[i] = keys[i];
	return k;
}

void D_heap::Sort()
{
	int tmp = heapsize;
	for (int i = heapsize - 1; i >= 0; i--)
		RemoveMin();
	heapsize = tmp;
}

int D_heap::GetSize() const
{
	return keysize;
}

int D_heap::operator==(const D_heap &heap) const
{
	if (keysize != heap.heapsize)
		return 0;
	for (int i = 0; i < keysize; i++)
		if (keys[i] != heap.keys[i])
			return 0;
	return 1;
}

int D_heap::operator!=(const D_heap &heap) const
{
	return !(*this == heap);
}