
#include "TabRecord.h"

TabRecord::TabRecord(KeyType key, DataType* data)
{
	this->key = key;
	this->data = data;
}

KeyType TabRecord::GetKey(void) const
{
	return key;
}

DataType* TabRecord::GetData(void) const
{
	return data;
}

TabRecord& TabRecord::operator=(const TabRecord &tab)
{
	TabRecord *t = new TabRecord(tab.key, tab.data);
	return *t;
}

int TabRecord::operator==(const TabRecord &tab) const
{
	return key == tab.key;
}

int TabRecord::operator>(const TabRecord &tab) const
{
		return key > tab.key;
}

int TabRecord::operator<(const TabRecord &tab) const
{
	return key < tab.key;
}

int TabRecord::operator!=(const TabRecord &tab) const
{
	return key != tab.key;
}

int TabRecord::operator>=(const TabRecord &tab) const
{
	return key >= tab.key;
}

int TabRecord::operator<=(const TabRecord &tab) const
{
	return key <= tab.key;
}
