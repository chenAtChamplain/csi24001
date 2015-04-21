/*
Author: Matthew Fortier
CSI-240-01
Final Project

Due: 04/24/2015

Number Linked List implementation

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

#include "NumberList.h"

/**********************************************************************
**Pre: none
**Post: default object is created
**Purpose: default constructor sets all values of Linked List to null
**********************************************************************/
NumberList::NumberList()
{
	mHead = NULL;
	mTail = NULL;
}

/**********************************************************************
**Pre: NumberList object has been previously created
**Post: NumberList object is cleared, and deleted
**Purpose: to clear and delete the List to prevent memory leak
**********************************************************************/
NumberList::~NumberList()
{
	while (mHead != NULL) //cycles throgth each node and removes it
		remove();
}

/**********************************************************************
**Pre: none
**Post: displays the entire list
**Purpose: cycle through all of the nodes and display each
**********************************************************************/
void NumberList::display()
{
	Node *tmp; //temporary node to avoid messing up mHead location

	if (mHead != NULL) //if list is filled
	{
		tmp = mHead; //assigns mHead to tmp to avoid changing mHead

		while (tmp != NULL) //cycles throught all nodes
		{
			cout << tmp->mData << endl; //outputs int object using overload
			tmp = tmp->mNext; //sets the temporary object to the next node
		}
	}
}

/**********************************************************************
**Pre: integer to insert
**Post: integer is appended to the end of the list, bool returned
**Purpose: to add a object to the end of a list and return if successful
**********************************************************************/
bool NumberList::insert(int data)
{
	Node *newNode;

	if (mHead == NULL) //list is empty
	{
		mHead = new Node(data); //create new node with data and makes it mHead
		if (mHead == NULL) //if there is nothing in data, return false
			return false;

		mTail = mHead; //since its the first and only item, the tail is the same a mHead

		linkCount++; //increased the link count to 1
	}
	else //list already exiists
	{
		if (isExist(data)) //if there is duplicte data, return false
			return false;

		newNode = new Node(data); //creates newNode with integer data
		if (newNode == NULL) //if there is nothing in data, return false
			return false;

		mTail->mNext = newNode; //sets the next node to the int data
		mTail = newNode; //since it is adding to the back, this is the new tail

		linkCount++; //increase the link count by one
	}

	return true; //returns true if data passes all clauses

}

/**********************************************************************
**Pre: integer to insert, index
**Post: integer is added to the index provided bool returned
**Purpose: to add a object to the specified index and return if successful
**********************************************************************/
bool NumberList::insert(int index, int data)
{
	Node* prev = new Node();
	Node* curr = new Node();
	Node* newNode = new Node();
	newNode->mData = data;
	bool pass = false;

	int tempPos = 0;   // Traverses through the list

	curr = mHead;      // Initialize current to head;
	if (mHead != NULL)
	{
		while (curr->mNext != NULL && tempPos != index) // Goes through all nodes until index
		{
			prev = curr; 
			curr = curr->mNext;
			tempPos++;
		}
		if (index == 0) // Add at head
		{
			cout << "Adding at Head! " << endl;
			newNode->mNext = mHead;
			mHead = newNode;
			pass = true;
		}
		else if (curr->mNext == NULL && index == tempPos + 1) // Add at the tail
		{
			cout << "Adding at Tail! " << endl;
			mTail->mNext = newNode; //sets the next node to the int data
			mTail = newNode; //since it is adding to the back, this is the new tail
			mTail->mNext = NULL;
			pass = true;
		}
		else if (index > tempPos + 1) // If index is out of bounds
		{
			cout << " Position is out of bounds " << endl;
			pass = false;
		}
		else // If everything checks out, add node at the index
		{
			prev->mNext = newNode;
			newNode->mNext = curr;
			cout << "Node added at position: " << index << endl;
			pass = true;
		}
	}
	else // If the list was empty, create one and add at head
	{
		mHead = newNode;
		newNode->mNext = NULL;
		cout << "Added at head as list is empty! " << endl;
		pass = true;
	}

	return pass;
}


/**********************************************************************
**Pre: integer you are looking for
**Post: boolean value returned
**Purpose: cycle through all of the nodes and see if searchKey is there
**********************************************************************/
bool NumberList::isExist(int searchKey)
{
	bool found = false; //default bool value
	Node *tmp; //temporary node object

	if (mHead != NULL) //if the list is not empty
	{
		tmp = mHead; //tmp is set to mHead to preserve mHead location

		while (tmp != NULL) //cycles through all nodes
		{
			if (tmp->mData == searchKey) // if the integer data in tmp is = to searchKey
			{
				found = true; //return true
				break; //if true, break from loop
			}
			tmp = tmp->mNext; //if not that node, set tmp to next node
		}
	}

	return found; //return if searchKey was found or not
}

/**********************************************************************
**Pre: NumberList has been created, not necessarily filled
**Post: delete first node
**Purpose: first node is deleted, and mHead is moved to the next location
**********************************************************************/
int NumberList::remove()
{
	int data = 0; //creates int object to catch returning int data
	Node *tmp; //temporary node to keep the contents of mHead before deletion

	if (mHead != NULL) //if list is not empty
	{
		tmp = mHead; //save mHead for later
		mHead = mHead->mNext; //mode mHead to the next node
		tmp->mNext = NULL; //disconnect tmp from the link

		data = tmp->mData; //save the data from tmp to return later
		delete tmp; //delete the pointer

		if (mHead == NULL) //if the list is now empty
			mTail = NULL; //set the tail to empty as well

		linkCount--; //decrease the link count by 1
	}

	return data; //return the data deleted
}