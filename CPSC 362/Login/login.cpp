#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T>
T get_input(const string &strQuery);

string get_username();
string get_password();
string get_companyName();

void save_user(const string &username, const string &password);
void save_employer(const string &companyName, const string &username, const string &password);

void login_user();
void login_employer();
void register_user();
void register_employer();
void main_menu();



int main()
{
    main_menu();
}

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();

    while (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "Error!" "\n";
        cout << strQuery << "\n> ";
    }

    return out;
}

string get_password()
{
    string password1 = get_input <string> ("Please enter your password.");
    string password2 = get_input <string> ("Please re-enter your password.");

    while (password1 != password2) {
        cout << "Error! Passwords do not match." "\n";
        password1 = get_input <string>("Please enter your password.");
        password2 = get_input <string>("Please re-enter your password.");
    }

    return password1;
}

string get_username()
{
    string username = get_input <string>("Please enter a username.");
    cout << "Username: \"" << username << "\"\n";

    while (get_input <char>("Confirm? [y|n]") != 'y') {
        username = get_input <string>("Please enter a username.");
        cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

string get_companyName()
{
    string companyName = get_input <string>("Please enter Company name.");
    cout << "Company: \"" << companyName << "\"\n";
    return companyName;
}

void login_user()
{
    cout << "You are being logged in!" "\n";
}

void login_employer()
{
    cout << "You are being logged in!" "\n";
}

void main_menu()
{
    int choice;
    do{
        choice = get_input <int>(
                                     "Hello, Would you like to log in or register?" "\n"
                                     "[1] Login as User" "\n"
                                     "[2] Login as Empolyer" "\n"
                                     "[3] Register as a Potential Employee" "\n"
                                     "[4] Register as a Employer" "\n"
                                     "[5] Exit");

        switch (choice)
        {
            case 1:
                login_user();
                break;
            case 2:
                login_employer();
                break;
            case 3:
                register_user();
                break;
            case 4:
                register_employer();
                break;
        }
    }while(choice == '5');
}

void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(firstname, lastname, username, password);
}

void register_employer()
{
    string companyName = get_companyName();
    string username = get_username();
    string password = get_password();
    save_employer(companyName, username, password);
}

void save_user(const string &username, const string &password)
{
    
    string filename = username + ".txt";
    ofstream file(filename);
    file << password << "\n";
}

void save_employer(const string &companyName, const string &username, const string &password)
{
    string filename = username + ".txt";
    ofstream file(filename);
    file << companyName << "\n";
    file << password << "\n";
}
