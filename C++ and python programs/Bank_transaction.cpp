//A Simple C++ program to compute the bank transactions and print the information of the customers
#include<iostream>
#define SIZE 20
using namespace std;

class account
{
  private:
     long int account_no;
     int pin;
     int amount;
  public:
     string name;
     string ifsc;
     void read_info();
     void deposit(int);
     void print_info();
     int withdraw(int);
     void current_balance();
     int check_account(long int);
};

void account :: read_info()
{
  cout<<"Enter your name"<<endl;
  cin>>name;
  cout<<"Enter the Account Number"<<endl;
  cin>>account_no;
  cout<<"Enter your PIN"<<endl;
  cin>>pin;
  cout<<"Enter the IFSC code of the bank"<<endl;
  cin>>ifsc;
  amount=0;
}

void account :: deposit(int money)
{
  amount += money;
}

void account :: print_info()
{
  cout<<"Name : "<<name<<endl;
  cout<<"Account No:- "<<account_no<<endl;
  cout<<"Balance : "<<amount<<" Rs"<<endl;
  cout<<"IFSC code : "<<ifsc<<endl;
}

int account :: withdraw(int money)
{
  int check;
  cout<<"Enter your PIN"<<endl;
  cin>>check;
    
  if(check != pin)
  {
     cout<<"Wrong PIN. Please enter Valid Pin!!"<<endl<<"Transaction closed"<<endl;
     return -1;
  }
  if(money > amount)
  {
     cout<<"Insufficient balance. Transaction Failed!!"<<endl;
     return -1;
  }
  if((check == pin) && (money < amount))
     amount -= money;

return 1;
}

void account :: current_balance()
{
  cout<<"Current balance is:-"<<endl<<amount<<" Rs"<<endl;
}

int account :: check_account(long int number)
{
  if(number == account_no)
    return 1;
  else
    return -1;
}

void read(account*, int);
void print(account*, int);
int index_of_customer(account*, int, long int);
int main()
{
  int n, money, acc_no, serial_no;
  char choice='1';
 
  cout<<"***Welcome to ABCD bank***"<<endl<<endl;
    cout<<"Create your account by following the below steps..."<<endl;
  account customer[SIZE];
  cout<<"Enter the number of Customers\n";
  cin>>n;
  read(customer,n);
  print(customer,n);

  while(choice!='0')
  {
    cout<<"Enter 1 to deposit\nEnter 2 to withdraw\nEnter 3 to exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    if(choice < '0' || choice > '3')
    {
      cout<<"\nEnter the valid choice!!\n"<<endl;
      continue;
    }
    if(choice == '3')
    {
      cout<<"Thank you for using our services"<<endl<<"Have a nice day!!"<<endl;
      break;
    }
    
    cout<<"Enter your account no"<<endl;
    cin>>acc_no;
    
    serial_no = index_of_customer(customer,n,acc_no);
    if(serial_no < 0)
      continue;
    
    if(choice == '1')
    {
       cout<<"Enter the money to be deposited"<<endl;
       cin>>money;
       customer[serial_no].deposit(money);
       cout<<"Successfully deposited!!"<<endl;
       customer[serial_no].current_balance();
    }
    else if(choice == '2')
    {
       cout<<"Enter the money to be withdrawn"<<endl;
       cin>>money;
       if(customer[serial_no]. withdraw(money) == -1)
          continue;
       else
          cout<<"Successfully Withdrawn!!"<<endl;
       customer[serial_no].current_balance();
    }
    
  }
  return 0;
}

void read(account *customer, int n)
{
 int money;
 for(int i=0; i<n; i++)
  {
    cout<<"Enter customer no "<<i+1<<" details"<<endl;
    customer[i].read_info();
    cout<<"Your bank balance is 0 Rs"<<endl<<"Enter the amount you want to deposit"<<endl;
    cin>>money;
    customer[i].deposit(money);
  }
}

void print(account *customer, int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"The details of customer no "<<i+1<<" is"<<endl;
    customer[i].print_info();
    cout<<endl;
  }
}
    
int index_of_customer(account *customer, int n, long int acc_no)
{
  for(int i=0; i<n; i++)
    if(customer[i].check_account(acc_no) == 1)
        return i;
  cout<<"Entered Account Number not found in Database. Please Enter the Valid account number!!"<<endl<<endl;
  return -1;
}