#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
	vector<int> integers(1);
	char userSelect = '\0';
	//string str1;
	
	do
	{
		cout << "Select \'a\' to add an element to the vector," << endl;
		cout << "Select \'v\' to view an element provided an index." << endl;
		cout << "Select \'x\' to exit" << endl;
		cout << "Select \'s\' to search for a value" << endl;
		cin >> userSelect;
		//cin >> str1;
		//bool isANumber = std::all_of(str1.begin(), str1.end(), [](char c) {return isdigit(static_cast<unsigned char>(c)); });
		//return isANumber ? std::stoi(str1) : throw std::invalid_argument{ "Invalid input" };


		if (userSelect == 'a')
		{
			cout << "Please enter the integer to add: ";
			int newInteger;
			cin >> newInteger;
			integers.push_back(newInteger);
			cout << endl;
			cout << newInteger << " has been added to the vector at position " << integers.size() - 1 << endl;

		}
		
		else if (userSelect == 'v')
			{
				cout << "Please enter index number to view integer: ";
				int viewInteger = 0;
				cin >> viewInteger;
				if (viewInteger < integers.size())
					cout << "Element at position " << viewInteger << " is: " << integers.at(viewInteger) << endl;
				else
				{
					cout << "Index number exceeds bounds!" << endl;
					return 0;
				}
			}
		else if (userSelect == 's')
		{
			cout << "Please enter integer value to search for: ";
			int findInteger = 0;
			cin >> findInteger;
			vector<int>::iterator elFound = find(integers.begin(), integers.end(), findInteger);
			if (elFound != integers.end())
			{
				int elPos = distance(integers.begin(), elFound);
				cout << "Value " << *elFound << " found at position: " << elPos << endl;
			}
			else
				cout << "Value not found" << endl;
		}
	} while (userSelect != 'x');

	cout << "Goodbye" << endl;
	return 0;
}
