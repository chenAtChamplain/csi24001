/*
Author: Matthew Fortier
CSI-240-01
Final Project

Due: 04/24/2015

Employee function declarations

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

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

enum EMPLOYEE_TYPE {
	MANAGER = 0,
	HOST,
	WAITER,
	COOK
};

const int SPACING = 25;

class Employee
{
protected:
	string mName;
	string mAddress;
	string mPhoneNumber;
	string mSSN;
	double mPay;

	int mEmployeeType;

public:
	Employee();
	Employee(string name, string address, string phoneNumber, string ssn, int employeeType, double pay);
	~Employee();

	//getters
	double getPay();

	string getAddress();	
   int    getEmployeeType();
	string getName();
	string getNumber();
	string getSSN();

	//setters
	void setAddress(string address);
	void setName(string name);
	void setNumber(string phoneNumber);
	void setPay(double pay);
	void setSSN(string ssn);

	virtual void displayOptions();
	virtual void operate();

	friend ostream& operator <<(ostream& output, Employee obj);
	friend ofstream& operator <<(ofstream& output, Employee obj);

	friend istream& operator >>(istream& input, Employee& obj);
	friend ifstream& operator >>(ifstream& input, Employee& obj);
};


#endif