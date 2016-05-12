#pragma once
typedef int KeyType;
typedef char DataType;


class TabRecord
{
protected:
	KeyType key;
	DataType *data;
public:
	TabRecord(KeyType, DataType*);
	KeyType GetKey(void) const;
	DataType* GetData(void) const;
	TabRecord& operator=(const TabRecord &);
	int operator==(const TabRecord &) const;
	int operator>(const TabRecord &) const;
	int operator<(const TabRecord &) const;
	int operator!=(const TabRecord &) const;
	int operator>=(const TabRecord &) const;
	int operator<=(const TabRecord &) const;
};