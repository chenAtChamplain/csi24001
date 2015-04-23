/*
 
 Author: Nicholas Boyle
 Class: CSI-240-01
 Assignment: FINAL PROJECT
 Date Assigned: 3/17/15
 Due Date: 4/24/15 11:00AM
 
 Description:
 A class for organizing table data for a restaurant program
 
 Certification of Authenticity:
 I certify that this is entirely my own work, except where I have given fully
 documented references to the work of others. I understand the definition and
 consequences of plagiarism and acknowledge that the assessor of this assignment
 may, for the purpose of assessing this assignment:
 -Reproduce this assignment and provide a copy to another member of
 academic staff; and/or
 -Communicate a copy of this assignment to a plagiarism checking service
 (which may then retain a copy of this assignment on its database for
 the purpose of future plagiarism checking)
 */

#ifndef __TABLE_H__
#define __TABLE_H__

#include "LinkedList.h"



class Table
{
private:
    unsigned int mNumberOfSeats;
    unsigned int mSeatsOccupied;
	string mWaiterID;
    LinkedList mOrders;

    
public:
	Table();
	~Table();
	Table(unsigned int numberOfSeats, std::string waiterID);
	double Table::calculateBill();
    unsigned int getNumberOfSeats();
	LinkedList& getOrders();
	unsigned int getSeatsOccupied();
	string getWaiterID();
	void addToOrder(MenuItem item);
	void displayOrder();
	bool isOccupied();
	void loadTableFromFile();
	bool orderExists();
	MenuItem popItem();
	void removeFromOrder(std::string order);
    void setNumberOfSeats(unsigned int seats);
    void setSeatsOccupied(unsigned int seats);
	void Table::setWaiterID(std::string waiterID);
	void saveTableToFile();


    
};



#endif
