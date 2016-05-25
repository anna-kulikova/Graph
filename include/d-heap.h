#pragma once

#include <iostream>
#include <cmath>

#define MAX_HEAP 10000

using namespace std;

typedef int KeyType;
 
class Priority
{
public:
	KeyType pr;
};

 
class Dist : public Priority 
{
public:
	int v;
	Dist(int, KeyType);
};

 
class D_heap 
{
private:
	int d; 
	Priority** keys; 
	int count; 
public:
	D_heap(int, int);
	D_heap(const D_heap&);
	~D_heap();

	int GetParent(int); 
	void Swap(const int, const int); 
	void SiftUp(int); 
	void SiftDown(int); 
	int MinChild(int); 
	void RemoveMin(); 
	void Remove(int); 
	void Push(KeyType); 
	void Heapify(); 
	void GetHeap(); 
	int operator == (const D_heap&) const;
	D_heap& operator=(const D_heap&);
	int GetCount();
	Priority* GetKey(int); 
	void Sort(); 
};
