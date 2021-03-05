#include <iostream>
#include <string>
#include <fstream>
#include "ResourceSearch.hpp"

using namespace std;

int main()
{
	
	system ( "title Database Search for Resource" );
	system ( "cls" );

	int choice;
	cout << "1. Search database for book." << endl;
	cout << "2. Exit Program." << endl;
	cout << "3. Input new Book." << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		ResourceSearch::searchForResource();
		break;
	case 2:
		ResourceSearch::quit();
		break;
	case 3:
		ResourceSearch::input();
		break;

		cin.get();
	}

}