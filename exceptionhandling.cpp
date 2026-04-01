#include <iostream> 
#include <stdexcept> // For standard exceptions 
using namespace std; 
 
class BankAccount { 
private: 
    double balance; 
 
public: 
    BankAccount(double initial_balance) { 
        if (initial_balance < 0) { 
            throw invalid_argument("Initial balance cannot be negative!"); 
        } 
        balance = initial_balance; 
    } 
 
    void deposit(double amount) { 
        if (amount <= 0) { 
            throw invalid_argument("Deposit amount must be positive!"); 
        } 
        balance += amount; 
        cout << "Deposited: " << amount << endl; 
    } 
 
    void withdraw(double amount) { 
        if (amount <= 0) { 
            throw invalid_argument("Withdrawal amount must be positive!"); 
        } 
        if (amount > balance) { 
            throw runtime_error("Insufficient funds for withdrawal!"); 
        } 
        balance -= amount; 
        cout << "Withdrawn: " << amount << endl; 
    } 
 
    void checkBalance() const { 
        cout << "Current balance: " << balance << endl; 
 
 
    } 
}; 
 
int main() { 
    try { 
        BankAccount account(1000); 
 
        account.checkBalance(); 
 
        account.deposit(500); 
 
        account.deposit(-100); 
 
    } catch (const invalid_argument &e) { 
        cout << "Invalid argument exception: " << e.what() << 
endl; 
    } catch (const runtime_error &e) { 
        cout << "Runtime exception: " << e.what() << endl; 
    } 
 
    try { 
        BankAccount account2(500); 
 
        account2.withdraw(600); 
    } catch (const invalid_argument &e) { 
        cout << "Invalid argument exception: " << e.what() << 
endl; 
    } catch (const runtime_error &e) { 
        cout << "Runtime exception: " << e.what() << endl; 
    } 
 
    return 0; 
}