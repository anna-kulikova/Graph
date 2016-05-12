#include "hash_table.h"

unsigned long HashTable::HashFunc(KeyType key) const
{
	return key;
}
