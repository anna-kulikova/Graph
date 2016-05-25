#pragma once
typedef int KeyType;
typedef char DataType;


class TabRecord
{
protected:
	KeyType key; 
	DataType data; 
public:
	TabRecord(KeyType a, DataType b)
	{
		key = a;
		data = b;
	}
	int GetKey()
	{
		return key;
	}
	DataType GetData()
	{ 
		return data;
	}
	TabRecord& operator=(const TabRecord &);
	int operator==(const TabRecord &) const;
	int operator>(const TabRecord &) const;
	int operator<(const TabRecord &) const;
	int operator!=(const TabRecord &) const;
	int operator>=(const TabRecord &) const;
	int operator<=(const TabRecord &) const;
};