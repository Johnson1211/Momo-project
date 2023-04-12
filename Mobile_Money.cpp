#include <iostream>
using namespace std;

// Default PIN and balance
const int DEFAULT_PIN = 0000;
const int DEFAULT_BALANCE = 1000;

// Maximum number of allowed wrong PIN attempts
const int MAX_WRONG_PIN_ATTEMPTS = 3;

int main() {
    int pin = DEFAULT_PIN;
    int balance = DEFAULT_BALANCE;
    int wrongPinAttempts = 0;
    int financial_option;
    int option;

    // Loop for program execution
    while (true) {
        cout << "________________________" << endl;
        cout << "Mobile Money Service" << endl;
        cout << "________________________" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Financial Services" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                if (enteredPin == pin) {
                    cout << "Authentication successful!" << endl <<endl;
                    wrongPinAttempts = 0;
                    // Reset wrong PIN attempts counter
                } else {
                    cout << "Incorrect PIN! \nPlease try again!" << endl <<endl;
                    wrongPinAttempts++;

                    if (wrongPinAttempts >= MAX_WRONG_PIN_ATTEMPTS) {
                        cout << "Maximum wrong PIN attempts reached. Exiting..." << endl;
                        return 0;
                    }
                }
                break;
            }
            // Resetting Pin
            case 2: {
                int oldPin, newPin;
                cout << "Enter old PIN: ";
                cin >> oldPin;
                cout << "Enter new PIN: ";
                cin >> newPin;
                pin = newPin; // Update PIN
                cout << "PIN changed successfully!" << endl <<endl;
                break;
            }
            // Checking Balance
            case 3: {
                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;
                if (enteredPin == pin) {
                    cout << "Your balance is: GHC" << balance << endl <<endl;
                } else {
                    cout << "PIN is incorrect" << endl <<endl;
                }
                break;
            }
            // Sending Money
            case 4: {
                int amount, number, enteredPin;
                cout << "Enter Mobile Number: " << endl;
                cin >> number;
                cout << "Enter amount to send: GHC";
                cin >> amount;
                cout << "Enter pin: " << endl;
                cin >> enteredPin;
                if (enteredPin == pin) {
                    cout << "Payment made for GHC" << amount <<" to " << number << endl <<endl;
                } else {
                    cout << "You have entered a wrong Pin" << endl <<endl;
                    break;
                }

                if (amount > balance) {
                    cout << "You do not have sufficient funds to perform this transaction." << endl <<endl;
                } else {
                    balance -= amount; // Deduct sent amount from balance
                    cout << "Your current balance is: GHC" << balance << endl <<endl;
                }
                break;
            }
            // Althernative Options
            case 5: {
                int financial_option;
                int amount;
                cout << "Choose an Option" << endl;
                cout << "1. Borrow Money" << endl;
                cout << "2. Repay Loan" << endl;
                cout << "3. Buy Airtime" << endl;
                cout << "4. Buy Bundle" << endl;
                cout << "Enter an Option: ";
    cin >> financial_option;

    switch(financial_option){
    	// borrowing money
        case 1:{
            cout<<"Enter an amount to borrow(0.01 - 200): ";
            cin >> amount;
            if(amount>200){
                cout <<"Transaction failed. \nAmount exceeds limit." <<endl <<endl;
            }
            else{
                balance+=amount;
                cout <<"Current Amount is GHC " << balance <<endl <<endl;
                cout <<"Money has been sent to your account successfully" <<endl <<endl;
            }
        }
        // Repaying Loan
        case 2:{
            cout<<"Enter Amount to Pay(0.01 - 200): ";
            cin>>amount;
            if(amount>200){
                cout <<"REPAY LOAN UNSUCCESSFUL. \nAmount exceeds limit." <<endl;
            }
            else{
                balance-=amount;
                cout << "An amount of GHC"<< amount << "has been deducted from your account. \nCurrent balance is GHC" <<balance <<endl;
                cout <<"REPAYING LOAN SUCCESSFUL.\n" <<endl;
            }
            break;
        }
        // buying airtime
        case 3:{
            cout<<"Enter Amount(0.01 - 500):";
            cin>>amount;
            if(amount>500){
                cout <<"BUYING AIRTIME UNSUCCESSFUL. \nAmount exceeds limit." <<endl <<endl;
            }
            else{
                balance-=amount;
                cout <<"Current Balance is GHC" <<balance <<endl;
                cout <<"BUYING AIRTIME SUCCESSFUL.\n" <<endl <<endl;
            }
            break;
        }
        // buying bundle
        case 4:{
            cout<<"Enter an amount to buy (0.01 - 500):";
            cin>>amount;
            if(amount>500){
                cout <<"BUYING BUNDLE UNSUCCESSFUL. \nAmount exceeds limit." <<endl <<endl;
            }
            else{
                balance-=amount;
                cout <<"BALANCE AVAILABLE IS GHC" <<balance <<endl;
                cout <<"BUYING BUNDLE SUCCESSFUL.\n" <<endl <<endl;
            }
            break;
        }
        default: {
            cout << "Invalid Option. Please try again." << endl;
            break;
        }
    }
}

			// exiting program
            case 6: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid option! Please try again." << endl;
                break;
            }
        }
    }
  
	
    return 0;
}
