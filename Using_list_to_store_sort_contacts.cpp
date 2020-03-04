#include "pch.h"
#include <iostream>
#include <list>
#include <string>

using namespace  std;

template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << *element << endl;
	}
	cout << endl;
}

class ContactItem
{
public:
	string firstName;
	string lastName;
	string country;
	string displayAs;

	ContactItem(const string &conFName, const string &conLName, const string &conCountry)
	{
		firstName = conFName;
		lastName = conLName;
		country = conCountry;
		displayAs = (firstName + " " + lastName + " lives in " + country);
	}

	//remove tool
	bool operator == (const ContactItem& itemToCompare) const
	{
		return (itemToCompare.lastName == this->lastName);
	}

	//sort by last name
	bool operator < (const ContactItem &itemToCompare) const
	{
		return (this->lastName < itemToCompare.lastName);
	}

	operator const char*() const
	{
		return displayAs.c_str();
	}

	
};

bool SortByCountry(const ContactItem &item1, const ContactItem &item2)
{
	return (item1.country < item2.country);
}




int main()
{
	list<ContactItem> contacts;

	contacts.push_back(ContactItem("Jack", "Welsch", "USA"));
	contacts.push_back(ContactItem("Bill", "Gates", "USA"));
	contacts.push_back(ContactItem("Angi", "Merkel", "Germany"));
	contacts.push_back(ContactItem("Vlad", "Putin", "Russia"));
	contacts.push_back(ContactItem("Dan", "Craig", "UK"));

	cout << "List initial order: " << endl;
	DisplayContents(contacts);
	contacts.sort();
	cout << "List after default sort (configured to last name):" << endl;
	DisplayContents(contacts);
	//contacts.sort(SortByCountry);
	//cout << "Sorting by country" << endl;
	//DisplayContents(contacts);
	cout << "Reversing contents..." << endl;
	contacts.reverse();
	DisplayContents(contacts);

	return 0;

}
