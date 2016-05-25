#pragma once
#include <iostream>

using namespace std;

typedef int KeyType;

class D_heap
{
private:
	KeyType *keys;
	int d;
	int keysize;
	int heapsize;
public:
	D_heap(int, int);
	~D_heap();
	D_heap(const D_heap &);
	void Swap(int, int);
	void SiftDown(int);
	void SiftUp(int);
	int MinChild(int);
	void RemoveMin(void);
	void RemoveInd(int);
	void PushKey(const KeyType &);
	void Heapify(void);
	int Min(int, int);
	KeyType D_heap::GetKey(int idx) const;
	void Sort(void);
	int GetSize(void) const;
	int GetHeapSize(void)const {return heapsize;}
	int operator==(const D_heap &) const;
	int operator!=(const D_heap &) const;
	friend ostream& operator<<(ostream& out, const D_heap& heap)
	{
		for (int i = 0; i < heap.heapsize; i++)
			out << heap.keys[i] << " ";
		return out;
	}

};
