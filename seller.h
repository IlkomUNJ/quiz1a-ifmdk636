#ifndef SELLER_H
#define SELLER_H

#include "buyer.h"
#include <string>
using namespace std;

class Seller {
private:
    int id;
    string name;
    string phone;
    string address;
    Buyer linkedBuyer; // relasi ke buyer

public:
    // Constructor
    Seller(Buyer buyer, int id, string name, string phone, string address)
        : linkedBuyer(buyer), id(id), name(name), phone(phone), address(address) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }
    Buyer getLinkedBuyer() const { return linkedBuyer; }

    // Utility
    string getDetails() const {
        return "SellerID: " + to_string(id) +
               ", Name: " + name +
               ", Phone: " + phone +
               ", Address: " + address +
               ", Linked Buyer: " + linkedBuyer.getName();
    }
};

#endif
