/*
Question 2 : Create a class BankAccount with private attributes accountNumber and 
balance. Implement public methods deposit(), withdraw(), and getBalance() to 
manage the account.
*/

#include<iostream>
using namespace std;

class BankAccount{
    int account_no, balance;
public:
    BankAccount(int acc_no, int balance){
        this->account_no = acc_no;
        this->balance = balance;
    }

    void deposit(){
        int amount;
        cout<<"Enter the amount to deposit: ";
        cin>>amount;
        this->balance += amount;
        return;
    }

    void withdraw(){
        int amount;
        cout<<"Enter the amount to withdraw: ";
        cin>>amount;
        if(this->balance >= amount){
            this->balance -= amount;
        } else{
            cout<<"Balance is less.";
        }
    }

    int getBalance(){
        return this->balance;
    }
};

int main(){
    BankAccount myAccount(123456, 500); 
    myAccount.deposit(); 
    myAccount.withdraw();
    cout << "Current Balance: Rs." << myAccount.getBalance() << endl; 
    return 0;
}