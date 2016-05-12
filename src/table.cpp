#include "table.h"

Table::Table(int size)
{
	count = 0;
	pos = 0;
}

int Table::IsEmpty(void) const
{
	if (count == 0)
		return 0;
	return 1;
}

int Table::IsFull(void) const
{
	if (count == size)
		return 1;
	return 0;
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
