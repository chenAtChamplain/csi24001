/*
Author: Toby Ingmire
Class: CSI-240-01
Assignment: Final
Date Assigned: April 3, 2015
Due Date: April 24, 2015 @ 11:00AM

Description:

The purpose of this program is to set up a new POS system
for a new resturaunt named Wei's Place. The POS system should
allow different stakeholders to perform unique tasks designated
to their position.

Certification of Authenticity:

I certify that this is entirely my own work, except
where I have given fully-documented references to the
work of others. I understand the definition and consequences
of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:

- Reproduce this assignment and provide a copy to another member
of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

#ifndef _COOK_H
#define _COOK_H

#include "Employee.h"

#include <iostream>
#include <iomanip>


using namespace std;

class Cook: public Employee
{
public:
	Cook();
	~Cook();

	virtual int getEmployeeType();
};
#endif