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



unsigned int Table::getNumberOfSeats()
{
    return mNumberOfSeats;
}

void Table::setNumberOfSeats(unsigned int seats)
{
    mNumberOfSeats = seats;
}

unsigned int Table::getSeatsOccupied()
{
    return  mSeatsOccupied;
}

void Table::setSeatsOccupied(unsigned int people)
{
    mSeatsOccupied = people;
}

bool Table::isOccupied()
{
    return (mSeatsOccupied > 0);
}

LinkedList& Table::getOrders()
{
    return mOrders;
}