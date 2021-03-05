#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <utility> 
#include "ResourceSearch.hpp"

using namespace std;


ResourceSearch::ResourceSearch(
	std::string_view title,
	std::string_view author,
	std::string_view isbn)

	: _isbn(isbn),
	_title(title),
	_author(author) {}

std::string ResourceSearch::isbn() const
{
	return _isbn;
}

std::string ResourceSearch::title() const
{
	return _title;
}

std::string ResourceSearch::author() const
{
	return _author;
}

void ResourceSearch::isbn(const std::string_view newIsbn)
{
	_isbn = newIsbn;
}

void ResourceSearch::title(const std::string_view newTitle)
{
	_title = newTitle;
}

void ResourceSearch::author(const std::string_view newAuthor)
{
	_author = newAuthor;
}


void ResourceSearch::quit()
{
	system("CLS");
	cout << "Thank you for using the Resource Search feature. The program will now close." << endl;
	system("pause");
	cin.get();
}

void ResourceSearch::displayAll()
{
	ResourceSearch resource;
	ifstream Book("ResourceDatabase.txt");
	string author, _isbn, title;
	system("CLS");
	cout << "Entire Resource Database" << endl;
	cout << "Author name, " << "Book Title, " << "ISBN" << endl;
	cout << "----------------------------------" << endl;

	while (Book >> author >> title >> _isbn)
	{
		cout << author << " " << title << " " << _isbn << endl;
	}
	system("pause");
	cin.get();

}

void ResourceSearch::searchByISBN()
{
	ifstream Book("ResourceDatabase.txt");
	string author, _isbn, title;
	string inputisbn, line;
	system("CLS");
	cout << "Enter the ISBN of the book you are searching for: ";
	cin >> inputisbn;

	while (Book >> author >> title >> _isbn)
	{
		if (inputisbn == _isbn)
		{
			system("CLS");
			cout << "Book's ISBN found. Displaying entire resource." << endl;
			cout << author << " " << title << " " << _isbn << endl;
		}

	}
	while (Book >> _isbn)
	{
		if (inputisbn != _isbn)
		{
			cout << "Book's ISBN not found." << endl;
		}
	}

	system("pause");
}

void ResourceSearch::searchByBookTitle()
{
	ifstream Book("ResourceDatabase.txt");
	string author, _isbn, title;
	string str, line;
	system("CLS");
	cout << "Enter the title of the book you are searching for: ";
	cin >> str;

	while (Book >> author >> title >> _isbn)
	{
		if (str == title)
		{
			system("CLS");
			cout << "Book title found. Displaying entire resource." << endl;
			cout << author << " " << title << " " << _isbn << endl;
		}
	}
	while (Book >> title)
	{
		if (str != title)
		{
			cout << "Book title not found." << endl;
		}
	}
	system("pause");
}
void ResourceSearch::searchByAuthorName()
{
	ifstream Book("ResourceDatabase.txt");
	string author, _isbn, title;
	string str, line;
	system("CLS");
	cout << "Enter the author's name you are searching for: ";
	cin >> str;

	while (Book >> author >> title >> _isbn)
	{
		if (str == author)
		{
			system("CLS");
			cout << "Author found. Displaying entire resource." << endl;
			cout << author << " " << title << " " << _isbn << endl;
		}
	}
	while (Book >> author)
	{
		if (str != author)
		{
			cout << "Author not found." << endl;
		}
	}
	system("pause");
}

void ResourceSearch::input()
{
	string author, _isbn, title;
	ofstream newBook("ResourceDatabase.txt", ios::app);
	cin.ignore();
	cout << "Enter the new Book's author:" << endl;
	getline(cin, author);
	cout << "Enter the new Book's name:" << endl;
	getline(cin, title);
	cout << "Enter the new Book's ISBN:" << endl;
	cin >> _isbn;

	newBook <<"\n"<< author << ", " << title << ", " << _isbn;
	cout << "Book entered successfully. Program will now close. Please restart." << endl;
	newBook.close();
}
void ResourceSearch::searchForResource()
{
	int choice2;
	system("CLS");

	cout << "1. Search by author name." << endl;
	cout << "2. Search by book name." << endl;
	cout << "3. Search by keyword / ISBN." << endl;
	cout << "4. Display all books." << endl;
	cout << "5. Exit program." << endl;
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		searchByAuthorName();
		break;
	case 2:
		searchByBookTitle();
		break;
	case 3:
		searchByISBN();
		break;
	case 4:
		displayAll();
		break;
	case 5:
		quit();
		break;

	}
}


std::istream& operator>>(std::istream& stream, ResourceSearch& book)
{
	ResourceSearch someBook;
	char delim = ',';

	stream >> std::quoted(someBook._author) >> delim
		>> std::quoted(someBook._title) >> delim
		>> std::quoted(someBook._isbn);

	if (stream) book = std::move(someBook);

	return stream;
}