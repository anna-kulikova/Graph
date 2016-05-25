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
	Table(KeyType);
	virtual TabRecord* FindKey(KeyType) = 0;
	virtual void Push(KeyType, DataType) = 0;
	virtual void Remove(KeyType) = 0; 
	int	IsEmpty();
	int	IsFull(); 
	virtual int GetCount(); 
	virtual void Reset(); 
	virtual int	GoNext(); 
	virtual int IsTabEnded();
};

