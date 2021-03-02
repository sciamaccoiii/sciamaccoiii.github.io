#include "Post.h"
#include <algorithm>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

/*This header file has three classes: Account, Personal and Company. When you store data in a vector in main, 
I recommend to use class Account because it has both Personal and Company inside, and a boolean so we can track when the user
swtich to personal mode or company mode. Personal and Company are for storing other account's details.
All the function descriptions are inside the class. newFunction is recommended to use when user want to edit the info*/

class Personal {
private:
	string fName;
	string lName;
	Date dOB;
	vector<string>* languages;
	vector<string>* experiences;
	string paragraph;

public:
	Personal()
	{
		Date defa;
		fName = "n/a";
		lName = "n/a";
		dOB = defa;
		languages = new vector<string>();
		experiences = new vector<string>();
	}
	Personal(string newFName, string newLName, Date newDOB, string newParagraph)
	{
		fName = newFName;
		lName = newLName;
		dOB = newDOB;
		paragraph = newParagraph;
	}
	void newFName(string newFName) { fName = newFName; }
	void newLName(string newLName) { lName = newLName; }
	void newDOB(Date newDOB) { dOB = newDOB; }
	void newPara(string newPara) { paragraph = newPara; }
	string getFName() { return fName; }
	string getLName() { return lName; }
	Date getDOB() { return dOB; }
	string getPara() { return paragraph; }
	vector<string>* getLanguage() { return languages; }
	vector<string>* getExperience() { return experiences; }
	void addLanguage(string newLanguage) { languages->push_back(newLanguage); }
	void addExperience(string newExpr) { experiences->push_back(newExpr); }
	void removeLanguage(string newLanguage)
	{
		vector<string>::iterator it;
		it = find(languages->begin(), languages->end(), newLanguage);
		languages->erase(it);
	}
	void removeExperience(string newExpr)
	{
		vector<string>::iterator it;
		it = find(experiences->begin(), experiences->end(), newExpr);
		experiences->erase(it);
	}
	~Personal() {}
};

class Company {
private:
	string companyCode;
	string companyName;
	Date dE;
	string paragraph;
	vector<string>* products;
	vector<Post>* blogPosts;

public:
	Company()
	{
		companyCode = "n/a";
		companyName = "n/a";
		paragraph = "n/a";
		products = new vector<string>();
		blogPosts = new vector<Post>();
	}
	Company(string newCompanyCode, string newCompanyName, Date newDE, string newParagraph)
	{
		companyCode = newCompanyCode;
		companyName = newCompanyName;
		dE = newDE;
		paragraph = newParagraph;
	}
	void newcompanyCode(string newCompanyCode) { companyCode = newCompanyCode; }
	void newcompanyName(string newCompanyName) { companyName = newCompanyName; }
	void newDE(Date newDE) { dE = newDE;  }
	void newPara(string newPara) { paragraph = newPara; }
	string getcompanyCode() { return companyCode; }
	string getcompanyName() { return companyName; }
	Date getDE() { return dE; }
	string getPara() { return paragraph; }
	vector<string>* getProduct() { return products; }
	vector<Post>* getBlogPost() { return blogPosts; }
	void addProduct(string newProduct) {  products->push_back(newProduct); }
	void newPost(Post newPost) { blogPosts->push_back(newPost); }
	void removeProduct(string product)
	{
		vector<string>::iterator it;
		it = find(products->begin(), products->end(), product);
		products->erase(it);
	}
	void removePost(Post newPost)
	{
		vector<Post>::iterator it;
		it = find(blogPosts->begin(), blogPosts->end(), newPost);
		blogPosts->erase(it);
	}
	~Company() {}
};

class Account {
private:
	string iD;
	string password;  //ID and password might need to be converted to some kind of int using hash for more security
	Personal personalAc;
	Company compAc;
	bool companyMode; //if companyMode is true, only display all infors or functions that are available for company mode. If it is false then display functions and resources available for personal account

public:
	Account()
	{
		iD = "n/a";
		password = "n/a";
		companyMode = false;
	}
	Account(string newID, string newPass, Personal newPersonalAc, Company newCompAc, bool newCompanyMode)
	{
		iD = newID;
		password = newPass;
		personalAc = newPersonalAc;
		compAc = newCompAc;
		companyMode = newCompanyMode;
	}
	void newRegAcInfor(Personal newPersonalAc) {personalAc = newPersonalAc;}
	void newCompAcInfor(Company newCompAc) { compAc = newCompAc; }
	void newCompanyMode(bool newMode) { companyMode = newMode; }; //change account mode function
	Personal getPerosnalAcInfor(){ return personalAc;  }
	Company getCompAcInfor() { return compAc;  }
	bool getCompanyMode() { return companyMode;  }
	~Account() {}
};



#endif

