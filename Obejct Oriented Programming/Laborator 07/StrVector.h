#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
#include<initializer_list>

using namespace std;


class StrVector
{
private:
	vector<string> v;

	int my_size = 0;

public:
	StrVector(initializer_list<string> l)
	{
		for (auto item : l)
		{
			v.push_back(item);
			my_size++;
		}
	}

	int GetCount()
	{
		return my_size;
	}

	void print()
	{
		for (auto item : v)
		{
			cout << item << endl;
		}
	}


	vector<string>::iterator begin()
	{
		return v.begin();
	}

	vector<string>::iterator end()
	{
		return v.end();
	}

	vector<string>::iterator GetIterator()
	{
		return v.begin();
	}

	
};