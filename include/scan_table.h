#pragma once
#include "table.h"

class ScanTable :public Table
{
protected:
	TabRecord **recs;
public:
	ScanTable(int);
	ScanTable(const ScanTable& table) : ScanTable(table.size) {
		count = table.count;
		for (size_t i = 0; i < table.count; i++)
			recs[i] = new TabRecord(table.recs[i]->GetKey(), table.recs[i]->GetData());
	};
	~ScanTable();
	virtual TabRecord* Search(KeyType);
	virtual void Push(KeyType, DataType*);
	virtual void Remove(KeyType);
	friend class SortTable;
};