#pragma once
#include "tab_record.h"
#include <iostream>
typedef int KeyType;
typedef char DataType;

using namespace std;

class Table
{
protected:
	int size;
	int count;
	int pos;
public:
	Table() { cout << "Table::Table()" << endl; };
	Table(int);
	virtual TabRecord* Search(KeyType) = 0;
	virtual void Push(KeyType, DataType*) = 0;
	virtual void Remove(KeyType) = 0;
	int IsEmpty(void) const;
	int IsFull(void) const;
	int GetCount(void) const;
	virtual void Reset(void);
	virtual int GetNext(void);
	virtual int IsTabEnded(void) const;
};