/*
* Author: Evan Nudd
*
* Class: NA (Applicable in all courses)
*
* Assignment: NA (Self made project to be used in any assignment.)
*
* Date Assigned: 1NA
*
* Due Date: NA
*
*
* Description:
*  Functions heads for the IOComm (Input Output Communicator) class. This class
*  is designed to make obtaining information for assignments cleaner and faster.
*  This class will handle alot of the error checking for you to assure that when
*  you reqpuest a particular type of response you will recieve it.
*
* Certification of Authenticity:
* I certify that this is entirely my own work,
* except where I have given fully- documented references
* to the work of others. I understand the definition and
* consequences of plagiarism and acknowledge that the assessor
* of this assignment may, for the purpose of assessing
* this assignment:
*
* -  Reproduce this assignment and provide a copy to another
* member of academic staff; and/or
*
*-  Communicate a copy of this assignment to a plagiarism
* checking service (which may then retain a copy of this
* assignment on its database for the purpose of future plagiarism
* checking)
*
*/
#ifndef IOCOMM_H
#define IOCOMM_H

#include <iostream>
#include <conio.h>
#include <string>

const int BACKSPACE_KEY_VALUE = 127;
const int DELETE_KEY_VALUE = 8;
const int ENTER_KEY_VALUE = 13;

const int TELEPHONE_LENGTH = 10;
const int SSN_LENGTH = 9;

class IOComm
{

private:
	void attemptBackspace(std::string &responseToReduce);

	void consoleBackspace();

	bool isBackspaceEntered(char input);

	int sizeToInt(const std::string input);

	char getMaskedChar();

public:
   IOComm();
   ~IOComm();
   
   std::string getAlphaNumericResponse();

   std::string getAlphaNumericResponseOr(const char otherKeys[], int size);

   std::string getAlphaResponse();

   std::string getAlphaResponse(bool spaces);

   std::string getAlphaResponseOr(const char otherkeys[], int size);

   char getCharResponse(const char options[], int optionSize);

   std::string getMaskedResponse();

   std::string getFirstName();

   std::string getLastName();

   std::string getName();

   std::string getName(std::string &firstName, std::string &lastName);

   std::string getNumericResponse();

   std::string getNumericResponse(int size);

   std::string getSSN();

   std::string getTelephoneNumber();
};

#endif