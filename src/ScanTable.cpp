#include "ScanTable.h"

ScanTable::ScanTable(int size):Table(size)
{
	recs = new TabRecord*[size];
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
	if (!Search(key))
		return;
	delete recs[pos];
	recs[pos] = recs[count - 1];
	count--;
}

