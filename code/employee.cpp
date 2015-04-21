/*
Author: Matthew Fortier
CSI-240-01
Final Project

Due: 04/24/2015

Employee function implementation

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

#include "employee.h"
#include "IOComm.h"

/********************************************************
**Pre: none
**Post: default object is created
**Purpose: define an employee object with default values
**Author: Matthew Fortier
********************************************************/
Employee::Employee()
{
	mName = " ";
	mAddress = " ";
	mPhoneNumber = " ";
	mSSN = " ";
	mPay = 0;
	mEmployeeType = -1;
}

/********************************************************
**Pre: values available to be parameters
**Post: object created with specified values
**Purpose: define an employee object with given values
**Author: Matthew Fortier
********************************************************/
Employee::Employee(string name, string address, string phoneNumber, string ssn,int employeeType, double pay)
{
	mName = name;
	mAddress = address;
	mPhoneNumber = phoneNumber;
	mSSN = ssn;
	mPay = pay;
	mEmployeeType = employeeType;
}
 
/********************************************************
**Pre: none
**Post: none
**Purpose: delete the object when out of scope
**Author: Matthew Fortier
********************************************************/
Employee::~Employee()
{

}

/********************************************************
**Pre: variable to catch return
**Post: employee pay is returned
**Purpose: to access private data from employee object
**Author: Matthew Fortier
********************************************************/
double Employee::getPay()
{
	return mPay;
}

/********************************************************
**Pre: variable to catch return
**Post: employee address is returned
**Purpose: to access private data from employee object
**Author: Matthew Fortier
********************************************************/
string Employee::getAddress()
{
	return mAddress;
}


int Employee::getEmployeeType()
{
   return mEmployeeType;
}

/********************************************************
**Pre: variable to catch return
**Post: employee name is returned
**Purpose: to access private data from employee object
**Author: Matthew Fortier
********************************************************/
string Employee::getName()
{
	return mName;
}

/********************************************************
**Pre: variable to catch return
**Post: employee phone number is returned
**Purpose: to access private data from employee object
**Author: Matthew Fortier
********************************************************/
string Employee::getNumber()
{
	return mPhoneNumber;
}

/********************************************************
**Pre: variable to catch return
**Post: employee pay is returned
**Purpose: to access private data from employee object
**Author: Matthew Fortier
********************************************************/
string Employee::getSSN()
{
	return mSSN;
}

/********************************************************
**Pre: none
**Post: address is set
**Purpose: to set private data in the employee object
**Author: Matthew Fortier
********************************************************/
void Employee::setAddress(string address)
{
	mAddress = address;
}

/********************************************************
**Pre: none
**Post: Name is set
**Purpose: to set private data in the employee object
**Author: Matthew Fortier
********************************************************/
void Employee::setName(string name)
{
	mName = name;
}

/********************************************************
**Pre: none
**Post: phoneNumber is set
**Purpose: to set private data in the employee object
**Author: Matthew Fortier
********************************************************/
void Employee::setNumber(string phoneNumber)
{
	mPhoneNumber = phoneNumber;
}

/********************************************************
**Pre: none
**Post: pay is set
**Purpose: to set private data in the employee object
**Author: Matthew Fortier
********************************************************/
void Employee::setPay(double pay)
{
	mPay = pay;
}

/********************************************************
**Pre: none
**Post: SSN is set
**Purpose: to set private data in the employee object
**Author: Matthew Fortier
********************************************************/
void Employee::setSSN(string ssn)
{
	mSSN = ssn;
}

/********************************************************
**Pre: none
**Post: none
**Purpose: none
**Author: Matthew Fortier
********************************************************/
void Employee::displayOptions()
{

}

/********************************************************
**Pre: none
**Post: none
**Purpose: none
**Author: Matthew Fortier
********************************************************/
void Employee::operate()
{

}

ostream& operator << (ostream& output, Employee obj)
{
	cout << "Employee Name: " << right << setw(SPACING-8) << obj.mName << endl;
	cout << "Employee Address: " << right << setw(SPACING) << obj.mAddress << endl;
	cout << "Employee Phone Number: " << right << setw(SPACING-10) << obj.mPhoneNumber << endl;
	cout << "Employee SSN: " << right << setw(SPACING-2) << obj.mSSN << endl;
	cout << "Employee Pay/Salary: " << right << setw(SPACING-17) << obj.mPay << endl;

	switch (obj.mEmployeeType)
	{
		case MANAGER:
			cout << "Employee Type: " << right << setw(SPACING-7) << "Manager" << endl;
			break;
		case HOST:
			cout << "Employee Type: " << right << setw(SPACING-10) << "Host" << endl;
			break;
		case WAITER:
			cout << "Employee Type: " << right << setw(SPACING-8) << "Waiter" << endl;
			break;
		case COOK:
			cout << "Employee Type: " << right << setw(SPACING-10) << "Cook" << endl;
			break;
		default:
			cout << "Employee Type: " << right << setw(SPACING+7) << "Employee Type Not Set" << endl;
	}

	return output;
}

ofstream& operator << (ofstream& output, Employee obj)
{
	output << obj.mName << endl;
	
	switch (obj.mEmployeeType)
	{
		case MANAGER:
			output << "Manager" << endl;
			break;
		case HOST:
			output << "Host" << endl;
			break;
		case WAITER:
			output << "Waiter" << endl;
			break;
		case COOK:
			output << "Cook" << endl;
			break;
		default:
			output << "Employee Type Not Set" << endl;
	}
	
	output << obj.mSSN << endl;
	output << obj.mPhoneNumber << endl;
	output << obj.mAddress << endl;
	output << obj.mPay << endl;

	output.close();

	return output;
}

istream& operator >> (istream& input, Employee& obj)
{
	string temp;
	double temp2;
	IOComm tmp;

	const char chars[] = { ' ' };

	temp = tmp.getName();
	obj.mName = temp;
	cout << endl;

	cout << "Enter Address: ";
	temp = tmp.getAlphaNumericResponseOr(chars,1);
	obj.mAddress = temp;

	cout << endl;

	cout << "Enter Employee Phone Number: ";
	temp = tmp.getTelephoneNumber();
	obj.mPhoneNumber = temp;

	cout << endl;

	cout << "Enter Employee Social Security Number: ";
	temp = tmp.getSSN();
	obj.mSSN = temp;

	cout << endl;

	cout << "Enter Employee Pay: ";
	while (!(cin >> temp2))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	obj.mPay = temp2;

	cout << "Enter Employee Type i.e Cook Waiter Host Manager: ";
	temp = tmp.getAlphaResponse();
	if (temp == "Cook" || temp == "cook")
	{
		obj.mEmployeeType = COOK;
	}
	else if (temp == "Waiter" || temp == "waiter")
	{
		obj.mEmployeeType = WAITER;
	}
	else if (temp == "Host" || temp == "host")
	{
		obj.mEmployeeType = HOST;
	}
	else
	{
		obj.mEmployeeType = MANAGER;
	}

	cout << endl;

	return input;
}

ifstream& operator >>(ifstream& input, Employee& obj)
{
	return input;
}