#include <fstream>
#include <iomanip>
#include <cstdlib>
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

bool validateLoginUser(const string &username, const string &password);
bool validateLoginEmployer(const string &companyName, const string &username, const string &password);

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
    ifstream file("user.txt", ios::in);
    string usn;
    string pswd;

            string username = get_input <string> ("Username: ");
            string password = get_input <string> ("Password: ");
    
    while(!file.eof())
    {
        file >> usn >> pswd;
        
        if(username.compare(usn) == 0 && password.compare(pswd) == 0)
        {
            cout << "You are being logged in!" "\n";
            exit(1);
        }
        else
            cout << "INVALID INPUT. ENTER CORRECT USERNAME/PASSWORD!.\n";
    }
}

void login_employer()
{
    ifstream file("user.txt", ios::in);
    string cmpny;
    string usn;
    string pswd;
    
    string company  = get_input <string> ("Company : ");
    string username = get_input <string> ("Username: ");
    string password = get_input <string> ("Password: ");
    
    while(!file.eof())
    {
        file >> cmpny >> usn >> pswd;
        
        if(company.compare(cmpny) == 0 && username.compare(usn) == 0 && password.compare(pswd) == 0)
        {
            cout << "You are being logged in!" "\n";
            exit(1);
        }
        else
            cout << "INVALID INPUT. ENTER CORRECT USERNAME/PASSWORD!.\n";
    }
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
            case 5:
                exit(1);
        }
    }while(choice != '5');
}

void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
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
    ofstream file;
    file.open("user.txt", ios_base::app);
    
    file << username << " " << password << "\n";
    
    file.close();
}

void save_employer(const string &companyName, const string &username, const string &password)
{
    ofstream file;
    file.open("employer.txt", ios_base::app);
    
    file << companyName << " " << username << " " << password << "\n";
    
    file.close();
}
