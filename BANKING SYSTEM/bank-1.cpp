#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
    BankAccount()
    {
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }

    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited Successfully!" << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void calculateInterest()
    {
        cout << "No Interest Calculation Available." << endl;
    }
    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << getBalance() << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest = " << interest << endl;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount)
    {
        if (amount <= getBalance() + overdraftLimit)
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawal Successful!" << endl;
        }
        else
        {
            cout << "Overdraft Limit Exceeded!" << endl;
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit = " << overdraftLimit << endl;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal)
    {
        term = t;
    }

    void calculateInterest()
    {
        double interest = getBalance() * 0.08 * term / 12;
        cout << "Fixed Deposit Interest = " << interest << endl;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Term (Months) : " << term << endl;
    }
};
int main()
{
    SavingsAccount sa(101, "Prince", 10000, 5);
    CheckingAccount ca(102, "Rahul", 15000, 5000);
    FixedDepositAccount fa(103, "Amit", 20000, 12);

    BankAccount *ptr;

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Checking Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
            ptr = &sa;
        else if (choice == 2)
            ptr = &sa;
        else if (choice == 3)
            ptr = &sa;
        else if (choice == 4)
            break;
        else
        {
            cout << "Invalid Choice!" << endl;
            continue;
        }

        int option;

        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Calculate Interest" << endl;
        cout << "Enter Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter Amount: ";
            cin >> amount;
            ptr->deposit(amount);
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            ptr->withdraw(amount);
            break;

        case 3:
            ptr->displayAccountInfo();
            break;

        case 4:
            ptr->calculateInterest();
            break;

        default:
            cout << "Invalid Option!" << endl;
        }

    } while (choice != 4);

    cout << "\nThank You!" << endl;
}