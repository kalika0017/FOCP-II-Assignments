#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;
    const int MAX_TICKETS = 100;

public:
    bool BOOK(int userId, int movieId) {
        // Already booked
        if (bookings[movieId].count(userId))
            return false;

        // Sold out
        if (bookings[movieId].size() >= MAX_TICKETS)
            return false;

        bookings[movieId].insert(userId);
        return true;
    }

    bool CANCEL(int userId, int movieId) {
        // Not booked
        if (!bookings[movieId].count(userId))
            return false;

        bookings[movieId].erase(userId);
        return true;
    }

    bool IS_BOOKED(int userId, int movieId) {
        return bookings[movieId].count(userId);
    }

    int AVAILABLE_TICKETS(int movieId) {
        return MAX_TICKETS - bookings[movieId].size();
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    MovieTicket mt;

    while (Q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "BOOK") {
            int X, Y;
            ss >> X >> Y;

            cout << (mt.BOOK(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            ss >> X >> Y;

            cout << (mt.CANCEL(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            ss >> X >> Y;

            cout << (mt.IS_BOOKED(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            ss >> Y;

            cout << mt.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}