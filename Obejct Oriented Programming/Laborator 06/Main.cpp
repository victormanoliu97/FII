#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include "RomanNumbers.h"
#include "Sentences.h"
using namespace std;

#ifdef _MSC_VER 
//not #if defined(_WIN32) || defined(_WIN64) because we have strncasecmp in mingw
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif



bool romanSort(RomanNumbers i, RomanNumbers j)
{
	return i.getDecimalPair() < j.getDecimalPair();
}

int main()
{

	// Problema 2:


	RomanNumbers r1, r2, r3, r5, r6, r7;

	r1.SetRoman("XX");
	r2.SetRoman("XII");
	r3.SetRoman("XIII");
	r5.SetRoman("MCMXXXV");
	r6.SetRoman("CXCVI");
	r7.SetRoman("MCMIV");



	r1.SetDecimal(r1.Convert());
	r2.SetDecimal(r2.Convert());
	r3.SetDecimal(r3.Convert());
	r5.SetDecimal(r5.Convert());
	r6.SetDecimal(r6.Convert());
	r7.SetDecimal(r7.Convert());

	vector<RomanNumbers> nums;

	nums.push_back(r1);
	nums.push_back(r2);
	nums.push_back(r3);
	nums.push_back(r5);
	nums.push_back(r6);
	nums.push_back(r7);

	sort(nums.begin(), nums.end(), romanSort);

	for (auto i : nums)
	{
		cout << i.getRomanPair() << " ";
	}

	cout << endl;
	cout << endl;


	// Problema 1:

	
	ifstream fin("input.in");

	vector<string> v = readSentences(fin);

	bool rez = validateText(v);

	cout << rez << endl;

	

	map<string, int> words = extractWords(v);
	set<string, Comp> sortedWords;

	for (auto it = words.begin(); it != words.end(); it++)
	{
		sortedWords.insert(it->first);
	}

	for (auto it = sortedWords.begin(); it != sortedWords.end(); it++)
	{
		cout << *it << endl;
	}


	fin.close();

	

	return 0;
}
