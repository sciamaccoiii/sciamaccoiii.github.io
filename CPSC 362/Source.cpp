
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string job_title;
	int option_company;
	int option_job;
	string company_choice; 
	//create map to store the info of companies and their available job
	map<string,multimap<string, string>> company_salary; 
	// store the list of jobs and salary of company A for instance
	company_salary.insert(make_pair("A", multimap<string, string>()));
	company_salary["A"].insert(make_pair("software development", "30$/h"));
	company_salary["A"].insert(make_pair("manager", "40$/h"));
	// store the list of jobs and salary of company B for instance
	company_salary.insert(make_pair("B", multimap<string, string>()));
	company_salary["B"].insert(make_pair("web designer", "$50,000/year"));
	company_salary["B"].insert(make_pair("game designer", "35$/h"));
	//propmt user to choose
	cout << " PLease enter 1 if you want to see the salary information of all company or 2 to search for a specific company: ";
	cin >> option_company;
	if (option_company == 1 ){ // if user want to display all jobs and company
		map<string, multimap<string, string> >::iterator itr; 		// For accessing outer map 
		multimap<string, string>::iterator ptr;				   // For accessing inner map 
		for (itr = company_salary.begin(); itr != company_salary.end(); itr++){
			for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
				cout << "Company " << itr->first
					<< "--> Job title: " << ptr->first
					<< ". Salary: " << ptr->second << endl;
			}
		}
	}
	else{ // if the user want to pick a specific company
		cout << "Please enter the company name you want to search: "<< endl;
		cin >> company_choice;
		//promp user to choose if they want to see all jobs of that company or a specific job
		cout << "PLease enter 1 if you want to see all jobs of company "<<company_choice<<" or 2 if you want to search for a specific job title:";
		cin >> option_job;
		if (option_job==1){
			map<string, multimap<string, string> >::iterator itr;
			multimap<string, string>::iterator ptr;
			for (itr = company_salary.begin(); itr != company_salary.end(); itr++) {
				for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
					if (itr->first==company_choice){
						cout << "Company " << itr->first
							<< "--> Job title: " << ptr->first
							<< ". Salary: " << ptr->second << endl;
					}
				}
			}
		}
		else{
			cout << "Please enter the job title you want to search  from company " << company_choice << ":";
			cin >> job_title;
			map<string, multimap<string, string> >::iterator itr;
			multimap<string, string>::iterator ptr;
			for (itr = company_salary.begin(); itr != company_salary.end(); itr++) {
				for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
					if (ptr->first == job_title){
						cout << "Company " << itr->first
							<< "--> Job title: " << ptr->first
							<< ". Salary: " << ptr->second << endl;
					}
				}
			}
		}
	}
}