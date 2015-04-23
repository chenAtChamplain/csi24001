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

#include "Table.h"


Table::Table()
{
    mNumberOfSeats = 0;
    mSeatsOccupied = 0;
    mWaiterID = "";
}

Table::Table(unsigned int numberOfSeats, std::string waiterID)
{
    mNumberOfSeats = numberOfSeats;
    mSeatsOccupied = 0;
    mWaiterID = waiterID;
}

Table::~Table()
{
    
}

/*
 *PRE: Nothing
 *
 *POST: number of seats is returned
 *
 *PURPOSE: to return the number of seats
 *
 ********************************************************/
unsigned int Table::getNumberOfSeats()
{
    return mNumberOfSeats;
}

/*
 *PRE: unsigned int representing the number of seats
 *
 *POST: Nothing
 *
 *PURPOSE: number of seats is set
 *
 ********************************************************/
void Table::setNumberOfSeats(unsigned int seats)
{
    mNumberOfSeats = seats;
}

LinkedList& Table::getOrders()
{
	return mOrders;
}

/*
 *PRE: Nothing
 *
 *POST: number of seats occupied is returned
 *
 *PURPOSE: to get the number of seats
 *
 ********************************************************/
unsigned int Table::getSeatsOccupied()
{
    return  mSeatsOccupied;
}

/*
 *PRE: number of people
 *
 *POST: Nothing
 *
 *PURPOSE: sets the number of seats occupied to the number of peole
 *
 ********************************************************/
void Table::setSeatsOccupied(unsigned int people)
{
    mSeatsOccupied = people;
}

/*
 *PRE: Nothing
 *
 *POST: whether its occupied or not
 *
 *PURPOSE: to tell if the table is occupied
 *
 ********************************************************/
bool Table::isOccupied()
{
    return (mSeatsOccupied > 0);
}

/*
 *PRE: a string representing the waiters id
 *
 *POST: Nothing
 *
 *PURPOSE: to set the tables waiter id
 *
 ********************************************************/
void Table::setWaiterID(std::string waiterID)
{
    mWaiterID = waiterID;
}

/*
 *PRE: Nothing
 *
 *POST: waiter id is returned
 *
 *PURPOSE: to return the waiters id
 *
 ********************************************************/
std::string Table::getWaiterID()
{
    return mWaiterID;
}

/*
 *PRE: Nothing
 *
 *POST: Nothing
 *
 *PURPOSE: to display orders of the table
 *
 ********************************************************/
void Table::displayOrder()
{
    mOrders.display();
}

/*
 *PRE: a menu item
 *
 *POST: Nothing
 *
 *PURPOSE: to add a menu item to the tables orders
 *
 ********************************************************/
void Table::addToOrder(MenuItem item)
{
    mOrders.insertInOrder(item);
}

/*
 *PRE: an order as a string
 *
 *POST: Nothing
 *
 *PURPOSE: to remove an order from the table
 *
 ********************************************************/
void Table::removeFromOrder(std::string order)
{
    mOrders.remove(order);
}

/*
 *PRE: Nothing
 *
 *POST: whether an order exists
 *
 *PURPOSE: to return if an order exists
 *
 ********************************************************/
bool Table::orderExists()
{
    return !mOrders.empty();
}

/*
 *PRE: Nothing
 *
 *POST: the total is returned
 *
 *PURPOSE: to return the total
 *
 ********************************************************/
double Table::calculateBill()
{
    return mOrders.subTotalOrder();
}

MenuItem Table::popItem()
{
	return mOrders.pop();
}

