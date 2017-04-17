#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<initializer_list>
#include"StrVector.h"

using namespace std;

void main()
{
	StrVector v = { "Test", "for" , "C++" };
    auto it = v.GetIterator();
    auto count = v.GetCount();
	
	for (auto index = 0; index < count; index++, it++)
		cout << (*it) << " ";

	

	cout << endl;
    for (auto element: v)
		cout << element << endl;

	auto x = 10 / 2.0;
	
	auto y = 2 / 1.5;

	cout << x << endl;

	cout << y << endl;
}
