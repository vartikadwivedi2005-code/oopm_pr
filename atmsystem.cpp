#include <iostream> 
#include <string> 
#include <vector> 
 
using namespace std; 
 
class Account { 
private: 
    string accountNumber; 
    string accountHolder; 
    string pin; 
    double balance; 
 
public: 
    Account(string accNum, string accHolder, string pin, double 
initBalance) 
        : accountNumber(accNum), accountHolder(accHolder), 
pin(pin), balance(initBalance) {} 
 
    string getAccountNumber() { 
        return accountNumber; 
    } 
 
    string getAccountHolder() { 
        return accountHolder; 
    } 
 
    double getBalance() { 
        return balance; 
    } 
 
    bool verifyPin(string enteredPin) { 
        return pin == enteredPin; 
    } 
 
    void deposit(double amount) { 
        if (amount > 0) { 
            balance += amount; 
            cout << "Deposited: " << amount << "\nNew Balance: " << balance << endl; 
        } else { 
 
 
            cout << "Invalid deposit amount.\n"; 
        } 
    } 
 
    bool withdraw(double amount) { 
        if (amount <= balance && amount > 0) { 
            balance -= amount; 
            cout << "Withdrawn: " << amount << "\nNew Balance: " << balance << endl; 
            return true; 
        } else { 
            cout << "Insufficient funds or invalid amount.\n"; 
            return false; 
        } 
    } 
 
    void showBalance() { 
        cout << "Account Balance: " << balance << endl; 
    } 
}; 
 
class Transaction { 
private: 
    Account &account; 
 
public: 
    Transaction(Account &acc) : account(acc) {} 
 
    void withdrawAmount(double amount) { 
        if (!account.withdraw(amount)) { 
            cout << "Transaction failed.\n"; 
        } 
    } 
 
    void depositAmount(double amount) { 
        account.deposit(amount); 
    } 
 
    void checkBalance() { 
        account.showBalance(); 
    } 
}; 
 
class ATM { 
private: 
    vector<Account> accounts; 
    Account* currentAccount; 
 
public: 
 
 
    ATM() : currentAccount(nullptr) {} 
 
    void addAccount(Account acc) { 
        accounts.push_back(acc); 
    } 
 
    Account* authenticate(string accNum, string pin) { 
        for (auto &acc : accounts) { 
            if (acc.getAccountNumber() == accNum && 
acc.verifyPin(pin)) { 
                currentAccount = &acc; 
                return currentAccount; 
            } 
        } 
        cout << "Authentication failed!\n"; 
        return nullptr; 
    } 
 
    void displayMenu() { 
        if (!currentAccount) { 
            cout << "No account logged in.\n"; 
            return; 
        } 
        cout << "\nATM Menu\n"; 
        cout << "1. Deposit\n"; 
        cout << "2. Withdraw\n"; 
        cout << "3. Check Balance\n"; 
        cout << "4. Exit\n"; 
    } 
 
    void performTransaction(int choice) { 
        if (!currentAccount) { 
            cout << "Please log in first.\n"; 
            return; 
        } 
        Transaction txn(*currentAccount); 
        double amount; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter amount to deposit: "; 
            cin >> amount; 
            txn.depositAmount(amount); 
            break; 
        case 2: 
            cout << "Enter amount to withdraw: "; 
            cin >> amount; 
            txn.withdrawAmount(amount); 
            break; 
 
 
        case 3: 
            txn.checkBalance(); 
            break; 
        case 4: 
            cout << "Exiting ATM...\n"; 
            currentAccount = nullptr; 
            break; 
        default: 
            cout << "Invalid choice.\n"; 
        } 
    } 
}; 
 
int main() { 
    ATM atm; 
 
    // Adding sample accounts 
    Account acc1("12345", "John Doe", "1234", 5000); 
    Account acc2("67890", "Jane Smith", "5678", 3000); 
    atm.addAccount(acc1); 
    atm.addAccount(acc2); 
 
    string accNum, pin; 
    cout << "Enter Account Number: "; 
    cin >> accNum; 
    cout << "Enter PIN: "; 
    cin >> pin; 
 
    Account* loggedInAccount = atm.authenticate(accNum, pin); 
 
    if (loggedInAccount) { 
        int choice; 
        do { 
            atm.displayMenu(); 
            cout << "Select an option: "; 
            cin >> choice; 
            atm.performTransaction(choice); 
        } while (choice != 4); 
    } 
 
    return 0; 
} 