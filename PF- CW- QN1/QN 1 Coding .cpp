#include <iostream>
#include <string>
using namespace std;

struct Account {
    string userId;
    string password;
    double balance;
};

Account account = {"", "", 0.0};  // Initially no account is created

bool createAccount() {
    cout << "Please enter your user id: ";
    cin >> account.userId;
    cout << "Please enter your password: ";
    cin >> account.password;
    account.balance = 0.0;  // Initial balance is $0.0
    cout << "Thank You! Your account has been created!\n";
    return true;
}

bool login() {
    string inputId, inputPassword;
    cout << "Please enter your user id: ";
    cin >> inputId;
    cout << "Please enter your password: ";
    cin >> inputPassword;

    if (inputId == account.userId && inputPassword == account.password) {
        cout << "Access Granted!\n";
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***\n";
        return false;
    }
}

void atmMenu() {
    char choice;
    do {
        cout << "d -> Deposit Money\n";
        cout << "w -> Withdraw Money\n";
        cout << "r -> Request Balance\n";
        cout << "q -> Quit\n";
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 'd': {
                double deposit;
                cout << "Amount of deposit: $";
                cin >> deposit;
                account.balance += deposit;
                break;
            }
            
            case 'w': {
                double withdrawal;
                cout << "Amount of withdrawal: $";
                cin >> withdrawal;
                if (withdrawal <= account.balance) {
                    account.balance -= withdrawal;
                } else {
                    cout << "Insufficient balance!\n";
                }
                break;
            }
            case 'r': {
                cout << "Your balance is $" << account.balance << ".\n";
                break;
            }
            case 'q':
                cout << "Thank you for using the ATM Machine!\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != 'q');
    
}



    int main() {
    char choice;

    cout << "Hi! Welcome to the ATM Machine!\n";

    do {
        cout << "Please select an option from the menu below:\n";
        cout << "l -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n";
        cout << "For Example\n> ";
        cin >> choice;

        switch (choice) {
            case 'l':
                if (login()) {
                    atmMenu();
                }
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != 'q');

    return 0;
}














