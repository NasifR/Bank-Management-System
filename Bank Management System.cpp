#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

class Bank {
    string firstName, lastName, address, accType;
    int firstDeposit, balance;
    int depositAmount, withdrawAmount;
public:
    void open_acc();
    void deposit();
    void withdraw();
    void display_acc();

};


void Bank::withdraw() {
    cout << "Enter the amount you want to withdraw: " << endl;
    cin >> withdrawAmount;
    balance -= withdrawAmount;                             // if balance < 0: not enough balance
    if (balance < 0) {
        balance += withdrawAmount;
        cout << "Withdraw unsuccessful. Not enough balance available." << endl;
    }
    else {
        cout << "Withdraw successful. Current balance: $" << balance << endl;
    }
    
}
void Bank::display_acc() {
    cout << "Account information:\n";
    cout << "Full name: " << firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    if (accType == "1") {
        cout << "Account type: Savings" << endl;
    }
    if (accType == "2") {
        cout << "Account type: Checking" << endl;
    }
    cout << "Account balance: $" << balance << endl;
}

void Bank::deposit() {
    cout << "Enter the amount of money you want to deposit:" << endl;
    cin >> depositAmount;
    balance += depositAmount;
    cout << "Deposit successful! Your total balance is: $" << balance << endl;

}

void Bank::open_acc() {
    cout << "Enter your first name:" << endl;
    cin >> firstName;
    cout << "Enter your last name:" << endl;
    cin >> lastName;
    cout << "Enter your home address:" << endl;
    cin.ignore();
    getline(cin, address);
    
    while (accType != "1" && accType != "2") {
        cout << "Select the type of account you want to open:\n1) Savings\n2) Checking\n";
        cin >> accType;
        if (accType != "1" && accType != "2") {
            cout << "Invalid input" << endl;
        }
    }

    cout << "Enter the amount you want to deposit:\n";
    cin >> firstDeposit;
    balance = firstDeposit;
    cout << "Your account has been created!" << endl;
}



int main() {
    int opt;
    char x;
    Bank bank;
    do {
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw money\n";
        cout << "4) Account Information\n";
        cout << "5) Exit\n";
        cout << "\nEnter a number (1-5)\n";
        cin >> opt;
        switch (opt) {
        case 1: cout << "1) Open Account\n";
            bank.open_acc();
            break;
        case 2: cout << "2) Deposit Money\n";
            bank.deposit();
            break;
        case 3: cout << "3) Withdraw money\n";
            bank.withdraw();
            break;
        case 4: cout << "4) Account Information\n";
            bank.display_acc();
            break;
        case 5: cout << "5) Exit\n";
            return 0;
            break;
        default:
            cout << "Invalid input" << endl;
        }
        cout << "Continue? (Y/N)" << endl;
        cin >> x;
        if (x == 'n' || x == 'N') {
            exit(0);
        }

    } while (x == 'y' || x == 'Y');

    
    return 0;


}