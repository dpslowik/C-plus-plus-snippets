#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<float> Jars(2);
	float jHeight;
	float jDiameter;
	char goAgain = '\0';

	do
	{
		cout << "Enter diameter of jar: ";
		cin >> jDiameter;
		cout << endl;
		cout << "Enter height of jar: ";
		cin >> jHeight;
		Jars.push_back(jDiameter);
		Jars.push_back(jHeight);
		cout << "Do you have another package?(y/n)";
		cin >> goAgain;
	} while (goAgain != 'n');
	
	for (size_t counter = 1; (counter * 2) < Jars.size(); ++counter)
		{
			int evenCounter = counter * 2;
			int oddCounter = (counter * 2) + 1;
			cout << "Dimentions for Shipment " << counter << ": " << endl;
			cout << "Diameter is: " << Jars[evenCounter] << endl;
			cout << "  Height is: " << Jars[oddCounter] << endl;
		}
	
	
	
	return 0;

}

