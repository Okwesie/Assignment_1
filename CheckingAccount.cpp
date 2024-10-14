#include "CheckingAccount.hpp" // Include the header file for the CheckingAccount class
#include <iostream>            // Include the iostream library for input/output
#include <string>             // Include the string library for using string objects
using namespace std;          // Use the standard namespace

// Default constructor initializes a CheckingAccount with no fees and sets the initial balance
CheckingAccount::CheckingAccount()
        :Account() { // Call the base class constructor
    feePerTransaction = 0; // Set the transaction fee to 0
    initialBalance = getBalance(); // Initialize initialBalance with the current account balance
}

// Parameterized constructor to initialize a CheckingAccount with specific values
CheckingAccount::CheckingAccount(int accNumber, string firstName, string lastName, string dob, string gender, string address, int phoneNumber, string email, int accNo, double accBal, string accountType, double feePerTransaction)
                :Account(accNumber, firstName, lastName, dob, gender, address, phoneNumber, email, accBal, accountType) { // Call the base class constructor
        this->feePerTransaction = feePerTransaction; // Set the transaction fee to the provided value
        initialBalance = getBalance(); // Initialize initialBalance with the current account balance
}

// Method to credit an amount to the CheckingAccount balance, deducting the transaction fee
void CheckingAccount::credit(double amount) {
    Account::credit(amount); // Call the base class credit method to add the amount
    // Deduct the transaction fee from the account balance
    setAccountBalance(getBalance() - feePerTransaction);
}

// Method to debit an amount from the CheckingAccount balance, deducting the transaction fee
void CheckingAccount::debit(double amount) {
    // Check if the debit is successful in the base class
    if (Account::debit(amount)) {
        // If successful, deduct the transaction fee from the account balance
        setAccountBalance(getBalance() - feePerTransaction);
    }
    else {
        cout << "Insufficient Balance"; // Print an error message if the debit fails due to insufficient funds
    }
}