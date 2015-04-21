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
*  Functions bodies for the IOComm (Input Output Communicator) class. This class 
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
#include "IOComm.h"


IOComm::IOComm()
{
}


IOComm::~IOComm()
{
}


/*
* Pre: string val passed in is going to be manipulated, be aware of this.
*
* Post: The string size is reduced by 1 (removing the final char) and the 
*       console will move backwards and clear 1 space. If responseToReduce is 
*       == 0 than it will do nothing.
*
* Purpose: To handle removing a char from a string as well as manipulating it
*          on the console display.
*/
void IOComm::attemptBackspace(std::string &responseToReduce)
{
   // see if we can even reduce our current string at all.
   if (responseToReduce.length() > 0)
   {
      responseToReduce.pop_back();
      consoleBackspace();
   }
}


/*
* Pre: None
*
* Post: appropriatly move the cursos back one space on the console.
*
* Purpose: moves the console back one space and clears it at the same time,
*          so you're not seeing the char you just deleted.
*/
void IOComm::consoleBackspace()
{
   // move cursor back one space
	std::cout << '\b';
   // replace the character at the space with a blank.
	std::cout << ' ';
   // move the cursor back to its original place.
	std::cout << '\b';
}


/*
* Pre: The character entered.
*
* Post: True if backspace or delete are entered, otherwise false
*
* Purpose: To inform you if the letter the user entered is indicating a desire
*          to move backwards one char in their input.
*/
bool IOComm::isBackspaceEntered(char input)
{
	if (input == DELETE_KEY_VALUE || input == BACKSPACE_KEY_VALUE)
		return true;
	else
		return false;
}


/*
* Pre: input is a valid string, (not null)
*
* Post: int value of the length() instead of size_t
*
* Purpose: To give a size of a string back to the caller instead of
*          an annoying size_t format.
*/
int IOComm::sizeToInt(const std::string input)
{
	return static_cast<int>(input.length());
}


/*
* Pre: None
*
* Post: A string containing only integers / letters is returned.
*
* Purpose: To only accept integers / letters as a response, then to make
*          those into a string and return the value.
*/
char IOComm::getMaskedChar()
{
	char input = ' ';

	input = _getch();
	if (input != ENTER_KEY_VALUE && !isBackspaceEntered(input))
		std::cout << '*';

	return input;
}


/*
* Pre: None
*
* Post: A string containing only integers / letters is returned.
*
* Purpose: To only accept integers / letters as a response, then to make
*          those into a string and return the value.
*/
std::string IOComm::getAlphaNumericResponse()
{
	std::string response = "";
   char entered = ' ';

   entered = _getch();
   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      if (isalnum(entered))
      {
         response.push_back(entered);
		 std::cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: otherKeys is populated with values, size = the length of otherKeys[]
*
* Post: A string containing only integers / letters / any of the
*       specific other keys is returned.
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
std::string IOComm::getAlphaNumericResponseOr(const char otherKeys[], int size)
{
   std::string response = "";
   char entered = ' ';

   // get an initial value.
   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }
      // check to see if a valid number, if so add it to the string
      if (isalnum(entered))
      {
         response.push_back(entered);
		 std::cout << entered;
      }
      else
      {
         for (int i = 0; i < size; i++)
         {
            if (otherKeys[i] == entered)
            {
               response.push_back(entered);
			   std::cout << entered;
            }
         }
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: None
*
* Post: A string containing only letters is returned.
*
* Purpose: To only accept letters as a response, then to make those into a
*          string and return the value.
*/
std::string IOComm::getAlphaResponse()
{
	std::string response = "";
   char entered = ' ';

   entered = _getch();
   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      if (isalpha(entered))
      {
         response.push_back(entered);
		 std::cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: bool on whether you want spaces or not
*
* Post: A string containing only letters is returned. and spaces if space = true
*
* Purpose: To only accept letters as a response, then to make those into a
*          string and return the value. Includes spaces if bool is true.
*/
std::string IOComm::getAlphaResponse(bool spaces)
{
   std::string response = " ";

   if (spaces)
   {
      char space[] = {' '};
      response = getAlphaResponseOr(space, 1);
   }
   else
   {
      response = getAlphaResponse();
   }

   return response;
}


/*
* Pre: otherKeys is populated with values, size = the length of otherKeys[]
*
* Post: A string containing only letters / any of the
*       specific other keys is returned.
*
* Purpose: To only accept alpha chars and the specific other keys as a response,
*          then to make those into a string and return the value.
*/
std::string IOComm::getAlphaResponseOr(const char otherKeys[], int size)
{
   std::string response = "";
   char entered = ' ';

   // get an initial value.
   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }
      // check to see if a valid number, if so add it to the string
      if (isalpha(entered))
      {
         response.push_back(entered);
		 std::cout << entered;
      }
      else
      {
         for (int i = 0; i < size; i++)
         {
            if (otherKeys[i] == entered)
            {
               response.push_back(entered);
			   std::cout << entered;
            }
         }
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: options is populated, optionsize = options length
*      all values in options MUST be capitalized.
*
* Post: A char the user selected that is equivilent to one of the options
*
* Purpose: To only accept specific letters as a response, then to return that
*          value to the user as an upper case letter.
*/
char IOComm::getCharResponse(const char options[], int optionSize)
{
	std::string letter = ""; // string to make it easier to check values.
   char input = ' ';
   input = _getch();

   while (input != ENTER_KEY_VALUE || letter.length() == 0)
   {
      // Check for and handle if backspace was input.
      if (isBackspaceEntered(input))
         attemptBackspace(letter);
      else
      {
         // check to see if a letter. And that we don't already have an option
         if (isalpha(input) && letter.length() == 0)
         {
            // normalize data.
            input = static_cast<char>(toupper(input));

            // loop through options.
            for (int i = 0; i < optionSize; i++)
            {
               // if one of the letters looking for.
               if (input == options[i])
               {
                  letter.push_back(input);
				  std::cout << input;
                  break;
               }
            }
         }
      }

      // check for another input
      input = _getch();
   }

   return letter.at(0);
}


/*
* Pre: None
*
* Post: A string is returned.
*
* Purpose: To accept an input and to mask the input with * as they are entered.
*/
std::string IOComm::getMaskedResponse()
{
	std::string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      response.push_back(entered);
	  std::cout << "*";

      entered = _getch();
   }

   return response;
}


/*
* Pre: None
*
* Post: The last name of the user is returned to the caller.
*
* Purpose: To request and return in the form of a string, the first
*          name of the user.
*/
std::string IOComm::getFirstName()
{	
	std::string name;

	//prompt the name.
	std::cout << "Enter your first name: ";

	//obtain input.
	name = getAlphaResponse(true);

	return name;
}


/*
* Pre: None
*
* Post: The last name of the user is returned to the caller.
*
* Purpose: To request and return in the form of a string, the last
*          name of the user.
*/
std::string IOComm::getLastName()
{
	std::string name;

	//prompt the name.
	std::cout << "Enter your last name: ";

	//obtain input.
	name = getAlphaResponse(true);

	return name;
}


/*
* Pre: None
*
* Post: The full name of the user is returned to the caller.
*
* Purpose: To get the first and last name of the user, and return the
*          string containing the full name.
*/
std::string IOComm::getName()
{
	std::string fName, lName;

	// obtain the names.
	fName = getFirstName();
	std::cout << std::endl; // new line for neatness.
	lName = getLastName();

	return (fName + " " + lName);
}


/*
* Pre: first name and last name references are where you want to
*      STORE the first and last names.
*
* Post: The full name of the user is returned to the caller. And the
*       first and last names are stored into the variables passed.
*
* Purpose: To get the first and last name of the user, and return the
*          string containing the full name, as well as store the first
*          and last name's into params. 
*/
std::string IOComm::getName(std::string &firstName, std::string &lastName)
{
	// obtain the first and second part of the name.
	firstName = getFirstName();
	lastName = getLastName();

	// return the full name.
	return (firstName + " " + lastName);
}


/*
* Pre: None
*
* Post: A string containing only integers is returned.
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
std::string IOComm::getNumericResponse()
{
	std::string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      // only accept digits and only if the length is low enough to accept more.
      if (isdigit(entered))
      {
         response.push_back(entered);
         std::cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: size of the numeric response you want back.
*
* Post: A string containing only integers is returned. and is = size
*
* Purpose: To only accept integers as a response, then to make those into a
*          string and return the value.
*/
std::string IOComm::getNumericResponse(int size)
{
	std::string response = "";
   char entered = ' ';

   entered = _getch();

   while (entered != ENTER_KEY_VALUE || response.length() != size)
   {
      if (isBackspaceEntered(entered))
      {
         attemptBackspace(response);
         entered = _getch();
         continue; // continue the loop, no need to execute rest.
      }

      // only accept digits and only if the length is low enough to accept more.
	  if (isdigit(entered) && sizeToInt(response) < size)
      {
         response.push_back(entered);
		 std::cout << entered;
      }

      entered = _getch();
   }

   return response;
}


/*
* Pre: None
*
* Post: A 10 digit string is returned. Assumably a valid SSN
*
* Purpose: To obtain a SSN number with a proper format for doing such. 
*          First 6 chars are masked while the remaining 4 are displayed.
*/
std::string IOComm::getSSN()
{
	std::string response;
	char input;

	// first char is garenteed to need to be masked.
	input = getMaskedChar();
	// continously obtain info until we obtain a SSN
	while (input != ENTER_KEY_VALUE || response.length() != SSN_LENGTH)
	{
		// check if input is a digit (neccisary for SSN)
		if (isdigit(input)){
			// If we have space to add the input, do so.
			if (response.length() < SSN_LENGTH)
			{
				// display unmasked char is they are the last 4
				if (response.length() >= SSN_LENGTH - 4)
					std::cout << input;

				// add the input to the response.
				response.push_back(input);
			}
		}
		else
		{
			// make a backspace if necissary.
			if (isBackspaceEntered(input))
				attemptBackspace(response);
		}

		// determine which kind of input we want to obtain next.
		if (response.length() < SSN_LENGTH - 4)
			input = getMaskedChar();
		else 
			input = _getch();
	}

	return response;
}

/*
* Pre: none
*
* Post: a string containing only int value's is returned, size = 10. 
*
* Purpose: To get a phone number value. Essentailly just obtaining 10 ints
*          from the user but it formats it nicely in the console.
*/
std::string IOComm::getTelephoneNumber()
{
	const char leftBrace = '(',
		       rightBrace = ')';
	std::string response = "";

	std::cout << leftBrace;

	char input = _getch();
	while (input != ENTER_KEY_VALUE || response.length() < TELEPHONE_LENGTH)
	{

		// obtain input
		while (!isdigit(input))
		{
			if (isBackspaceEntered(input))
			{
				// see if we need to clean any special chars
				int size = sizeToInt(response);
				if (size == 3)
				{
					for (int i = 0; i < 2; i++)
						consoleBackspace();
				}
				else if (size == 6)
					consoleBackspace();
					
				
				// attempt to commit a backspace to the string.
				attemptBackspace(response);
			}

			input = _getch();
		}

		// add the char input to the string.
		if (sizeToInt(response) < TELEPHONE_LENGTH)
		{
			response.push_back(input);
			// display the input
			std::cout << input;

			// see if any special chars need to be used.
			int responseC = sizeToInt(response);
			if (responseC == 3) std::cout << rightBrace << " ";
			if (responseC == 6) std::cout << '-';
		}
			
		input = _getch();
	}
	return response;
}

