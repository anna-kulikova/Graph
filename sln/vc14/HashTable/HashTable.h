#pragma once
#include <iostream>
#include "Table.h"

using namespace std;

class HashTable : public Table
{
protected:
	virtual unsigned long HashFunc(KeyType) const;
public:
	HashTable(int size):Table(size){}
	virtual TabRecord* Search(KeyType) = 0;
	virtual void Push(KeyType, DataType*) = 0;
	virtual void Remove(KeyType) = 0;
};