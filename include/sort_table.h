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
	virtual void Push(KeyType, DataType*);
	virtual void Remove(KeyType);
	void SortData();
};