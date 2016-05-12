#pragma once
#include <iostream>
#include "table.h"
#include "hash_table.h"

using namespace std;

class ArrayHashTable : public HashTable
{
protected:
	TabRecord **recs;
	int freepos;
	int hashstep;
	TabRecord *mark;
	int GetNextPos(int, int) const;
public:
	ArrayHashTable(int size, int hashstep) : HashTable(size)
	{
		this->hashstep = hashstep;
		recs = new TabRecord *[size];
		for (int i = 0; i < size; i++)
			recs[i] = 0;
		mark = new TabRecord(-1, 0);
	}

	virtual TabRecord* Search(KeyType);
	virtual void Push(KeyType, DataType*);
	virtual void Remove(KeyType);
	virtual void Reset();
	virtual int GetNext();
};