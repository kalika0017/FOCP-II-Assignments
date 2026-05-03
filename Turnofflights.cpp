#include <iostream>
#include <string>
using namespace std;

bool canTurnOff(string bulbs, int n, int k, int l) {
    int operations = 0;

    for (int i = 0; i < n; i++) {
        if (bulbs[i] == '1') {
            operations++;
            i += l - 1;  
        }
    }

    return operations <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1;
    int right = n;
    int answer = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            answer = mid;
            right = mid - 1;  
        } 
        else {
            left = mid + 1;   
        }
    }

    cout << answer;

    return 0;
}
