#include "Cook.h"

/*
Constructor
-Author: Toby Ingmire
-Prototype: Cook::Cook() : Employee()
-Pre: None
-Post: Initialize the cook variables
-Purpose: To initialize the variables of
cook.
*/
Cook::Cook() : Employee()
{

}

/*
Deconstructor
-Author: Toby Ingmire
-Prototype: Cook::~Cook()
-Pre: None
-Post: To deconstruct the cook
-Purpose: To deconstruct the cook
*/
Cook::~Cook()
{

}

/*
Get Employee Type
-Author: Evan Nudd
-Prototype: int Cook::getEmployeeType()
-Pre: None
-Post: Return employee type of Cook
-Purpose: To return the cooks employee
type
*/
int Cook::getEmployeeType()
{
	return EMPLOYEE_TYPE::COOK;
}

