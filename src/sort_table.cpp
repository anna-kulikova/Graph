#include "sort_table.h"
#include "table.h"


TabRecord * SortTable::FindKey(KeyType key)
{
	int left = 0;
	int right = count - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (key < recs[mid]->GetKey()) {
			right = mid - 1;
			pos = left;
		}
		else if (key > recs[mid]->GetKey()) {
			left = mid + 1;
			pos = left;
		}
		else
		{
			pos = mid;
			return recs[mid];
		}
	}
	return 0;
}
void SortTable::Push(KeyType k, DataType Data)
{
	if (IsFull())
		throw
		exception("Table is full");
	TabRecord *tmp;
	tmp = FindKey(k);
	for (int i = count + 1; i >= pos + 1; i--)
		recs[i] = recs[i - 1];
	recs[pos] = new TabRecord(k, Data);
	count++;
}

void SortTable::Remove(KeyType k)
{
	if (IsEmpty())
		//return;
		throw
		exception("Table is empty");
	if (FindKey(k) == NULL)
		throw
		exception("Element doesn't exist");
	for (int i = pos; i<count - 1; i++)
		recs[i] = recs[i + 1];
	recs[count] = NULL;
	count--;
}

void SortTable::Sort()
{
	TabRecord *tmp;
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (recs[i]->GetKey() > recs[j]->GetKey())
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
}


TabRecord* SortTable::Min()
{
	return recs[0];
}




