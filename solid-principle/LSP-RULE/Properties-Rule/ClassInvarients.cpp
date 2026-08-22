#include<bits/stdc++.h>
using namespace std;



// BankAccount class that adheres to the Liskov Substitution Principle

//Invarient: The balance of a BankAccount should never be negative.
class BankAccount {
    protected:
        double balance;
        public:
        BankAccount(double balance){
            if(balance<0){
                throw invalid_argument("Balance cannot be negative");
            }
            this->balance = balance;
        }
        virtual void withdraw(double amount){
            if(balance - amount < 0){
                throw runtime_error("Insufficient balance");  
            }
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
    };
    

    // CheatAccount class that violates the Liskov Substitution Principle
    class CheatAccount : public BankAccount {
        public:
        CheatAccount(double balance) : BankAccount(balance) {}
        void withdraw(double amount) override {
            // This violates the Liskov Substitution Principle
            // by allowing withdrawal even if it results in negative balance.
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
    };

    int main(){
        
        BankAccount* account1 = new BankAccount(100);
        account1->withdraw(50); // Valid withdrawal

        BankAccount* account2 = new CheatAccount(100);
        account2->withdraw(150); // This should not be allowed, but it is due to violation of LSP

        return 0;
    }