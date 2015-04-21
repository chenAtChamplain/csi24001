/*
Author: JT Woodside
Class: CSI-240-01
Assignment: Final Project
Date Assigned: 3/17/15
Due Date: 4/24/15 11:00AM
 
Description:
A class allowing waiters to add items to an order as well as change or delete those items
 
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, 
for the purpose of assessing this assignment:
-Reproduce this assignment and provide a copy to another member of academic staff; and/or
-Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/
#include"waiter.h"  
  
Waiter::Waiter()  
{  
}  
  
Waiter::~Waiter()  
{ 
}  
   
bool Waiter::takeOrder(vector<string> mTakeOrder)   
{
   //pre:
   //post:
   //purpose:

   const int ORDER_NUM = 10; 
   string order1; 

   std::vector<string> order(ORDER_NUM); 
 
   cout << "Enter The Customers Order: " << endl; 
   cin >> order1;

   order.push_back(order1); 

   return true;  // wkc:  I am not sure what to return here
}   
    
bool Waiter::changeItemOrder(vector<string> order, int numChange, string newOrder)   
{ 
   //pre:
   //post:
   //purpose:
    
   order[numChange] = newOrder;

   return true;  // wkc:  I am not sure what to return here  
}   
   
bool Waiter::deleteItemOrder(vector<string> order, int numChange)   
{  
   //pre:
   //post:
   //purpose:
   
   order.erase(order.begin() + numChange);

   return true;  // wkc:  I am not sure what to return here
}  


int Waiter::getEmployeeType()
{
   return 0; //  wkc:  I am not sure what to return here
}