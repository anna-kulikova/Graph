#include "ArrayHashTable.h"

int ArrayHashTable::GetNextPos(int p, int size) const
{
	return ((p + hashstep) % size);
}

TabRecord*  ArrayHashTable::Search(KeyType key)
{
	pos = HashFunc(key) % size;
	freepos = -1;
	for (int i = 0; i < size; i++)
	{
		if (recs[pos] == 0)
			return 0;
		if (recs[pos]->GetKey() == key)
			return recs[pos];
		if ((recs[pos] == mark) && (freepos == -1))
			freepos = pos;
		pos = GetNextPos(pos, size);
	}
	return 0;
}

void ArrayHashTable::Push(KeyType key, DataType* data)
{
	if (IsFull())
		return;
	TabRecord *tmp = Search(key);
	if (freepos != -1)
	{
		pos = freepos;
		recs[pos] = new TabRecord(key, data);
		count++;
	}
}

void ArrayHashTable::Remove(KeyType key)
{
	TabRecord *tmp = Search(key);
	if (tmp == 0)
		return;
	delete recs[pos];
	recs[pos] = mark;
	count--;
}

void ArrayHashTable::Reset()
{
	pos = 0;
	while (IsTabEnded())
	{
		if ((recs[pos] != 0) && (recs[pos] != mark))
			break;
		pos++;
	}
}

int ArrayHashTable::GetNext()
{
	while (IsTabEnded())
	{
		if ((recs[pos] != 0) && (recs[pos] != mark))
			break;
		pos++;
	}
	return IsTabEnded();
}

