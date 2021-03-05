#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string_view>

using namespace std;

class ResourceSearch
{
	friend std::istream& operator>>(std::istream& stream, ResourceSearch& book);

public:
	// Constructors
	 ResourceSearch(
		std::string_view title = {},
		std::string_view author = {},
		std::string_view isbn = {} 
		);

	std::string isbn() const;
	std::string title() const;
	std::string author() const;

	void isbn(std::string_view newIsbn);
	void title(std::string_view newTitle);
	void author(std::string_view newAuthor);

	static void searchByAuthorName();
	static void searchByBookTitle();
	static void searchByISBN();
	static void quit();
	static void displayAll();
	static void input();

	static void searchForResource();
private:

	std::string _isbn;
	std::string _title;
	std::string _author;
};