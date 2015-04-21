/*
Class: CSI-240-01
Assignment: FINAL PROJECT
Date Assigned: 3/17/15
Due Date: 4/24/15 11:00AM

Description:
A class for organizing table data for a restaurant program

Certification of Authenticity:
We certify that this is entirely our own work, except where we have given fully
documented references to the work of others. We understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
-Reproduce this assignment and provide a copy to another member of
academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/


//  Author: Evan Nudd and Johnna Ferguson and Danial Thomas

#include "restaurant.h"


Restaurant::Restaurant()
{
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
   LinkedList mMenuItems;
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

   cout << "Please go fuck yourself: ";
   cin >> newInt;

   return mMenuItems.push(newItem);
}

void Restaurant::billPaid()
{
}


void Restaurant::changeEmployee()
{
}


bool Restaurant::changeItemOrder(vector<string> order, int numChange, string newOrder)
{
   //pre: An order has been taken
   //post: Allows change within the vector
   //purpose: 
   //Author: JT Woodside

   order[numChange] = newOrder;

   return true;
}


//Pre: mMenuItems exists
//Post: The original item is removed and replaces with another item
//Purpose: To allow the cook to change times on the menu.
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
   if (!mMenuItems.isExist(searchKey))
   {
      return false;
   }

   tempItem = mMenuItems.getItem(searchKey);
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

   mMenuItems.remove(searchKey);
   mMenuItems.push(tempItem);


   return changed;
}


void Restaurant::changeMenuPrice()
{
}


bool Restaurant::checkOrderStatus(int orderNumber) //but there is no order number
{
   return false;
}


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
   system("cls");
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
   NumberList orderList;

   do
   {
      cookMenu();
      int choice = getInputBetween(0, COOK_NUM_OPTIONS);

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
         // no one made functions for removing items...
         break;
      case 3:
         addMenuItem();
         break;
      case 4:
         viewOrderInProgress(orderList);
         break;
      case 5:
         checkOrderStatus(1);  // wkc:  this need an int as parameter.  I am putting things here just to make it compiles
         break;
      case 6:
         // nothing needs to be done for logout.
         break;
      }
   } while (choice != 6);
}


void Restaurant::dailyReport()
{
}


bool Restaurant::deleteItemOrder(vector<string> order, int numChange)
{
   //pre: None
   //post: Item(s) are deleted from the vector
   //purpose: To delete items from the vector
   //Author: JT Woodside

   order.erase(order.begin() + numChange);

   return true;
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

   if (mMenuItems.isExist(searchKey))
   {
      mMenuItems.remove(searchKey);
      removed = true;
   }

   return removed;
}


void Restaurant::displayDinerMenu()
{
}


void Restaurant::displayOpenTables()
{
}


void Restaurant::displayTables()
{
}


void Restaurant::fireEmployee()
{
}


void Restaurant::generateBill()
{
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

      if (selection >= min && selection < max)
         valid = true;
   } while (!valid);

   return selection;
}

void Restaurant::hireEmployee()
{
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
         // no function has been made for this assignment
         break;
      case 2:
         // no function has been made for this assignment
         break;
      case 3:
         // nohting needs to be done for logout
         break;
      }
   } while (choice != 3);

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
      while (!fin.eof())
      {
         fin >> item;
         mDiningMenu.insertInOrderNoRepeat(item);
      }
   }
   else
   {
      cout << "Saved Menu Not Found\n";
   }
   fin.close();
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

         break;
      case 3:
         searchEmployee();
         break;
      case 4:
         // no function for selecting daily staff?
         break;
      case 5:
         generateBill();
         break;
      case 6:
         // nothing needs to be done for logout
         break;
      case 7:
         // add what ev else you want this to do here. like write files.
         exit(0);
         break;
      }
   } while (choice != 7);

}


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
            cout << "\nloading: " << item.getName();
            mTables[index].getOrders().insertInOrder(item);
            ch = fin.peek();
            cout << "\n peek: " << ch << endl;
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
      if (!(mTables[i].getOrders().empty()))
      {
         //iterate through list to ofstream
         nextItem = mTables[i].getOrders().pop();
         do {
            fout << nextItem;
            listRebuild.insertInOrder(nextItem);
            nextItem = mTables[i].getOrders().pop();
         } while (!(nextItem == ""));

         //iterate through rebuilding list
         nextItem = listRebuild.pop();
         do {
            mTables[i].getOrders().insertInOrder(nextItem);
            nextItem = listRebuild.pop();
         } while (!(nextItem == ""));
      }

      fout << "#Table" << i + 1 << " ";
      fout << mTables[i].getNumberOfSeats() << " ";
      fout << mTables[i].getSeatsOccupied() << " " << endl;
   }
   fout.close();
}


void Restaurant::searchEmployee()
{
}


bool Restaurant::seatTable()
{
   return false;
}


bool Restaurant::seatTable(int& tableId, string& waiter) // no waiter; 
{
   return false;
}


void Restaurant::shutDown()
{
}


bool Restaurant::takeOrder(vector<string>mTakeOrder)
{
   //pre: None
   //post: The vector is created and the order is stored
   //purpose:to store the order in the vector
   //Author: JT Woodside

   const int ORDER_NUM = 10;
   string order1;

   std::vector<string> order(ORDER_NUM);

   cout << "Enter The Customers Order: " << endl;
   cin >> order1;

   order.push_back(order1);

   return true;
}


void Restaurant::viewOrderInProgress(NumberList orderList)
{
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
   vector<string> order;
   int numChange = 0;

   do
   {
      waitMenu();
      choice = getInputBetween(0, WAIT_NUM_OPTIONS);

      // act on the choice
      switch (choice)
      {
      case 0:
         takeOrder(order);
         break;
      case 1:
         changeItemOrder(order, numChange, "abc");  // wkc:  not sure what is happending here
         break;
      case 2:
         deleteItemOrder(order, numChange);
         break;
      case 3:
         generateBill();
         break;
      case 4:
         displayTables();
         break;
      case 5:
         // nothing needs to be done for logout
         break;
      }
   } while (choice != 5);

}
























///*
//* Pre: normal day-startup is rerun.
//*
//* Post: table states are restored from file
//*
//* Purpose: to recover data after power outage
//*
//* Author: Johnna
//*/
//void Restaurant::restoreTableStates()
//{
//   ifstream fin(TABLE_STATES);
//   MenuItem item;
//   string junk;
//   char ch;
//   int numSeats, numDiners;
//   int index = 0;
//
//   if (!fin.fail())
//   {
//      while ((!fin.eof()) && (index < MAX_TABLES))
//      {
//         ch = fin.peek();
//         while (!fin.eof() && (ch != '#'))
//         {
//            fin >> item;
//            cout << "\nloading: " << item.getName();
//            mTables[index].getOrders().insertInOrder(item);
//            ch = fin.peek();
//            cout << "\n peek: " << ch << endl;
//         }
//
//         fin >> junk
//            >> numSeats
//            >> numDiners;
//         getline(fin, junk);
//         mTables[index].setNumberOfSeats(numSeats);
//         mTables[index].setSeatsOccupied(numDiners);
//         index++;
//      }
//   }
//   else
//   {
//      cout << "Saved Menu Not Found\n";
//   }
//
//   fin.close();
//}











