#include "linkedList.h"
#include "menuItem.h"

/* CONSTRUCTOR
 Pre: nothing
 Post: LinkedList is constructed
 Purpose: to construct LinkedList
 Author: Johnna Ferguson and Dan Thomas
 */
LinkedList::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
}

/*
 DESTRUCTOR
 Pre: a LinkedList
 Post: LinkedList is destroyed
 Purpose: to prevent memory leakage
 Author: Johnna Ferguson and Dan Thomas
 */
LinkedList::~LinkedList()
{
	while (mHead != NULL)
	{
		pop();
	}
	
}


/*
 Pre: a linked list
 Post: contents of linked list are displayed to console
 Purpose: to display menu for bill
 NOTE:  one item per line, as in receipt or kitchen cook list
 Author: Dan Thomas
 */
void LinkedList::display() 
{
	Node *tmp;
	if (mHead != NULL)
	{
		tmp = mHead;
		
		while (tmp != NULL)
		{
			tmp->mData.display();
			tmp = tmp->mNext;
		}
	}
}

/*
 Pre: a linked list
 Post: full contents of linked list, including description are displayed 
       to console, including description.
 Purpose: to display all menuItem information, as to print a menu for customers
 Author: Johnna Ferguson
 */
void LinkedList::displayFull() 
{
	Node *tmp;
	if (mHead != NULL)
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			tmp->mData.displayFull();
			cout << endl;
			tmp = tmp->mNext;
		}
	}
	
}

/*
 Pre: a linked list
 Post: returns bool true if empty
 Purpose: to know if any food has been ordered
 Author: Johnna Ferguson
*/
bool LinkedList::empty()
{
	if (mHead != NULL)
		return false;
	else
		return true;
}

/*
 Pre: a linked list and a menuItem name.
 Post: returns true if a menuItem of that name is already in list
 Purpose: to check if that menuItem is already in list
 Author: Johnna Ferguson
 */
bool LinkedList::isExist(string name)
{
	bool found = false;
	Node *tmp;
	
	if (mHead != NULL)
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			if (tmp->mData == name)
			{
				found = true;
				break;
			}
			tmp = tmp->mNext;
		}
	}
	return found;
}

/*
Pre: the name of the menuItem wanted from the list
Post: returns full MenuItem
Purpose: to retrieve all item data when adding to a table order
Author: Johnna Ferguson
*/
MenuItem LinkedList::getItem(string itemName)
{
	MenuItem item("item not found", 0.0, itemName, 3);
	Node *tmp;

	if (mHead != NULL)
	{
		tmp = mHead;
		while (tmp != NULL)
		{
			if (tmp->mData == itemName)
			{
				item = tmp->mData;
				break;
			}
			tmp = tmp->mNext;
		}
	}
	return item;

}

/*
pre: a menuItem and a Linked List to insert into
post: the menuItem is inserted into the linked list
purpose: to build a sorted linked list
NOTE: ALLOWS DUPLICATION
NOTE: order of sort set by: int MenuItem::compareTo(MenuItem)
CREDIT: Gaddis et al. textbook page 1033-4
Author: Johnna Ferguson
*/
bool LinkedList::insertInOrder(MenuItem data)
{
	Node *newNode, *ptr, *previousNodePtr;

	if (mHead == NULL) // empty LinkedList
	{
		mHead = new Node(data);
		if (mHead == NULL)
		{
			return false; // not enough memory for a newNode
		}
		else
		{
			mTail = mHead; // Linked List of one node
		}
	}
	else if (mHead->mData.compareTo(data) <= 0) // insert before Head
	{
		newNode = new Node(data);
		if (newNode == NULL)
		{
			return false; // not enough memory for a new Node
		}
		else
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
	}
	else
	{
		previousNodePtr = mHead;
		ptr = mHead->mNext;

		// find right place to insert
		while (ptr != NULL && ptr->mData.compareTo(data) > 0) 
		{
			previousNodePtr = ptr;
			ptr = ptr->mNext;
		}
		newNode = new Node(data);
		if (newNode == NULL)
		{
			return false;
		}
		else
		{
			newNode->mNext = ptr;  
			previousNodePtr->mNext = newNode;
			if (newNode->mNext == NULL) // check to move Tail
			{
				mTail = newNode;
			}
		}
	}
	return true;
}

/*
pre: a menuItem and a Linked List to insert into
post: the menuItem is inserted into the linked list
purpose: to build a sorted linked list
NOTE: NO DUPLICATION
Author: Johnna Ferguson
*/
bool LinkedList::insertInOrderNoRepeat(MenuItem data)
{
	if (isExist(data.getName()))
	{
		return false;
	}
	else
		return insertInOrder(data);
}

/*
pre: file with menu data
post: LinkedList is populated with data from file
purpose: to have a default restaurant menu based on last save
Author: Johnna Ferguson
*/
void LinkedList::loadData()
{

	MenuItem item;

	ifstream fin(SAVED_MENU);

	if (!fin.fail())
	{
		while (!fin.eof())
		{
			fin >> item;
			push(item);
		}
	}
	else
	{
		cout << "Saved Menu Not Found\n";
	}

	fin.close();
}

/*
 Pre: a linked list
 Post: one menuItem is removed from HEAD of list
 Purpose: to remove first object from list.
 Johnna Ferguson
 */
MenuItem LinkedList::pop()
{
	MenuItem data = MenuItem();
	Node *tmp; //pointer
	
	if (mHead != NULL) // check list not empty
	{
		tmp = mHead;
		mHead = mHead->mNext;
		tmp->mNext = NULL; //detaches from LinkList
		data = tmp->mData;
		
		delete tmp;
		
		if (mHead == NULL)
		{
			mTail = NULL; //  empty list should have null pointers
		}
		
	}
	return data;
}

/*
 Pre: a menuItem
 Post: the menuItem is added to the HEAD of LinkedList
 Purpose: to add a menuItem to LinkedList
 NOTE: function will only add menuItems with unique itemNames,
 esp for use in a masterMenu of what dishes are on the menu for the day
 Author: Johnna Ferguson
 */
bool LinkedList::push(MenuItem data) //no duplicates
{
	Node *newNode;
	
	if (mHead == NULL) // empty LinkedList
	{
		mHead = new Node(data);
		if (mHead == NULL)
		{
			return false; // not enough memory for a newNode
		}
		else
		{
			mTail = mHead; // Linked List of one node
		}
	}
	else
	{
		if (isExist(data.getName()))
		{
			return false; // check for duplication
		}
		
		newNode = new Node(data);
		if (newNode == NULL)
		{
			return false; //not enough memory for a newNode
		}

		newNode->mNext = mHead;
		mHead = newNode;
	}
	return true;
}

/*
 IN PROGRESS
 Pre: a menuItem
 Post: the menuItem is added to the HEAD of LinkedList
 Purpose: to add a menuItem to LinkedList
 NOTE: allows duplicates, as for a table order, a dish can be ordered 
       more than once.
Author: Dan Thomas
 */
bool LinkedList::pushOrder(MenuItem item)
{
	return false;
}

/*
	IN PROGRESS
 Pre: a menuItem
 Post: the menuItem is removed from the LinkedList FIRST OCCURENCE IS REMOVED!
 Purpose: to remove a menuItem from the LinkedList
 NOTE: duplicates are okay to just remove any one.
 Author: Dan Thomas
 */
bool LinkedList::remove(string name)
{
	//IN PROGRESS
	return false;
}

/*
Pre: a linked list of menu items
Post: menu item data is saved to file
Purpose: to save restaurant menu or table orders to file
Author: Johnna Ferguson
*/
void LinkedList::saveData()
{

	ofstream fout(SAVED_MENU);

	Node* iter;
	iter = mHead;

	while (iter != NULL)
	{
		fout << iter->mData;
		iter = iter->mNext;
	}

	fout.close();

}

/*
 IN PROGRESS
 Pre: a menuItem
 Post: the menuItem is searched for existence in the LinkedList
 Purpose: to see if the menuItem exists in the LinkedList
 NOTE SAME AS isExist(name) !!!
 Author: Dan Thomas
 */
bool LinkedList::search(string name)
{
	return false;
} 

/*
 IN PROGRESS 
 Pre: a linked list
 Post: sorts list by category, then by price, then by name
 Purpose: so list will be in order for kitchen or bill printing or 
          customer menu.
 Note: relies on MenuItem::compareTO() for order of sort.
 Author: Dan Thomas
 */
void LinkedList::sort()
{

}

/*
Pre: nothing
Post: returns double representing subTotal of order
Purpose: to support calculating a bill
NOTE: does not include tax rate or tip
Author: Johnna
*/
double LinkedList::subTotalOrder()
{
	double subTotal = 0.0;
	Node *iter;

	if (mHead != NULL)
	{
		iter = mHead;
		while (iter != NULL)
		{
			subTotal = subTotal + iter->mData.getPrice();
			iter = iter->mNext;
		}
	}
	return subTotal;
}

/*
Pre: a linked list
Post: a ofstream that could be saved to file by another function
Purpose: to support saving Tables with orders to file
Author: Johnna Ferguson
*/
ofstream& operator<<(ofstream& output, LinkedList& obj)
{
	output.setf(ios::fixed | ios::showpoint);
	output.precision(2);

	LinkedList::Node* iter;

	if (obj.mHead != NULL)
	{
		iter = obj.mHead;
		while (iter != NULL)
		{
			output << iter->mData;
			iter = iter->mNext;
		}
	}
	return output;
}


/*
Pre:
Post:
Purpose: to support reading LinkedList data from file,
such as restoring data after power outtage
NOTE: '#' marks the end of table order info in file
HELPER FUNCTION TO RESTAURANT::RESTORE TABLE STATES
Author: Johnna Ferguson
*/
ifstream& operator>>(ifstream& input, LinkedList& obj)
{
	MenuItem item;
	char ch;

		ch = input.peek();
		while (!input.eof() && (ch != '#'))
		{
			input >> item;
			obj.insertInOrder(item);
			ch = input.peek();
		}

	return input;
}