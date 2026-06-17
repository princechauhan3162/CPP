#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string ownerName;
    float balance;

public:
    void input()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Owner Name: ";
        getline(cin, ownerName);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void credit(float amount)
    {
        balance = balance + amount;
        cout << "Amount Credited Successfully." << endl;
    }

    void debit(float amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Debited Successfully." << endl;
        }
        else
        {
            cout << "Insufficient Balance." << endl;
        }
    }

    void displayBalance()
    {
        cout << "\n----- Account Details -----" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Owner Name     : " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1;

    float amount;

    b1.input();

    cout << "\nEnter Amount to Credit: ";
    cin >> amount;
    b1.credit(amount);

    cout << "\nEnter Amount to Debit: ";
    cin >> amount;
    b1.debit(amount);

    b1.displayBalance();

}