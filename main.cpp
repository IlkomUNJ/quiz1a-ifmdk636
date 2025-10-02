#include <iostream>
#include <vector>
#include <algorithm>
#include "bank_customer.h"
#include "buyer.h"
#include "seller.h"
#include <string>


using namespace std;

// Global storage
vector<Buyer> buyers;
vector<Seller> sellers;
int nextBuyerId = 1;
int nextSellerId = 100;
int nextBankId = 1000;

// Fungsi untuk menampilkan semua buyer
void viewAllBuyers() {
    cout << "\n--- All Buyers ---\n";
    if (buyers.empty()) {
        cout << "No buyers registered.\n";
        return;
    }
    for (auto &b : buyers) {
        cout << "Buyer ID: " << b.getId() << ", Name: " << b.getName() << endl;
    }
}

// Fungsi untuk menampilkan semua seller
void viewAllSellers() {
    cout << "\n--- All Sellers ---\n";
    if (sellers.empty()) {
        cout << "No sellers registered.\n";
        return;
    }
    for (auto &s : sellers) {
        cout << "Seller ID: " << s.getId() << ", Name: " << s.getName() << endl;
    }
}

// Fungsi untuk mencari buyer/seller berdasarkan ID atau Nama
void searchUser() {
    cout << "\nSearch by: 1.ID  2.Name\n";
    int opt; cin >> opt;
    if (opt == 1) {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        for (auto &b : buyers) {
            if (b.getId() == id) {
                cout << "[Buyer Found] ID: " << b.getId() << ", Name: " << b.getName() << endl;
                return;
            }
        }
        for (auto &s : sellers) {
            if (s.getId() == id) {
                cout << "[Seller Found] ID: " << s.getId() << ", Name: " << s.getName() << endl;
                return;
            }
        }
    } else {
        string name;
        cout << "Enter Name: ";
        cin >> name;
        for (auto &b : buyers) {
            if (b.getName() == name) {
                cout << "[Buyer Found] ID: " << b.getId() << ", Name: " << b.getName() << endl;
                return;
            }
        }
        for (auto &s : sellers) {
            if (s.getName() == name) {
                cout << "[Seller Found] ID: " << s.getId() << ", Name: " << s.getName() << endl;
                return;
            }
        }
    }
    cout << "User not found!\n";
}

// Fungsi untuk membuat akun baru (Buyer/Seller/Bank)
void createUser() {
    cout << "\nCreate: 1. Buyer  2. Seller\n";
    int choice; cin >> choice;

    if (choice == 1) {
        string name;
        double deposit;
        cout << "Enter Buyer Name: ";
        cin >> name;
        cout << "Phone: ";
        string phone; cin >> phone;
        cout << "Address: ";
        string address; cin >> address;
        cout << "Initial Deposit: ";
        cin >> deposit;

BankCustomer account(nextBankId++, name, deposit);
Buyer newBuyer(nextBuyerId++, name, phone, address, account);
buyers.push_back(newBuyer);


        cout << "Buyer Created Successfully!\n";

    } else if (choice == 2) {
        string name, phone, address;
        cout << "Enter Seller Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);

        if (buyers.empty()) {
            cout << "No buyers available. Create Buyer first!\n";
            return;
        }

        // link sementara ke buyer pertama
        Seller newSeller(buyers[0], nextSellerId++, name, phone, address);
        sellers.push_back(newSeller);

        cout << "Seller Created Successfully!\n";
    }
}


// Fungsi untuk menghapus user
void deleteUser() {
    cout << "Delete: 1. Buyer  2. Seller\n";
    int choice; cin >> choice;
    if (choice == 1) {
        int id;
        cout << "Enter Buyer ID: ";
        cin >> id;
        buyers.erase(remove_if(buyers.begin(), buyers.end(),
            [id](Buyer &b){ return b.getId() == id; }), buyers.end());
        cout << "Buyer Removed!\n";
    } else if (choice == 2) {
        int id;
        cout << "Enter Seller ID: ";
        cin >> id;
        sellers.erase(remove_if(sellers.begin(), sellers.end(),
            [id](Seller &s){ return s.getId() == id; }), sellers.end());
        cout << "Seller Removed!\n";
    }
}

// Fungsi laporan sistem
void systemReport() {
    cout << "\n--- System Report ---\n";
    cout << "Total Buyers: " << buyers.size() << endl;
    cout << "Total Sellers: " << sellers.size() << endl;
    cout << "Total Bank Accounts: " << buyers.size() << endl; 
    // karena setiap buyer pasti punya 1 BankCustomer
}


// Tambahkan di atas rootMenu()
void createBankAccount();
void seekUser();
void viewAllBuyerDetails();
void viewAllSellerDetails();


// Root (Admin) Menu
void rootMenu() {
    int choice;
    do {
        cout << "\n--- ROOT MENU ---\n";
        cout << "1. View All Buyers\n";
        cout << "2. View All Sellers\n";
        cout << "3. Search User (ID / Name)\n";
        cout << "4. Create New User (Buyer/Seller)\n";
        cout << "5. Delete User\n";
        cout << "6. View All Seller Details\n";
        cout << "7. View All Buyer Details\n"; 
        cout << "8. Seek User (Name/ID/Phone/Address)\n";
        cout << "9. Create Bank Account\n";   
        cout << "10. System Report\n";  
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: viewAllBuyers(); break;
            case 2: viewAllSellers(); break;
            case 3: searchUser(); break;
            case 4: createUser(); break;
            case 5: deleteUser(); break;
            case 6: viewAllSellerDetails; break;
            case 7: viewAllBuyerDetails(); break;      // ✅
            case 8: seekUser(); break;               // ✅
            case 9: createBankAccount; break;    // ✅
            case 10: systemReport(); break;  // ✅
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid!\n";
        }
    } while(choice != 0);
}

// 1. Create Bank Account
void createBankAccount() {
    string name, phone, address;
    double deposit;

    cout << "\n=== Create Bank Account ===\n";
    cout << "Customer Name: ";
    cin >> name;
    cout << "Phone Number: ";
    cin >> phone;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Initial Deposit: ";
    cin >> deposit;

    BankCustomer account(nextBankId++, name, deposit);
    Buyer newBuyer(nextBuyerId++, name, phone, address, account);
    buyers.push_back(newBuyer);

    cout << "Bank Account Created Successfully for " << name << "!\n";
}

// 2. Search Buyer or Seller
void seekUser() {
    cout << "\nSearch by: 1.ID  2.Name  3.Phone  4.Address\n";
    int opt; cin >> opt;
    string keyword;
    int id;

    if (opt == 1) {
        cout << "Enter ID: "; cin >> id;
        for (auto &b : buyers) {
            if (b.getId() == id) {
                cout << "[Buyer Found] " << b.getDetails() << endl;
                return;
            }
        }
        for (auto &s : sellers) {
            if (s.getId() == id) {
                cout << "[Seller Found] " << s.getDetails() << endl;
                return;
            }
        }
    } else {
        cout << "Enter keyword: ";
        cin.ignore();
        getline(cin, keyword);

        for (auto &b : buyers) {
            if (b.getName() == keyword || b.getPhone() == keyword || b.getAddress() == keyword) {
                cout << "[Buyer Found] " << b.getDetails() << endl;
                return;
            }
        }
        for (auto &s : sellers) {
            if (s.getName() == keyword || s.getPhone() == keyword || s.getAddress() == keyword) {
                cout << "[Seller Found] " << s.getDetails() << endl;
                return;
            }
        }
    }
    cout << "User not found!\n";
}

// 3. View All Buyer Details
void viewAllBuyerDetails() {
    cout << "\n=== Buyer Details ===\n";
    if (buyers.empty()) {
        cout << "No buyers registered.\n";
        return;
    }
    for (auto &b : buyers) {
        cout << b.getDetails() << "\n";
    }
}

// 4. View All Seller Details
void viewAllSellerDetails() {
    cout << "\n=== Seller Details ===\n";
    if (sellers.empty()) {
        cout << "No sellers registered.\n";
        return;
    }
    for (auto &s : sellers) {
        cout << s.getDetails() << "\n";
    }
}


int main() {
    string user, pass;
    cout << "Root Login\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (user == "root" && pass == "root") {
        cout << "Login Success!\n";
        rootMenu();
    } else {
        cout << "Invalid credentials!\n";
    }

    return 0;
}
