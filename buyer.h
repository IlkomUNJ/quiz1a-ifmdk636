#ifndef BUYER_H
#define BUYER_H

#include "bank_customer.h"
#include <string>
using namespace std;

class Buyer {
private:
    int id;
    string name;
    string phone;
    string address;
    BankCustomer account;  // relasi ke BankCustomer

public:
    // Constructor
    Buyer(int id, string name, string phone, string address, BankCustomer account)
        : id(id), name(name), phone(phone), address(address), account(account) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }
    BankCustomer getAccount() const { return account; }

    // Utility
    string getDetails() const {
        return "ID: " + to_string(id) +
               ", Name: " + name +
               ", Phone: " + phone +
               ", Address: " + address +
               ", Bank Balance: " + to_string(account.getBalance());
    }
};

#endif
