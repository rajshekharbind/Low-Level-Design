#include<bits/stdc++.h>
using namespace std;

// History Constraints Rule :
// A subclass should not weaken the history constraints of the parent class.
// History constraints are the rules that govern the state changes of an object over time.

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

    //History constraint: withdrawal should be allowed only if the balance is sufficient.

    virtual void withdraw(double amount){
        if(balance - amount < 0){
            throw runtime_error("Insufficient balance");  
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
    }
};

class FixedDepositAccount : public BankAccount {
    public:
        FixedDepositAccount(double balance) : BankAccount(balance) {}
        
        // This method violates the history constraints of the parent class
        // by allowing withdrawal even if it results in negative balance.
        void withdraw(double amount) override {
            throw runtime_error("Withdrawals are not allowed from Fixed Deposit Account");
        }
};

int main(){
    
    BankAccount* account1 = new BankAccount(100);
    account1->withdraw(50); // Valid withdrawal

    return 0;
}