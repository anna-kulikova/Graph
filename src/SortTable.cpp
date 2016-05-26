#include "SortTable.h"
#include "Table.h"


SortTable::SortTable(int size):ScanTable(size)
{
}

SortTable::SortTable(const ScanTable &t)
{
	size = t.size;
	count = t.count;
	pos = 0;
	recs = new TabRecord*[size];
	for (int i = 0; i < count; i++)
		recs[i] = new TabRecord(t.recs[i]->GetKey(), t.recs[i]->GetData());
	SortData();
}

TabRecord * SortTable::Search(KeyType key)
	{
		int left = 0;
		int right = count-1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (key < recs[mid]->GetKey())
				right = mid - 1;
			else if (key > recs[mid]->GetKey())
				left = mid + 1;
			else
			{
				pos = mid;
				return recs[mid];
			}
		}
		pos = right;
		return 0;
	}

void SortTable::Push(KeyType key, DataType *data)
{
	if (IsFull())
		return;
	Search(key);
	for (int i = count; i >= pos; i--)
		recs[i] = recs[i - 1];
	count++;
	recs[pos] = new TabRecord(key, data);
}

void SortTable::Remove(KeyType key)
{
	if (IsEmpty())
		return;
	Search(key);
	delete recs[pos];
	for (int i = count; i >= pos; i--)
		recs[i] = recs[i - 1];
	count--;
}

void SortTable::SortData()
{
	TabRecord *tmp;
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
		{
			if (recs[i] > recs[j])
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
		}
}
