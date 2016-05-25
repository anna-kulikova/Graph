#pragma once
#include "scan_table.h"
#include <iostream>

using namespace std;


class SortTable : public ScanTable
{
public:
	SortTable(int size) : ScanTable(size) {};
	SortTable(ScanTable& table) : ScanTable(table)
	{ 
		Sort();
	}
	virtual ~SortTable()
	{
		for (int i = 0; i < size; i++)
			delete recs[i];
		delete[]recs;
	}

	virtual TabRecord* FindKey(KeyType key);
	virtual void Push(KeyType k, DataType Data);
	virtual void Remove(KeyType k);
	void Sort();
	TabRecord* Min();
};


