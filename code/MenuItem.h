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

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <iostream>			//remove #includes and namespace as needed, they're for my own use before integrating files
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

enum
	Category {appetizer, entree, dessert, beverage};

struct MenuItem
{
private:

	double
		price;
	string
		description,
		itemName;
	Category
		category;

	//====================

public:

	MenuItem();
	MenuItem(string name, double pr, string desc, int cat);
	~MenuItem();

	int compareTo(MenuItem item);
	void display();
	void displayFull();
	Category getCategory();
	string getDescription();
	string getName();
	double getPrice();
	void operator=(const MenuItem& rhs);
	bool operator==(const MenuItem& rhs);
	bool operator==(string name);
	void setCategory(int newCat);
	void setDescription(string newDesc);
	void setName(string newName);
	void setPrice(double newPrice);

	friend istream& operator>>(istream& input, MenuItem& info);
	friend ostream& operator<<(istream& lhs, MenuItem& rhs);
	friend ifstream& operator>>(ifstream& lhs, MenuItem& rhs);
	friend ofstream& operator<<(ofstream& lhs, MenuItem& rhs);
};

#endif