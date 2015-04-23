#include "restaurant.h"

// Constructor
// author: Johnna
Restaurant::Restaurant()
{
	mNumOfOrders = 0;
	mGrandTotal = 0;
	//Table mTables[MAX_TABLES];

	for (int i = 0; i < MAX_TABLES; i++)
	{
		mTables[i].setNumberOfSeats(tableSizes[i]);
		//mTables[i].setSeatsOccupied(0);
	}
}


Restaurant::~Restaurant()
{
}


//Pre: mMenuItems exists
//Post: Appends a new menu item
//Purpose: To allow the cook to add items to the list to the
//Author: Nick Foster
bool Restaurant::addMenuItem()
{
	//LinkedList mMenuItems;
	std::string newString;
	int newInt;
	double newDouble;
	MenuItem newItem;

	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cout << "Please enter the new item name: ";
	getline(cin, newString);
	newItem.setName(newString);

	cout << "Please enter the item description: ";
	getline(cin, newString);
	newItem.setDescription(newString);

	cout << "Please enter the item price: ";
	cin >> newDouble;
	newItem.setPrice(newDouble);

	cout << "ask for category ";
	cin >> newInt;
	newItem.setCategory(newInt);

	return mDiningMenu.push(newItem);
}

/*
* Pre: None
*
* Post: 
	gets which table bill is for from console.
	The bill amount is added to daily Grand Total,
	the daily number of orders increases by one
	the table seats are cleared for new diners (or is that separate?)
	if there is a bill object, that is handled.
	if tips are being kept track of, they are added to waiters' tally
	the table order reset to zero to make way for next table order.
*
* Purpose: To mark bill paid and close dining transaction
*
* Author: Ethan Konczal
*/
void Restaurant::billPaid()
{

}


/*
//Changes pay, phone, address prompts what to change when called
// get which employee from console, display current info, prompt and make changes
* Pre: None
*
* Post:
* 
* Purpose:  prompt what to change, call function to change that value
*
* Author: Alex Rulev
*/
void Restaurant::changeEmployee()
{
   string search;
	int line = 0;
	string temp;
	bool found = false;
	cout << "Which employee do you want to change?(ENTER NAME)\n";
   getline(cin, search);
   ifstream fin;
   fin.open(EMPLOYEE_FILE);
   if (!fin.good())
   {
      cout << "***EMPLOYEE FILE MISSING***\n";
      system("pause");
      return;
   }
   else
   {
      while (!fin.eof())
      {
         line++;
         for (int i = 0; i < 6; i++)
         {
            getline(fin, temp);
            if (i == 0)
               if (temp == search)
               {
                  found = true;
                  fin.close();
               }
         }
      }
   }
   if (!found)
   {
      cout << "***Employee Not Found***\n";
      system("pause");
      return;
   }
   else
   {
      int j = 0;
      fin.open(EMPLOYEE_FILE);
      ofstream fout;
      fout.open(CHANGE_BUFFER);
      while (j < line)
      {
         for (int i = 0; i < 6; i++)
         {
            getline(fin, temp);
            fout << temp;
         }
      }
      for (int i = 0; i < 3; i++)
      {
         getline(fin, temp);
         fout << temp;
      }
      getline(fin, temp);
      cout << "The current phone number is: " << temp << "\n Would you like to change it? (1 for yes, 0 for no)\n";
      int select;
      cin >> select;
      if (select)
      {
         cout << "What new phone number would you like?\n";
         getline(cin, temp);
         fout << temp;
      }
      else
         fout << temp;
      getline(fin, temp);
      cout << "The current address is: " << temp << "\n Would you like to change it? (1 for yes, 0 for no)\n";
      //			int select;
      cin >> select;
      if (select)
      {
         cout << "What new address would you like?\n";
         getline(cin, temp);
         fout << temp;
      }
      else
         fout << temp;
      getline(fin, temp);
      cout << "The current salary is: " << temp << "\n Would you like to change it? (1 for yes, 0 for no)\n";
      //			int select;
      cin >> select;
      if (select)
      {
         cout << "What new salary would you like?\n";
         getline(cin, temp);
         fout << temp;
      }
      else
         fout << temp;
      while (!fin.eof())
      {
         getline(fin, temp);
         fout << temp;
      }
      fin.close();
      fout.close();
      fin.open(CHANGE_BUFFER);
      fout.open(EMPLOYEE_FILE);
      while (!fin.eof())
      {
         getline(fin, temp);
         fout << temp;
      }
      fin.close();
      fout.close();

   }
}

/*
* Pre: None
*
* Post: table order is updated
*
* Purpose:  prompt what to change, call function to change that value
*
* Author: JT Woodside
*/
bool Restaurant::changeItemOrder()
{
	return false;
}


//Pre: mMenuItems exists
//Post: The oroginal item is removed and replacesd with another item
//Purpose: To allow the cook to change itmes on the menu.
//Author: Nick Foster
bool Restaurant::changeMenuItem()
{
	bool changed = false;
	LinkedList mMenuItems;
	MenuItem tempItem;
	std::string searchKey, newString;
	enum Category{ appetiser, entree, dessert, beverage };
	double newDouble;
	int newInt;


	std::cout << "Please enter the name of the item you wish to change: ";
	std::cin >> searchKey;
	if (!mDiningMenu.isExist(searchKey))
	{
		return false;
	}

	tempItem = mDiningMenu.getItem(searchKey);
	std::cout << "Please enter the new item name: ";
	std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, newString);
	tempItem.setName(newString);
	std::cout << "Please enter the item description: ";
	getline(cin, newString);
	tempItem.setDescription(newString);
	std::cout << "Please enter the item price: ";
	std::cin >> newDouble;
	tempItem.setPrice(newDouble);
	std::cout << "Please enter the item category (1-4): ";
	std::cin >> newInt;
	//tempItem.setCategory(newInt);

	mDiningMenu.remove(searchKey);
	mDiningMenu.push(tempItem);


	return changed;
}


//+ changeMenuPrice() //Warren
//pre:none
//post : none
//   purpose : prompt for menu item, change the price of that item in the menu data file
void Restaurant::changeMenuPrice()
{

}


/*
Check Order Status
-Author: Toby Ingmire
-Prototype: bool Restaurant::checkOrderStatus(int tableNumber)
-Pre: tableNUmber is declared in caller
-Post: Tell if the tables order is ready or not
-Purpose: To return true or false based on whether the
order for the specified table number is ready.
*/
bool Restaurant::checkOrderStatus(int tableNumber)
{
	if (mTables[tableNumber].orderExists())
      return true;
   else
      return false;
}



/*
* Pre: None
*
* Post: 
*
* Purpose: To clear current seating number so table shows as available
*
* Author: Dan Konopka
*/
bool Restaurant::clearTable()
{
	return false;
}


/*
* Pre: None
*
* Post: Displays the cook menu
*
* Purpose: To display the cooks menu.
*
* Author: Evan Nudd
*/
void Restaurant::cookMenu()
{
	//system("cls");
	std::cout << RESTAURANT_TITLE << std::endl;
	for (int i = 0; i < COOK_NUM_OPTIONS; i++)
	{
		std::cout << i << ") " << COOK_OPTIONS[i] << std::endl;
	}
}



/*
* Pre: None
*
* Post: Acts upon the users choice of input for selected menu
*
* Purpose: to handle the user input for a particular employee.
*
* Author: Evan Nudd
*/


void Restaurant::cookOperations()
{
	int choice = -1;
	do
	{
		cookMenu();
		choice = getInputBetween(0, COOK_NUM_OPTIONS);

		// act on the choice
		switch (choice)
		{
		case 0:
			displayDinerMenu();
			break;
		case 1:
			changeMenuItem();
			break;
		case 2:
			deleteMenuItem();
			break;
		case 3:
			addMenuItem();
			break;
		case 4:
			viewOrderInProgress(mKitchenList);
			break;
		case 5:
			orderReady();
			break;
		case 6:
			// nothing needs to be done for logout.
			system("cls");
			break;
		}
	} while (choice != 6);
}


//+dailyReport() // ALEC RULEV
//pre:none
//post : display
//   purpose : take values from the day and generate the daily report
void Restaurant::dailyReport()
{
	cout << "The total amount made today is : $" << mGrandTotal << "\n";
	cout << "The total amount of orders is :" << mNumOfOrders << "\n";
	cout << "The average price per order is : $" << (mGrandTotal / mNumOfOrders) << "\n";
}



/*
* Pre: None
*
* Post: 
*
* Purpose: to delete an item from a table order
*
* Author: JT Woodside
*/
void Restaurant::deleteItemOrder()
{
	
}

//Pre: mMenuItems exists
//Post: The item is removed from the linked list
//Purpose: TO allow the cooks to remove items from the menu
//Author: Nick Foster
bool Restaurant::deleteMenuItem()
{
	bool removed = false;
	LinkedList mMenuItems;

	std::string searchKey;
	std::cout << "Please enter the name of the item you wish to change: ";
	std::cin >> searchKey;

	if (mDiningMenu.isExist(searchKey))
	{
		mDiningMenu.remove(searchKey);
		removed = true;
	}

	return removed;
}

/*
* Pre: None
*
* Post: Displays restaurant menu of food for sale
*
* Purpose: so manager and kitchen staff can review current menu
*
* Author: unassigned
*/
void Restaurant::displayDinerMenu()
{
	LinkedList listRebuild;
	MenuItem nextItem;
	int titlewidth = 22;

	cout << endl << endl << "APPETIZERS" << endl;
	//iterate through list by category
	nextItem = mDiningMenu.pop();
	do {
		if (nextItem.getCategory() == Category::appetizer)
		{
			nextItem.displayFull();
		}
		listRebuild.insertInOrder(nextItem);
		nextItem = mDiningMenu.pop();
	} while (!(nextItem == ""));

	//iterate through rebuilding list
	nextItem = listRebuild.pop();
	do {
		mDiningMenu.push(nextItem);
		nextItem = listRebuild.pop();
	} while (!(nextItem == ""));

	cout << endl << endl <<  "ENTREES" << endl;
	//iterate through list by category
	nextItem = mDiningMenu.pop();
	do {
		if (nextItem.getCategory() == Category::entree)
		{
			nextItem.displayFull();
		}
		listRebuild.insertInOrder(nextItem);
		nextItem = mDiningMenu.pop();
	} while (!(nextItem == ""));

	//iterate through rebuilding list
	nextItem = listRebuild.pop();
	do {
		mDiningMenu.push(nextItem);
		nextItem = listRebuild.pop();
	} while (!(nextItem == ""));

	cout << endl << endl << "DESSERTS" << endl;
	//iterate through list by category
	nextItem = mDiningMenu.pop();
	do {
		if (nextItem.getCategory() == Category::dessert)
		{
			nextItem.displayFull();
		}
		listRebuild.insertInOrder(nextItem);
		nextItem = mDiningMenu.pop();
	} while (!(nextItem == ""));

	//iterate through rebuilding list
	nextItem = listRebuild.pop();
	do {
		mDiningMenu.push(nextItem);
		nextItem = listRebuild.pop();
	} while (!(nextItem == ""));
	
	cout << endl << endl 
		<< "BEVERAGES" << endl;
	//iterate through list by category
	nextItem = mDiningMenu.pop();
	do {
		if (nextItem.getCategory() == Category::beverage)
		{
			nextItem.displayFull();
		}
		listRebuild.insertInOrder(nextItem);
		nextItem = mDiningMenu.pop();
	} while (!(nextItem == ""));

	//iterate through rebuilding list
	nextItem = listRebuild.pop();
	do {
		mDiningMenu.push(nextItem);
		nextItem = listRebuild.pop();
	} while (!(nextItem == ""));

}

/*
* Pre: None
*
* Post: Displays tables where no one is seated
*
* Purpose: so host can review available tables
*
* Author: Dan Konopka
*/
void Restaurant::displayOpenTables()
{

}

/*
* Pre: None
*
* Post: Displays tables where someone is seated
	and any associated order
*
* Purpose: so waiter can review work flow
*
* Author: Ethan Konczal
*/
void Restaurant::displayTables()
{
	//testing version, not Ethan's fault.
	for (int i = 0; i < MAX_TABLES; i++)
	{
		if (mTables[i].isOccupied())
		{
			cout << "\n\nTable " << i+1 << endl;
			mTables[i].displayOrder();
		}
	}
}

/*
* Pre: None
*
* Post: deletes employee from data file.  Input by console

* Purpose: so manager can remove an employee from the system
*
* Author: Warrem
*/
void Restaurant::fireEmployee()
{
	cout << "fire employee in progress";
}

/*
* Pre: None
*
* Post: Bill displays to console (or bill object is created?)

* Purpose: to generate bill for customers
*
* Author: Ethan Konczal
*/
void Restaurant::generateBill()
{

}



/*
* Pre: None
*
* Post: new employee is added to datafile.
	all input by console prompt
*
* Purpose: To hire employee
*
* Author: Ethan Konczal
*/
void Restaurant::hireEmployee()
{
	cout << "hire employee in progress";
}

/*
* Pre: min value in inclusive, max value is exclusive
*
* Post: returns an int between the two value's entered (one digit)
*
* Purpose: To get a valid input.
*
* Author: Evan Nudd
*/
int Restaurant::getInputBetween(int min, int max)
{
	int selection = -1;
	std::string input;
	bool valid = false;

	do
	{
		std::getline(std::cin, input);
		selection = static_cast<int>(input[0]); // No menu go's to double digit so this ok.
		selection = selection - 48; // temp correction by Johnna until Evan decides
		if (selection >= min && selection < max)
			valid = true;
	} while (!valid);

	return selection;
}


/*
* Pre: None
*
* Post: Displays the host menu
*
* Purpose: To display the hosts menu.
*
* Author: Evan Nudd
*/
void Restaurant::hostMenu()
{
	system("cls");
	std::cout << RESTAURANT_TITLE << std::endl;
	for (int i = 0; i < HOST_NUM_OPTIONS; i++)
	{
		std::cout << i << ") " << HOST_OPTIONS[i] << std::endl;
	}
}


/*
* Pre: None
*
* Post: Acts upon the users choice of input for selected menu
*
* Purpose: to handle the user input for a particular employee.
*
* Author: Evan Nudd
*/
void Restaurant::hostOperations()
{
	int choice = -1;

	do
	{
		hostMenu();
		choice = getInputBetween(0, HOST_NUM_OPTIONS);

		// act on the choice
		switch (choice)
		{
		case 0:
			displayOpenTables();
			break;
		case 1:
			seatTable();
			break;
		case 2:
			clearTable();
			break;
		case 3:
			// nothing needs to be done for logout
			system("cls");
			break;
		}
	} while (choice != 3);

}



/*
* Pre: normal day-startup is rerun.
*
* Post: load menu from datafile
*
* Purpose: to not have to start menu from scratch
*
* Author: Johnna
*/
void Restaurant::loadDinerMenu()
{
	ifstream fin(DINER_MENU);
	MenuItem item;

	if (!fin.fail())
	{
		fin >> item;
		while (!fin.eof())
		{
			mDiningMenu.insertInOrderNoRepeat(item);
			fin >> item;
      }
   }
   else
   {
      cout << "Saved Menu Not Found\n";
   }
   fin.close();
}


void Restaurant::login()
{
   ifstream loginFile;
   string username, password, temp;
   char c;
   bool done = false;

   cout << "Enter Username: ";
   getline(cin, username);

   system("cls");
   cout << "Enter password: ";

   while (!done)
   {
      c = _getch();

      if (c == '\r')
      {
         done = true;
      }
      else if (c == '\b')
      {
         if (password.length() > 0)
         {
            password.erase(password.length() - 1, 1);

            system("cls");
            cout << "Enter password: ";
            for (unsigned int i = 1; i < password.length(); i++)
            {
               cout << '*';
            }
         }
      }
      else
      {
         password.append(1, c);
         cout << "*";
      }
   }

   loginFile.open(LOGIN_FILE_NAME);

   while (loginFile)
   {
      getline(loginFile, temp);

      if (temp == username)
      {
         getline(loginFile, temp);

         if (temp == password)
         {
            // handle setting current user
			 login(username);

            cout << "Login successful\n";
            return;
         }
         else
         {
            cout << "Invalid password\n";
            return;
         }
      }
      else
      {
         getline(loginFile, temp);
      }
   }

   cout << "User does not exist\n";
}

/*
Pre: a name from the login file
Post: The mEmployeeType is set
Purpose: to set the mCurrentUser type to trigger the menus
Author: Johnna
Credit: Alex Rulev code from searchEmployee
NOTE: Does not follow the Design Document
*/
void Restaurant::login(string user)
{
	bool found = false;
	int empCat = -1;
	string temp;
	string empType;
	ifstream fin;
	fin.open(EMPLOYEE_FILE);
	if (!fin.good())
	{
		cout << "***EMPLOYEE FILE MISSING***\n";
		system("pause");
		return;
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, temp);
			if (temp == user)
			{
				getline(fin, empType);
				if (empType == "Manager")
				{
					empCat = 0;
				}
				if (empType == "Host")
				{
					empCat = 1;
				}
				if (empType == "Waiter")
				{
					empCat = 2;
				}
				if (empType == "Cook")
				{
					empCat = 3;
				}
			}
		}
	}
	fin.close();
	mCurrentUser = Employee(user, "", "", "", empCat, 0.0);
}

/*
* Pre: None
*
* Post: Displays the manager menu
*
* Purpose: To display the managers menu.
*
* Author: Evan Nudd
*/
void Restaurant::managerMenu()
{
	system("cls");
	std::cout << RESTAURANT_TITLE << std::endl;
	for (int i = 0; i < MANAGER_NUM_OPTIONS; i++)
	{
		std::cout << i << ") " << MANAGER_OPTIONS[i] << std::endl;
	}
}



/*
* Pre: None
*
* Post: Acts upon the users choice of input for selected menu
*
* Purpose: to handle the user input for a particular employee.
*
* Author: Evan Nudd
*/
void Restaurant::managerOperations()
{
	int choice = -1;

	do
	{
		managerMenu();

		choice = getInputBetween(0, MANAGER_NUM_OPTIONS);

		// act on the choice
		switch (choice)
		{
		case 0:
			hireEmployee();
			break;
		case 1:
			fireEmployee();
			break;
		case 2:
			changeEmployee();
			break;
		case 3:
			searchEmployee();
			break;
		case 4:
			dailyReport();
			break;
		case 5:
			// nothing needs to be done for logout
			system("cls");
			break;
		case 6:
			// add what ev else you want this to do here. like write files.
			saveDinerMenu();
			dailyReport();
			exit(0);
			break;
		}
	} while ((choice !=6) && (choice !=5)) ;
}



/*
* Pre: Nothing
*
* Post: Using input from console, delete a number from the kitchenlist
which corresponds to a table order that is ready to serve
*
* Purpose: for kitchen staff to mark orders done cooking
*
* Author: unassigned
*/
void Restaurant::orderReady()
{

}



/*
* Pre: normal day-startup is rerun.
*
* Post: table states are restored from file
*
* Purpose: to recover data after power outage
*
* Author: Johnna
*/
void Restaurant::restoreTableStates()
{
   ifstream fin(TABLE_STATES);
   MenuItem item;
   string junk;
   char ch;
   int numSeats, numDiners;
   int index = 0;

   if (!fin.fail())
   {
      while ((!fin.eof()) && (index < MAX_TABLES))
      {
         ch = fin.peek();
         while (!fin.eof() && (ch != '#'))
         {
            fin >> item;
            mTables[index].addToOrder(item);
            ch = fin.peek();
         }

         fin >> junk
            >> numSeats
            >> numDiners;
         getline(fin, junk);
         mTables[index].setNumberOfSeats(numSeats);
         mTables[index].setSeatsOccupied(numDiners);
         index++;
      }
   }
   else
   {
      cout << "Saved Menu Not Found\n";
   }

   fin.close();
}


void Restaurant::runRestaurant()
{
	// load data here
	loadDinerMenu();


	while (true) // infinite loop until manager shuts systems down.
	{
		login(); // login

		// operations will loop themselves until loged out.
		switch (mCurrentUser.getEmployeeType())
		{
		case EMPLOYEE_TYPE::COOK:
			cookOperations();
			break;
		case EMPLOYEE_TYPE::HOST:
			hostOperations();
			break;
		case EMPLOYEE_TYPE::MANAGER:
			managerOperations();
			break;
		case EMPLOYEE_TYPE::WAITER:
			waitOperations();
			break;
		}
	}

}

/*
* Pre: restaurant is running
*
* Post: saves current menu to datafile
*
* Purpose: to not start menu from scratch next time
*
* Author: Johnna
*/
void Restaurant::saveDinerMenu()
{
   ofstream fout(DINER_MENU);
   MenuItem nextItem;
   LinkedList listRebuild;

   if (!mDiningMenu.empty())
   {
      //iterate through list to ofstream
      nextItem = mDiningMenu.pop();
      do {
         fout << nextItem;
         listRebuild.insertInOrder(nextItem);
         nextItem = mDiningMenu.pop();
      } while (!(nextItem == ""));

      //iterate through rebuilding list
      nextItem = listRebuild.pop();
      do {
         mDiningMenu.insertInOrder(nextItem);
         nextItem = listRebuild.pop();
      } while (!(nextItem == ""));
   }

   fout.close();
}


/*
* Pre: restaurant is running
*
* Post: table states are saved to file
*
* Purpose: to save data in case of power outage
*
* Author: Johnna
*/
void Restaurant::saveTableStates()
{
   ofstream fout(TABLE_STATES);
   MenuItem nextItem;
   LinkedList listRebuild;

   for (int i = 0; i < MAX_TABLES; i++)
   {
      if (mTables[i].orderExists())
      {
         //iterate through list to ofstream
         nextItem = mTables[i].popItem();
         do {
            fout << nextItem;
            listRebuild.insertInOrder(nextItem);
            nextItem = mTables[i].popItem();
         } while (!(nextItem == ""));

         //iterate through rebuilding list
         nextItem = listRebuild.pop();
         do {
            mTables[i].addToOrder(nextItem);
            nextItem = listRebuild.pop();
         } while (!(nextItem == ""));
      }

      fout << "#Table" << i + 1 << " ";
      fout << mTables[i].getNumberOfSeats() << " ";
      fout << mTables[i].getSeatsOccupied() << " " << endl;
   }
   fout.close();
}


//+searchEmployee() // ALEC RULEV
//pre:none
//post : display
//   purpose : prompt for name, search data files for name and display info on that employee
void Restaurant::searchEmployee()
{
string employeeSearch;
	cout << "What employee are you searching for?\n";
	getline(cin, employeeSearch);
	ifstream fin;
	fin.open(EMPLOYEE_FILE);
	bool found = false;
	while (!fin.eof())
	{
		string temp;
		getline(fin, temp);
		if (temp == employeeSearch)
		{
			cout << temp;
			for (int i = 0; i < 5; i++)
			{
				getline(fin, temp);
				cout << temp;
			}
			system("pause");
			found = true;
			fin.close();
			return;
		}
	}
	if (!found)
		cout << "No such employee found!\n";
	system("pause");
	fin.close();
}

/*
* Pre: Nothing
*
* Post: Using input from console, assign a part of seats occupied
at a table.  Validates that seats occupied does not exceed 
the maximum seating for that table
returns true if successful.
*
* Purpose: for host to seat guests
*
* Author: Dan Konopka
*/
bool Restaurant::seatTable()
{
	return false;
}

/*
* Pre: 
*
* Post: 
*
* Purpose: 
*
* Author: Dan Konopka
NOTE: HELPER FUNCTION TO seatTable()?  up to Dan to include or cut.
*/
bool Restaurant::seatTable(int& tableId, string& waiter) // no waiter; 
{
	return false;
}


//+ shutDown()
//pre: none
// post : none
//		shut down program
// Author: unassigned
void Restaurant::shutDown()
{

}

/*
* Pre: seated Table
*
* Post: order is created and sent to kitchen
* get table number from console.
*
* Purpose: to take a table order
*
* Author: JT Woodside
*/
void Restaurant::takeOrder()
{
	cout << "take order"; 
	
}

void Restaurant::testRun()
{
	loadDinerMenu();
	restoreTableStates();
	mKitchenList.insert(0);
	mKitchenList.insert(5);
	mKitchenList.insert(10);




	cout << "\n\nif dininMenu.txt,  employeeInfo.txt, and tableState.txt were available to load " << endl;
	cout << "then this test run has a working menu; Tables 1, 6, and 11 have orders, " << endl;
	cout << "and the employee file contains Elena Kagan, Sonia Sotomayor, John Roberts, Samuel Alito, and John Breyer " << endl;
	cout << "\nhave fun testing functions.";


	cout << "\nManager" << endl;
	cout << "A. Hire Employee" << endl;
	cout << "B. Fire Employee" << endl;
	cout << "C. Update Employee Info" << endl;
	cout << "D. Search for Employee" << endl;
	cout << "E. Generate Daily Report" << endl;
	cout << "\nHost" << endl;
	cout << "H. Show Empty Tables" << endl;
	cout << "I. Assign Party Size to Table" << endl;
	cout << "J. Make Table Available" << endl;
	cout << "\n Kitchen" << endl;
	cout << "L. Display Menu" << endl;
	cout << "M. Change Item on Menu" << endl;
	cout << "N. Delete Item from Menu" << endl;
	cout << "O. Add item to menu" << endl;
	cout << "P. View orders to be completed" << endl;
	cout << "Q. Change status of order to complete" << endl;
	cout << "\nWaiter" << endl;
	cout << "R. Take order from Customer" << endl;
	cout << "S. Change items within an order" << endl;
	cout << "T. Delete items in orders" << endl;
	cout << "U. Show tables with guests and any orders" << endl;
	cout << "V. Generate Bill based on order" << endl;
	cout << "Z. Exit Test" << endl;



	string input;
	bool continueTest = true;


	do {

		cout << "\nenter choice A-Z\n\n";

		getline(cin, input);
		char choice = input[0];

		switch (choice)
		{
		case 'a':
		case 'A':
			hireEmployee();
			break;
		case 'b':
		case 'B':
			fireEmployee();
			break;
		case 'c':
		case 'C':
			changeEmployee();
			break;
		case 'd':
		case 'D':
			searchEmployee();
				break;
		case 'e':
		case 'E':
			dailyReport();
			break;
			break;
		case 'f':
		case 'F':
			break;
		case 'g':
		case 'G':
			break;
		case 'h':
		case 'H':
			displayOpenTables();
			break;
		case 'i':
		case 'I':
			seatTable();
			break;
		case 'j':
		case 'J':
			clearTable();
			break;
		case 'k':
		case 'K':
			break;
		case 'l':
		case 'L':
			displayDinerMenu();
			break;
		case 'm':
		case 'M':
			changeMenuItem();
			break;
		case 'n':
		case 'N':
			deleteMenuItem();
			break;
		case 'o':
		case 'O':
			addMenuItem();
			break;
		case 'p':
		case 'P':
			viewOrderInProgress(mKitchenList);
			break;
		case 'Q':
		case 'q':
			orderReady();
			break;
		case 'R':
		case 'r':
			takeOrder();
			break;
		case 's':
		case 'S':
			changeItemOrder();
			break;
		case 't':
		case 'T':
			deleteItemOrder();
			break;
		case 'u':
		case 'U':
			displayTables();
			break;
		case 'v':
		case 'V':
			generateBill();
			break;
		case 'z':
		case 'Z': continueTest = false;

		default:
			break;
		}
	} while (continueTest);

}

/*
View Order In Progress
-Author: Toby Ingmire
-Prototype: void Restaurant::viewOrderInProgress(NumberList mList)
-Pre: mList is declared in caller
-Post: View the order that is in progress
-Purpose: To display the current order that is in progress.
*/
void Restaurant::viewOrderInProgress(NumberList &mList)
{
	NumberList rebuild;

	int tableNumber = mList.remove();
	while (tableNumber > 0)
	{
		mTables[tableNumber].displayOrder();
		rebuild.insert(tableNumber);
		tableNumber = mList.remove();
	}

	tableNumber = rebuild.remove();
	while (tableNumber > 0)
	{
		mList.insert(tableNumber);
	}
}


/*
* Pre: None
*
* Post: Displays the waiters menu
*
* Purpose: To display the waiters menu.
*
* Author: Evan Nudd
*/
void Restaurant::waitMenu()
{
	system("cls");
	std::cout << RESTAURANT_TITLE << std::endl;
	for (int i = 0; i < WAIT_NUM_OPTIONS; i++)
	{
		std::cout << i << ") " << WAIT_OPTIONS[i] << std::endl;
	}
}



/*
* Pre: None
*
* Post: Acts upon the users choice of input for selected menu
*
* Purpose: to handle the user input for a particular employee.
*
* Author: Evan Nudd
*/
void Restaurant::waitOperations()
{
	int choice = -1;
	do
	{
		waitMenu();
		choice = getInputBetween(0, WAIT_NUM_OPTIONS);

		// act on the choice
		switch (choice)
		{
		case 0:
			takeOrder();
			break;
		case 1:
			changeItemOrder();
			break;
		case 2:
			deleteItemOrder();
			break;
		case 3:
			generateBill();
			break;
		case 4:
			displayTables();
			break;
		case 5:
			// nothing needs to be done for logout
			system("cls");
			break;
		}
	} while (choice != 5);

}


// CREATE EMPLOYEE FILE
//ofstream outFile;
//
//outFile.open("employeeInfo.txt");
//Employee e1, e2, e3, e4, e5;
//Employee mEmp[5];
//
//mEmp[0] = Employee("Elena Kagan", "Massachusetts", "8025551960", "111111111", 0, 20.11);
//mEmp[1] = Employee("Sonia Sotomayor",  "New York", "8025551954", "222222222", 1, 20.09);
//mEmp[2] = Employee("Samuel Alito",   "New Jersey", "8025551950", "333333333", 2, 20.06);
//mEmp[3] = Employee("John Roberts"       , "Maryland", "8025551955", "444444444", 3, 20.05);
//mEmp[4] = Employee("Stephen Breyer", "Massachusetts", "8025551938", "555555555", 0, 19.94);

//
//outFile << mEmp[0];
//outFile << mEmp[1];
//outFile << mEmp[2];
//outFile << mEmp[3];
//outFile << mEmp[4];

//outFile.close();


// CREATE TABLE STATES FILE  -- ASSUMES MATCHING ITEMS ON DINING MENU LOADED
//mTables[0].addToOrder(mDiningMenu.getItem("Tiramisu"));
//mTables[0].addToOrder(mDiningMenu.getItem("Steak Nuovo di York"));
//mTables[0].addToOrder(mDiningMenu.getItem("Soda"));
//mTables[0].addToOrder(mDiningMenu.getItem("Risotto"));
//mTables[5].addToOrder(mDiningMenu.getItem("Limonata"));
//mTables[5].addToOrder(mDiningMenu.getItem("Lasagna"));
//mTables[5].addToOrder(mDiningMenu.getItem("Cannoli"));
//mTables[5].addToOrder(mDiningMenu.getItem("Cake"));
//mTables[5].addToOrder(mDiningMenu.getItem("Cannoli"));
//mTables[5].addToOrder(mDiningMenu.getItem("Steak Nuovo di York"));
//mTables[10].addToOrder(mDiningMenu.getItem("Bruschetta"));
//mTables[10].addToOrder(mDiningMenu.getItem("Lasagna"));
//mTables[10].addToOrder(mDiningMenu.getItem("Italian Soda"));
//
//mTables[0].setSeatsOccupied(2);
//mTables[5].setSeatsOccupied(2);
//mTables[10].setSeatsOccupied(2);
//
//saveTableStates();
//
//cout << "\n\nLet's see what we get: \n";
//
//displayDinerMenu();
//
//displayTables();
//
//cout << "\n\nEnter to continue\n";
//string pause;
//getline(cin, pause);