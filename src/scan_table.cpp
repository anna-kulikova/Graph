#include "scan_table.h"

ScanTable::ScanTable(int size) :Table(size)
{
	recs = new TabRecord*[size];
	for (size_t i = 0; i < size; i++)
		recs[i] = NULL;
}

ScanTable::~ScanTable()
{
	delete[]recs;
}

TabRecord * ScanTable::Search(KeyType key)
{
	for (int i = 0; i < count; i++)
		if (key == recs[i]->GetKey())
		{
			pos = i;
			return recs[i];
		}
	return 0;
}

void ScanTable::Push(KeyType key, DataType *data)
{
	if (IsFull())
	{
		throw ("Table is empty");
		return;
	}
	recs[count] = new TabRecord(key, data);
	count++;
}

void ScanTable::Remove(KeyType key)
{
	if (IsEmpty())
		throw ("Table is empty");
	if (!Search(key))
		return;
	delete recs[pos];
	recs[pos] = recs[count - 1];
	count--;
}

