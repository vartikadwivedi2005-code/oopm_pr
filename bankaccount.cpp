#include <iostream> 
#include <string> 
using namespace std; 
 
class BankAccount { 
protected: 
    string accountHolderName; 
    double balance; 
 
public: 
    BankAccount(string name, double initialBalance) 
        : accountHolderName(name), balance(initialBalance) 
{} 
 
    virtual void displayAccountDetails() { 
    cout << "Account Holder: " << accountHolderName << endl; 
    cout << "Balance: " << balance << endl; 
    } 
 
    virtual void calculateInterest() { 
    cout << "No specific interest rate applied for base account." << endl; 
    } 
 
    virtual ~BankAccount() {} 
}; 
 
class SavingsAccount : public BankAccount { 
private: 
    double interestRate; 
 
public: 
    SavingsAccount(string name, double initialBalance, 
double rate) : BankAccount(name, initialBalance), 
interestRate(rate) {} 
 
    void calculateInterest() override { 
   double interest = balance * (interestRate / 100); 
   cout << "Savings Account Interest: " << interest << endl; 
    } 
 
 
 
    void displayAccountDetails() override { 
   cout << "Savings Account Holder: " << accountHolderName 
<< endl; 
        cout << "Balance: " << balance << endl; 
        cout << "Interest Rate: " << interestRate << "%" << 
endl; 
    } 
}; 
 
class CurrentAccount : public BankAccount { 
private: 
    double overdraftLimit; 
 
public: 
    CurrentAccount(string name, double initialBalance, double overdraft) 
        : BankAccount(name, initialBalance), overdraftLimit(overdraft) {} 
 
    void displayAccountDetails() override { 
   cout << "Current Account Holder: " << accountHolderName << endl; 
   cout << "Balance: " << balance << endl; 
   cout << "Overdraft Limit: " << overdraftLimit << endl; 
    } 
 
    void calculateInterest() override { 
         cout << "Current Account has no interest applied." << endl; 
    } 
}; 
 
class BankingOperations { 
public: 
    void deposit(double amount, double &balance) { 
        balance += amount; 
        cout << "Deposited " << amount << ". New Balance: " << balance << endl; 
    } 
 
    void deposit(double amount, double &balance, double bonus) { 
        balance += amount + bonus; 
        cout << "Deposited " << amount << " with bonus " << bonus << ". New Balance: " << balance << endl; 
    } 
}; 
 
    int main() { 
 
 
 
    double balance = 1000.0; 
    BankingOperations operations; 
    operations.deposit(500.0, balance); 
    operations.deposit(500.0, balance, 50.0); 
 
    cout << "\n"; 
 
    BankAccount *account1 = new SavingsAccount("Alice",2000.0, 5.0); 
    BankAccount *account2 = new CurrentAccount("Bob",1500.0, 500.0); 
 
    account1->displayAccountDetails(); 
    account1->calculateInterest(); 
 
    cout << "\n"; 
 
    account2->displayAccountDetails(); 
    account2->calculateInterest(); 
 
    delete account1; 
    delete account2; 
 
    return 0; 
} 