#pragma once
#include "table.h"

class ScanTable :public Table
{
protected:
	TabRecord **recs;
public:
	ScanTable(int);
	ScanTable() {};
	ScanTable(const ScanTable&) {};
	~ScanTable();
	virtual TabRecord* Search(KeyType);
	virtual void Push(KeyType, DataType*);
	virtual void Remove(KeyType);
	friend class SortTable;
};