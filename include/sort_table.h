#pragma once
#include "scan_table.h"
#include <iostream>

using namespace std;

class SortTable :public ScanTable
{
public:
	SortTable(int);
	SortTable(const ScanTable &);
	virtual TabRecord* Search(KeyType);
	TabRecord* findMin(void) {return count == 0 ? NULL : recs[0];}
	virtual void Push(KeyType, DataType*);
	virtual void Remove(KeyType);
	void SortData();
};