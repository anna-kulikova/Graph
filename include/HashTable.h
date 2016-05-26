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
};