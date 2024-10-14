#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Customer.hpp" // Include the Customer class for inheritance
#include <string>      // Include the string library for using string objects
#include <fstream>     // Include the fstream library for file handling

using namespace std;    // Use the standard namespace

// Define the Account class, inheriting from the Customer class
class Account: public Customer {
    private:
        double accBalance;     // Variable to hold the account balance
        string accountType;    // Variable to hold the type of account

    public:
        Account();  // Default constructor
        // Parameterized constructor to initialize an Account object with specific values
        Account(int accNumber, string firstName, string lastName, string dob, string gender, string address, int phoneNumber, string email, double accBal ,string accountType );

        // Method to debit an amount from the account
        bool debit(double amount);
        
        // Method to credit an amount to the account
        void credit(double amount);
        
        // Method to get the current balance of the account
        double getBalance() const;
        
        // Method to get the type of account
        string getAccountType() const;
        
        // Method to set the account balance
        void setAccountBalance(int accBal);

        // Method to save a transaction of a specific type to a file
        void saveTransaction(string transactionType, double amount) const;

        // Method to save account details to a file
        void saveToFile() const;

        // Static method to load an Account object from a file using the account number
        static Account* loadFromFile(int accNumber);
};

#endif // End of the ACCOUNT_HPP header guard