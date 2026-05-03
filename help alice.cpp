#include <iostream>
using namespace std;

long long f(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R;
    cin >> L >> R;

    long long X = f(R) ^ f(L - 1);

    if (X % 2 == 0) cout << "even";
    else cout << "odd";

    return 0;
}
