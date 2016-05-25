#pragma once
#include "table.h"

class ScanTable : public Table
{
protected:
	TabRecord** recs;
public:
	ScanTable(int size) : Table(size)
	{
		recs = new TabRecord*[size];
		for (int i = 0; i<size; i++)
		{
			recs[i] = NULL;
		}
	}
	virtual ~ScanTable();
	virtual TabRecord* FindKey(KeyType k);
	virtual void Push(KeyType k, DataType Data);
	virtual void Remove(KeyType k);
	void Print();
	virtual int GetCount();
	int GetSize();
	TabRecord** GetRecs();
};


