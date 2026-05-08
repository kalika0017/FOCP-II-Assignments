#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

class Bank {
private:
    map<string, int> accounts;

public:

    // CREATE X Y
    bool create(string id, int amount) {
        if (accounts.find(id) == accounts.end()) {
            accounts[id] = amount;
            return true;
        } else {
            accounts[id] += amount;
            return false;
        }
    }

    // DEBIT X Y
    bool debit(string id, int amount) {
        if (accounts.find(id) == accounts.end() || accounts[id] < amount) {
            return false;
        }

        accounts[id] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(string id, int amount) {
        if (accounts.find(id) == accounts.end()) {
            return false;
        }

        accounts[id] += amount;
        return true;
    }

    // BALANCE X
    int balance(string id) {
        if (accounts.find(id) == accounts.end()) {
            return -1;
        }

        return accounts[id];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    for (int i = 0; i < Q; i++) {
        string query;
        getline(cin, query);

        stringstream ss(query);

        string operation, id;
        int amount;

        ss >> operation;

        if (operation == "CREATE") {
            ss >> id >> amount;
            cout << (bank.create(id, amount) ? "true" : "false") << endl;
        }

        else if (operation == "DEBIT") {
            ss >> id >> amount;
            cout << (bank.debit(id, amount) ? "true" : "false") << endl;
        }

        else if (operation == "CREDIT") {
            ss >> id >> amount;
            cout << (bank.credit(id, amount) ? "true" : "false") << endl;
        }

        else if (operation == "BALANCE") {
            ss >> id;
            cout << bank.balance(id) << endl;
        }
    }

    return 0;
}