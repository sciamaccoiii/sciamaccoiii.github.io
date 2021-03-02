
#include "Account.h"
#include <map>
#include <string>
#include <time.h>

using namespace std;

//uncomment all functions include the two declaration below to test

//void TestSwitchAccount();
//void switchAccount(Account acc);

int main()
{
    //TestSwitchAccount();
    return 0;
}

/*
void TestSwitchAccount()
{
    Date birthday(12, 3, 1990), establisedDay(3, 2, 2021);
    Personal pacc("John", "Smith", birthday, "Hello, I'm working in the career resource center. This is my personal account");
    Company cacc("1234", "Test Inc", establisedDay, "Hello, as a company we are testing the switch account function");
    Account aNewAcc("something", "password", pacc, cacc, false);
    switchAccount(aNewAcc);
    aNewAcc.newCompanyMode(true);
    cout << "\nChanging account mode...\n" << endl;
    switchAccount(aNewAcc);
}

void switchAccount(Account acc)
{
    if (acc.getCompanyMode() == false)
    {
        //This is just an example testing on console
        cout << "Name: " << acc.getPerosnalAcInfor().getFName() << " " << acc.getPerosnalAcInfor().getLName() << endl;
        cout << "Birthday: " << acc.getPerosnalAcInfor().getDOB().dateFormat() << endl;
        cout << "Introduction: " << acc.getPerosnalAcInfor().getPara() << endl;
    }
    else
    {
        cout << "Name: " << acc.getCompAcInfor().getcompanyName() << endl;
        cout << "Established day: " << acc.getCompAcInfor().getDE().dateFormat() << endl;
        cout << "Introduction: " << acc.getCompAcInfor().getPara() << endl;
    }
}
*/
