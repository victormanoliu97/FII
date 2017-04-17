#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
#ifdef _MSC_VER 
//not #if defined(_WIN32) || defined(_WIN64) because we have strncasecmp in mingw
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif


vector<string> readSentences(ifstream& fin)
{

	vector<string> ret;
	char c;
	string tmp = "";
	while (fin.get(c))
	{
		if (c == '\n')
			continue;

		if (tmp.size() == 0 && c == ' ')
			continue;

		tmp += c;

		if (c == '?' || c == '!' || c == '.')
		{
			ret.push_back(tmp);
			tmp = "";
		}
	}
	if (tmp.size() != 0)
		ret.push_back(tmp);

	return ret;
}

bool validateText(vector<string> sentences)
{
	for (auto it = sentences.begin(); it != sentences.end(); it++)
	{
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
		{
			if (strchr(".-?!,", *it2) && *(it2) == *it2)
			{
				return false;
			}
		}

		if (strchr("?!.", *(it->end() - 1)) == NULL)
		{
			return false;
		}
	}

	return true;
}

map<string, int> extractWords(vector<string> sentences)
{
	map<string, int> ret;

	for (auto it = sentences.begin(); it != sentences.end(); it++)
	{
		bool inWord = false;
		string word = "";
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
		{
			if (isalpha(*it2) && !inWord)
			{
				inWord = true;
				word += *it2;
			}
			else if (isalpha(*it2) && inWord)
			{
				word += *it2;
			}
			else if (!isalpha(*it2) && inWord)
			{
				if (ret.find(word) == ret.end())
				{
					ret[word] = 1;
				}
				else
				{
					ret[word]++;
				}
				word = "";
				inWord = false;
			}
		}
	}

	return ret;
}

class Comp
{
public:
	bool operator()(const string& s1, const string& s2)
	{
		return (stricmp(s1.c_str(), s2.c_str()) < 0);
	}
};