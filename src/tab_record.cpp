
#include "tab_record.h"



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
