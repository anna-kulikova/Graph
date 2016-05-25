#include "table.h"


Table::Table(KeyType a)
{
	size = a;
	count = 0;
	pos = 0;
}


int Table::IsEmpty()
{
	if (count == 0)
		return 1;
	return 0;
}


int Table::IsFull()
{
	if (count == size)
		return 1;
	return 0;
}


int Table::GetCount()
{
	return count;
}


void Table::Reset()
{
	pos = 0;
}


int Table::GoNext()
{
	if (!IsTabEnded())
	{
		pos++;
		return 1;
	}
	return 0;
}


int Table::IsTabEnded()
{
	if (pos == count)
		return 1;
	return 0;
}
