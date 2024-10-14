#ifndef CHECKING_ACCOUNT_HPP // Header guard to prevent multiple inclusions
#define CHECKING_ACCOUNT_HPP

#include "Account.hpp" // Include the Account class header

// Class definition for CheckingAccount, inheriting from Account
class CheckingAccount : public Account
{
    private:
        double feePerTransaction; // Transaction fee for each transaction
        double initialBalance;     // Initial balance of the account

    public:
        // Default constructor
        CheckingAccount();
        
        // Parameterized constructor to initialize a CheckingAccount with account details
        CheckingAccount(int accNumber, string firstName, string lastName, string dob, string gender, string address, int phoneNumber, string email, int accNo, double accBal, string accountType, double feePerTransaction);
        
        // Method to credit an amount to the account, deducting the transaction fee
        void credit(double amount);
        
        // Method to debit an amount from the account, deducting the transaction fee if successful
        void debit(double amount);
};

#endif // End of header guard