#pragma once
#include <iostream>
#include <string>

#include "employee.h"
#include "table.h"
#include "NumberList.h" //or whatever Matt really names it
#include <conio.h>
#include <vector>

const int MAX_TABLES = 15;
const int tableSizes[] = { 2, 2, 4, 4, 4, 4, 4, 2, 6, 4, 4, 4, 2, 6, 4 };

const string LOGIN_FILE_NAME = "login.txt",
             DINER_MENU = "diningMenu.txt",
             TABLE_STATES = "tableState.txt",
			    EMPLOYEE_FILE = "employeeInfo.txt",
             CHANGE_BUFFER = "temp.txt";    //NEEDED FOR ChangeEmployee()

/* Amount of options in each employee menu. */
const int MANAGER_NUM_OPTIONS = 7;
const int HOST_NUM_OPTIONS = 4;
const int WAIT_NUM_OPTIONS = 6;
const int COOK_NUM_OPTIONS = 7;

/* Each of the Employee's options. */
const string RESTAURANT_TITLE = "Wei's Place";

const string MANAGER_OPTIONS[MANAGER_NUM_OPTIONS] {
		"Hire Employee",
		"Fire Employee",
		"Update Employee Data",
		"Search for Employee", 
		"Generate Daily Report",
		"Log Out",
		"Shut Down"
};

const string HOST_OPTIONS[HOST_NUM_OPTIONS] {
		"Display Empty Tables",
		"Assign Party Size",
		"Make Table Available",
		"Log Out"
};

const string WAIT_OPTIONS[WAIT_NUM_OPTIONS] {
		"Take Order",
		"Change Items In Order",
		"Delete Items In Order",
		"Generate Bill",
		"Display Occupied Tables",
		"Log Out"
};

const string COOK_OPTIONS[COOK_NUM_OPTIONS] {
	"Display Item Menu",
		"Change Item on Menu",
		"Delete Item on Menu",
		"Add Item to Menu",
		"View Orders To Be Completed",
		"Check Order Status",
		"Log Out"
};



class Restaurant
{
private:
	int mNumOfOrders; //for adding up cumulative number of table orders for End Of Day Report
	double mGrandTotal; //for adding up bills as we go along for End Of Day Report
	Employee mCurrentUser;
	NumberList mKitchenList;  //improve variable name?
	LinkedList mDiningMenu;  //better: DiningMenu mDiningMenu;
	Table mTables[MAX_TABLES];

	bool addMenuItem();
	void billPaid();
	void changeEmployee();
	bool changeItemOrder();
	bool changeItemOrder(vector<string> order, int numChange, string newOrder);
	bool changeMenuItem();
	void changeMenuPrice();
	bool checkOrderStatus(int orderNumber); //but there is no order number
	bool clearTable();
	void cookMenu();
	void dailyReport();
	void deleteItemOrder();
	bool deleteItemOrder(vector<string> order, int numChange);
	bool deleteMenuItem();
	void displayDinerMenu();
	void displayOpenTables();
	void displayTables();
	void fireEmployee();
	void generateBill();
	int  getInputBetween(int min, int max);
	void hireEmployee();
	void hostMenu();
	void login();
	void login(string user);
   void loadDinerMenu();
	void managerMenu();
	void orderReady();
	void restoreTableStates();
   void saveDinerMenu();
	void saveTableStates();
	void searchEmployee();
	bool seatTable();
	bool seatTable(int& tableId, string& waiter); // no waiter; 
	void shutDown();
	void takeOrder();
	bool takeOrder(vector<string>mTakeOrder);

	void viewOrderInProgress(NumberList &orderList);
	void waitMenu();
	void waitOperations();
	void hostOperations();
	void managerOperations();
	void cookOperations();

public:
	Restaurant();
	~Restaurant();
	void testRun();


   void runRestaurant();


};

