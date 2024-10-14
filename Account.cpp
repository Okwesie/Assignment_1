#include "Account.hpp" // Include the header file for the Account class
#include <iostream>     // Include the iostream library for input/output
#include <ctime>       // Include the ctime library for time functions
#include <string>      // Include the string library for using string objects
using namespace std;   // Use the standard namespace

// Constructor Definitions

// Default constructor initializes accBalance to 0.0 and accountType to an empty string
Account::Account() : accBalance(0.0), accountType("") {}

// Parameterized constructor to initialize an Account object with specific values
Account::Account(int accNumber, string firstName, string lastName, string dob, string gender, string address, int phoneNumber, string email, double accBal ,string accountType ) 
            : Customer(accNumber, firstName, lastName, dob,  gender, address, phoneNumber, email) {
    
    // Check if the initial balance is valid (non-negative)
    if(accBalance >= 0) {
        accBalance = accBal; // Set accBalance to the provided balance
    } else {
        cout << "Invalid Balance"; // Print an error message for invalid balance
        accBalance = 0.0; // Set accBalance to 0.0 if invalid
    }
    
    this->accountType = accountType; // Set the account type
}

// Method to debit an amount from the account balance
bool Account::debit(double amount) {
    // Check if sufficient balance is available for the debit operation
    if(amount < accBalance) {
        accBalance -= amount; // Deduct the amount from accBalance
        return true; // Return true indicating successful debit
    } else {
        cout << "Insufficient Balance" << endl; // Print an error message if balance is insufficient
        return false; // Return false indicating failed debit
    }
}

// Method to credit an amount to the account balance
void Account::credit(double amount) {
    accBalance += amount; // Increase accBalance by the amount
}

// Method to get the current account balance
double Account::getBalance() const {
    return accBalance; // Return the current balance
}

// Method to get the account type
string Account::getAccountType() const {
    return accountType; // Return the account type
}

// Method to set a new account balance
void Account::setAccountBalance(int accBal) {
    accBalance = accBal; // Update accBalance to the new value
}

// Method to save a transaction to a file
void Account::saveTransaction(string transactionType, double amount) const {
    ofstream file("transactions.txt", ios::app); // Open the transactions file in append mode
    if (file.is_open()) { // Check if the file is open
        time_t now = time(0); // Get the current time
        char* dt = ctime(&now); // Convert the time to a readable format
        // Write the transaction details to the file
        file << getAccountNumber() << "," << transactionType << "," << amount << "," << dt;
        file.close(); // Close the file
    } else {
        cout << "Unable to open file for writing transaction." << endl; // Print error if file can't be opened
    }
}

// Method to save account details to a file
void Account::saveToFile() const {
    ofstream file("accounts.txt", ios::app); // Open the accounts file in append mode
    if (file.is_open()) { // Check if the file is open
        // Write account details to the file
        file << getAccountNumber() << "," << getFirstName() << "," << getLastName() << "," 
             << getDate() << "," << getGender() << "," << getAddress() << "," << getPhone() << "," 
             << getEmail() << "," << accBalance << "," << accountType << endl;
        file.close(); // Close the file
    } else {
        cout << "Unable to open file for writing account." << endl; // Print error if file can't be opened
    }
}

// Static method to load an Account object from a file using the account number
Account* Account::loadFromFile(int accNumber) {
    ifstream file("accounts.txt"); // Open the accounts file for reading
    if (file.is_open()) { // Check if the file is open
        string line; // Variable to hold each line read from the file
        while (getline(file, line)) { // Read the file line by line
            int acc; // Variable to hold account number
            string fname, lname, dob, gen, addr, email, accType; // Variables for customer details
            int phone; // Variable for phone number
            double bal; // Variable for account balance
            
            // Parse the line into corresponding variables
            sscanf(line.c_str(), "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%lf,%s", 
                   &acc, fname.data(), lname.data(), dob.data(), gen.data(), addr.data(), 
                   &phone, email.data(), &bal, accType.data());
            // Check if the read account number matches the requested one
            if (acc == accNumber) {
                file.close(); // Close the file
                // Create and return a new Account object with the loaded data
                return new Account(acc, fname, lname, dob, gen, addr, phone, email, bal, accType);
            }
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file for reading account." << endl; // Print error if file can't be opened
    }
    return nullptr; // Return nullptr if account not found
}