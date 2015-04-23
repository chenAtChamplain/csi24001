#ifndef _waiter_H  
#define _waiter_H  
 
#include<string> 
#include<iostream> 
#include<sstream>
#include<vector>

#include "employee.h"
using namespace std; 
 
class Waiter : public Employee
{ 
   private:  
      vector<string>mTakeOrder;

   public:  
      Waiter();  
      ~Waiter();  
  
      virtual int getEmployeeType(); 
 
      bool takeOrder(vector<string> mTakeOrder);  
      bool changeItemOrder(vector<string> order, int numChange, string newOrder);  
      bool deleteItemOrder(vector<string> order, int numChange); 

      void generateBill();  
      void billPaid();  
      void displayTables();  
};  
   
#endif   