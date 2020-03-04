#include "pch.h"
#include <iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << element->first << " -> " << element->second << endl;
	}
	cout << endl;
}

//Predicate used to sort the contacts reguardless of the case used by first converting them to
//lower case and then sorting them.
struct PredIgnoreCase
{
	bool operator()(const string &str1, const string &str2) const
	{
		string str1NoCase(str1), str2NoCase(str2);
		transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);
		return (str1NoCase < str2NoCase);
	}
};

typedef multimap<string, string> DIR_WITH_CASE;
typedef multimap<string, string, PredIgnoreCase> DIR_NOCASE;

int main()
{
	DIR_WITH_CASE dirWithCase;

	dirWithCase.insert(make_pair("John", "2341234"));
	dirWithCase.insert(make_pair("JOHN", "234134"));
	dirWithCase.insert(make_pair("Joan", "9874758"));
	dirWithCase.insert(make_pair("JAMIE", "0823083"));
	dirWithCase.insert(make_pair("Jaime", "293854"));

	cout << "Displaying contents of the case sensitive map: " << endl;
	DisplayContents(dirWithCase);

	DIR_NOCASE dirNoCase(dirWithCase.begin(), dirWithCase.end());

	cout << "Displaying contents of the case insensitive map:" << endl;
	DisplayContents(dirNoCase);

	cout << "Enter a name to search for: ";
	string name;
	cin >> name;

	auto pairWithCase = dirWithCase.find(name);
	if (pairWithCase != dirWithCase.end())
	{
		cout << "Number located in case sensitive directory: " << pairWithCase->second << endl;
	}
	else
		cout << "Number not found in case sensitive directory" << endl;

	auto pairNoCase = dirNoCase.find(name);
	if (pairNoCase != dirNoCase.end())
	{
		for (; pairNoCase != dirNoCase.end(); ++pairNoCase)
		{
			cout << "Number located in case insensitive directory: " << pairNoCase->first << " " << pairNoCase->second << endl;
		}
	}
	else
		cout << "Number not found in case insensitive directory" << endl;

	return 0;
}