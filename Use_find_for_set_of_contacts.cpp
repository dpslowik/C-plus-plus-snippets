#include "pch.h"
#include <iostream>
#include<set>
#include<string>
using namespace std;

template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << *element << endl;
	}
	cout << endl;
}

struct ContactItem
{
	string name;
	string phonenum;
	string displayAs;

	ContactItem(const string &nameInit, const string &phone)
	{
		name = nameInit;
		phonenum = phone;
		displayAs = (name + " " + phonenum);
	}

	bool operator == (const ContactItem &itemToCompare) const
	{
		return (itemToCompare.phonenum == this->phonenum);
	}
	bool operator < (const ContactItem &itemToCompare) const
	{
		return (this->phonenum < itemToCompare.phonenum);
	}
	operator const char*() const
	{
		return displayAs.c_str();
	}
};

int main()
{
	set<ContactItem> setContacts;
	setContacts.insert(ContactItem("Jack Welsch", "1"));
	setContacts.insert(ContactItem("Bill Gates", "2"));
	setContacts.insert(ContactItem("Angi Merkle", "3"));
	setContacts.insert(ContactItem("Vlad Putin", "4"));
	setContacts.insert(ContactItem("John Travolta", "5"));
	setContacts.insert(ContactItem("Ben Affleck", "6"));

	DisplayContents(setContacts);

	cout << "Enter a number you wish to find: ";
	string inputNum;
	getline(cin, inputNum);

	auto contactFound = setContacts.find(ContactItem("", inputNum));
	if (contactFound != setContacts.end())
	{
		cout << *contactFound << " has been found" << endl;
	}
	else
		cout << "Contact not found" << endl;

	//auto elementFound = setContacts.find(ContactItem("\0", "2"));
	//if (elementFound != setContacts.end())
	//{
	//	cout << "Element " << *elementFound << " found!" << endl;
	//}
	//else
	//	cout << "Element not found" << endl;

	return 0;

}
