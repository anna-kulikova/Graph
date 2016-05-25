#include "scan_table.h"



ScanTable::~ScanTable()
{
	for (int i = 0; i < size; i++)
		delete recs[i];
	delete[]recs;
}


TabRecord * ScanTable::FindKey(KeyType k)
{
	for (int i = 0; i < count; i++)
		if (k == recs[i]->GetKey())
		{
			pos = i;
			return recs[i];
		}
	return NULL;
};

void ScanTable::Push(KeyType k, DataType Data)
{
	if (IsFull())
		throw
		exception("Table is full");
	recs[count] = new TabRecord(k, Data);
	count++;
}

void ScanTable::Remove(KeyType k)
{
	if (IsEmpty())
		//return;
		throw
		exception("Table is empty");
	if (FindKey(k) == NULL)
		//return;
		throw
		exception("Record doesn't exist");
	delete recs[pos];
	recs[pos] = recs[count - 1];
	count--;
}
void ScanTable::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << recs[i]->GetKey() << " " << recs[i]->GetData() << endl;
	}
}

int ScanTable::GetCount()
{
	return count;
};


int ScanTable::GetSize()
{
	return size;
}


TabRecord** ScanTable::GetRecs()
{
	return recs;
}
