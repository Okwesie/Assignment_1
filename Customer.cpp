#include "Customer.hpp" // Include the header file for the Customer class
#include <iostream>     // Include the iostream library for input and output

// Default Constructor
Customer::Customer() 
    : accNumber(0), firstName(""), lastName(""), dateOfBirth(""), 
      gender(""), address(""), phoneNumber(0), email("") {}

// Parameterized Constructor
Customer::Customer(int accNumber, string firstName, string lastName, string dob, string gender, string address, int phoneNumber, string email)
    : accNumber(accNumber), firstName(firstName), lastName(lastName), 
      dateOfBirth(dob), gender(gender), address(address), 
      phoneNumber(phoneNumber), email(email) {}

// Method to save customer details to a file
void Customer::saveToFile() const {
    ofstream file("customers.txt", ios::app); // Open the file in append mode
    if (file.is_open()) {
        // Write customer details to the file in CSV format
        file << accNumber << "," << firstName << "," << lastName << "," 
             << dateOfBirth << "," << gender << "," << address << "," 
             << phoneNumber << "," << email << endl;
        file.close(); // Close the file after writing
    } else {
        cout << "Unable to open file for writing." << endl; // Error message if file can't be opened
    }
}

// Method to load customer details from a file based on account number
Customer* Customer::loadFromFile(int accNumber) {
    ifstream file("customers.txt"); // Open the file for reading
    if (file.is_open()) {
        string line;
        // Read each line from the file
        while (getline(file, line)) {
            int acc;
            string fname, lname, dob, gen, addr, email;
            int phone;
            // Parse the line into variables
            sscanf(line.c_str(), "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d,%s", 
                   &acc, fname.data(), lname.data(), dob.data(), 
                   gen.data(), addr.data(), &phone, email.data());
            // Check if the account number matches
            if (acc == accNumber) {
                file.close(); // Close the file before returning
                // Return a new Customer object with the loaded details
                return new Customer(acc, fname, lname, dob, gen, addr, phone, email);
            }
        }
        file.close(); // Close the file after reading all lines
    } else {
        cout << "Unable to open file for reading." << endl; // Error message if file can't be opened
    }
    return nullptr; // Return nullptr if account number not found
}

// Setters for customer details
void Customer::setFirstName(string newFirstName) { firstName = newFirstName; }
void Customer::setLastName(string newLastName) { lastName = newLastName; }
void Customer::setDateOfBirth(string dob) { dateOfBirth = dob; }
void Customer::setAddress(string newAddress) { address = newAddress; }
void Customer::setPhone(int newPhone) { phoneNumber = newPhone; }
void Customer::setEmail(string newEmail) { email = newEmail; }

// Getters for customer details
int Customer::getAccountNumber() const { return accNumber; }
string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }
string Customer::getDate() const { return dateOfBirth; }
string Customer::getGender() const { return gender; }
string Customer::getAddress() const { return address; }
int Customer::getPhone() const { return phoneNumber; }
string Customer::getEmail() const { return email; }