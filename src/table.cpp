#include "table.h"

Table::Table(int size)
{
	if (size < 0)
		throw("Size can not be negative");
	this->size = size;
	count = 0;
	pos = 0;
}

int Table::IsEmpty(void) const
{
	return count == 0;
}

int Table::IsFull(void) const
{
	return count == size;
}

int Table::GetCount(void) const
{
	return count;
}

void Table::Reset(void)
{
	pos = 0;
}

int Table::GetNext(void)
{
	if (IsTabEnded())
		return 1;
	pos++;
}

int Table::IsTabEnded(void) const
{
	if (pos == count)
		return 1;
	return 0;
}
