#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include <string>
using namespace std;

class BankCustomer {
private:
    int id;
    string name;
    double balance;

public:
    // Constructor
    BankCustomer(int id, string name, double balance);

    // Getters
    int getId() const;
    string getName() const;
    double getBalance() const;

    // Operations
    void setBalance(double amount);
    void addBalance(double amount);
    bool withdrawBalance(double amount);

    // Utility
    void printInfo() const;
};

#endif
