#include "bank_customer.h"
#include <iostream>
using namespace std;

// Constructor
BankCustomer::BankCustomer(int id, string name, double balance) {
    this->id = id;
    this->name = name;
    this->balance = balance;
}

// Getters
string BankCustomer::getName() const {
    return this->name;
}

int BankCustomer::getId() const {
    return this->id;
}

double BankCustomer::getBalance() const {
    return this->balance;
}

// Setters / Operations
void BankCustomer::setBalance(double amount) {
    this->balance = amount;
}

void BankCustomer::addBalance(double amount) {
    this->balance += amount;
}

bool BankCustomer::withdrawBalance(double amount) {
    if (amount > this->balance) {
        cout << "Rejected: Insufficient funds!" << endl;
        return false;
    }
    this->balance -= amount;
    return true;
}

// Utility
void BankCustomer::printInfo() const {
    cout << "Customer Name: " << this->name << endl;
    cout << "Customer ID: " << this->id << endl;
    cout << "Balance: $" << this->balance << endl;
}

