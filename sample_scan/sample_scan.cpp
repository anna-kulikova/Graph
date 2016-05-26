#include "ScanTable.h"
#include <iostream>


int main()
{
	ScanTable s(1);
	s.Push(1, "a");
	cout << s.Search(1)->GetKey() << endl;

}