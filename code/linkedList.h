#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include "menuItem.h"
using namespace std;

class LinkedList
{
private:
	struct Node
	{
		MenuItem mData;
		Node *mNext;
		
		Node()
		{
			mNext = NULL;
		}
		
		Node(MenuItem value)
		{
			mData = value;
			mNext = NULL;
		}
	};
	
	Node *mHead, *mTail;
	
public:

	const string SAVED_MENU = "menu.txt";

	LinkedList();
	~LinkedList();
	void display(); // one item per line, as in receipt
	void displayFull(); // displays all elements of menuItems, 
	                    // including description
	bool empty(); //returns true if the the list is empty
	MenuItem getItem(string itemName);
	bool insertInOrder(MenuItem data);
	bool insertInOrderNoRepeat(MenuItem data);
	bool isExist(string name); // helper for push without duplicates
	void loadData();
	MenuItem pop(); // just in case
	bool push(MenuItem item); //no duplicates
	bool pushOrder(MenuItem item); //allows duplicates
	bool remove(string name); // so the waiter can take something off an order
	void saveData();
	bool search(string name);
	void sort(); // sorts list by category and then price then name
	double subTotalOrder(); // sum before taxes and tip

	friend ofstream& operator<<(ofstream& output, LinkedList& obj);
	friend ifstream& operator>>(ifstream& input, LinkedList& obj);

};

#endif