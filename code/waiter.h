#ifndef _waiter_H  
#define _waiter_H  
 
#include<string> 
#include<iostream> 
#include<sstream>
#include<vector>
 
using namespace std; 
 
class Waiter  
{ 
   private:  
      double mPay;  
  
      string mName;  
      string mAddress;  
      string mPhoneNumber;   
      string mSSN;  
      string mID;  
     
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