#include <vector>
#include "Date.h"

using namespace std;

/*This class is dedicated for company's posts about hiring or internship*/

#ifndef POST_H
#define POST_H

class Post {
private:
	int postID;
	Date dP;
	string paragraph;

public:
	Post()
	{
		postID = 0;
	}
	Post(int newPostID, string newParagraph)
	{
		postID = newPostID;
		paragraph = newParagraph;
	}
	int getPostID()
	{
		return postID;
	}
	string getParagraph()
	{
		return paragraph;
	}
	Date getDP()
	{
		return dP;
	}
	void newParagraph(string newPara)
	{
		paragraph = newPara;
	}
	~Post();
};
#endif
