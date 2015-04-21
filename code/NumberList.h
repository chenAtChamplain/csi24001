/*
Author: Matthew Fortier
CSI-240-01
Final Project

Due: 04/24/2015

Number Linked List declaration

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the
assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the
purpose of future plagiarism checking)

*/

#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include "employee.h"

const int ALL_INDICIES = 0;

class NumberList
{
private:
	struct Node
	{
		int mData;
		Node *mNext;

		Node()
		{
			mNext = NULL;
		}
		Node(int value)
		{
			mData = value;
			mNext = NULL;
		}
	};

	Node *mHead = NULL, *mTail = NULL;

public:
	NumberList(); //constructor

	~NumberList(); //destructor

	int linkCount = 0;

	void display();

	bool insert(int data);

	bool insert(int index, int data);

	bool isExist(int searchKey);

	int remove();
};

#endif // !LINKEDLIST_H