/*
Author: RJ Robbins
Class: Advanced Programming
Assignment: Final Project
Date Assigned: 3/17/15
Due Date: 4/24/15 11:00AM

Description: This file simply creates the structure for MenuItem objects.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

#include "MenuItem.h"

static const int MenuItem_WIDTH = 13;

MenuItem::MenuItem()
{

}

MenuItem::MenuItem(string name, double pr, string desc, int cat)
{
	itemName = name;
	price = pr;
	description = desc;

	switch (cat)
	{
	case 0:
		category = appetizer;
		break;
	case 1:
		category = entree;
		break;
	case 2:
		category = dessert;
		break;
	case 3:
		category = beverage;
		break;
	default:			//remains uncategorized
		break;
	}
}

MenuItem::~MenuItem()
{

}

int MenuItem::compareTo(MenuItem item)			//compares 2 MenuItems alphabetically
{
	//if (category == item.getCategory() && price == item.getPrice())
	//	if (itemName.compare(item.itemName) < 0)
	//		return -1;			//the original item is alphabetically after the parameter item
	//	else if (itemName.compare(item.itemName) > 0)
	//		return 1;			//the original item is alphabetically before the parameter item
	//	else
	//		return 0;			//the original item is the same as the parameter item
	//
	//return -2;			//not in same categories and/or have different prices

	if (itemName < item.itemName)
		return 1;
	else if (itemName > item.itemName)
		return -1;

	return 0;
}

void MenuItem::display()			//outputs name and price of an item on 1 line
{
	//cout << itemName << " $" << price << endl;

	cout << left << setw(12) << itemName << right << setw(8) << price << endl;
}

void MenuItem::displayFull()			//outputs name and price of an item on 1 line and the item's description on the next
{
	//cout << itemName << " $" << price << endl << description << endl;

	cout << left << setw(12) << itemName << right << setw(8) << price << endl;
	cout << description << endl;
}

Category MenuItem::getCategory()
{
	return category;
}

string MenuItem::getDescription()
{
	return description;
}
	
string MenuItem::getName()
{
	return itemName;
}
	
double MenuItem::getPrice()
{
	return price;
}

void MenuItem::operator=(const MenuItem& rhs)			//sets all variables in the lhs MenuItem to the values of the rhs ones
{
	itemName = rhs.itemName;
	price = rhs.price;
	description = rhs.description;
	category = rhs.category;
}

bool MenuItem::operator==(const MenuItem& rhs)			//checks if the name of the lhs MenuItem == the name of the rhs one
{
	if (itemName == rhs.itemName)
		return true;
		
	return false;
}

bool MenuItem::operator==(string name)			//checks if the name of the lhs MenuItem == an inputted name
{
	if (itemName == name)
		return true;

	return false;
}

void MenuItem::setCategory(int newCat)
{
	switch (newCat)
	{
	case 0:
		category = appetizer;
		break;
	case 1:
		category = entree;
		break;
	case 2:
		category = dessert;
		break;
	case 3:
		category = beverage;
		break;
	default:
		break;
	}
}

void MenuItem::setDescription(string newDesc)
{
	description = newDesc;
}
	
void MenuItem::setName(string newName)
{
	itemName = newName;
}

void MenuItem::setPrice(double newPrice)
{
	price = newPrice;
}

//====================

istream& operator>>(istream& input, MenuItem& info)
{
	int catNum;
	string tmp;

	cout << setw(12) << "Enter name:  ";
	getline(input, info.itemName);

	cout << setw(12) << "Enter item category by number:  ";
	input >> catNum;
	getline(input, tmp);
	info.setCategory(catNum);

	cout << setw(12) << "Enter price:  ";
	input >> info.price;
	getline(input, tmp);

	cout << setw(12) << "Enter description:  ";
	getline(input, info.description);

	return input;
}

ostream& operator<<(ostream& output, MenuItem info)
{
	output << setw(MenuItem_WIDTH) << "MenuItem ID:  "
		<< info.getName() << endl
		<< setw(MenuItem_WIDTH) << "MenuItem category:  "
      << info.getCategory() << endl
		<< setw(MenuItem_WIDTH) << "MenuItem price:  "
      << info.getPrice() << endl;

	return output;
}

ifstream& operator>>(ifstream& lhs, MenuItem& rhs)
{
	int i;
	string s;

	getline(lhs, rhs.itemName);

	lhs >> rhs.price;
	getline(lhs, s);

	getline(lhs, rhs.description);

	lhs >> i;
	getline(lhs, s);

	if (i == 0)
		rhs.category = appetizer;
	else if (i == 1)
		rhs.category = entree;
	else if (i == 2)
		rhs.category = dessert;
	else if (i == 3)
		rhs.category = beverage;			//reamins NULL for any other values (-1)

	getline(lhs, s);

   return lhs;
}

ofstream& operator<<(ofstream& lhs, MenuItem& rhs)
{
	lhs << rhs.itemName << endl;
	lhs << rhs.price << endl;
	lhs << rhs.description << endl;

	if (rhs.category == appetizer)
		lhs << 0 << endl;
	else if (rhs.category == entree)
		lhs << 1 << endl;
	else if (rhs.category == dessert)
		lhs << 2 << endl;
	else if (rhs.category == beverage)
		lhs << 3 << endl;
	else
		lhs << -1 << endl;			//if rhs.category is NULL

	lhs << endl;			//spaces between objects in file

   return lhs;
};