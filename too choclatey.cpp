#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        set<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }

        vector<int> v(s.begin(), s.end());
        sort(v.rbegin(), v.rend());

        long long alex = 0, bob = 0;

        for (int i = 0; i < (int)v.size(); i++) {
            if (i % 2 == 0) alex += v[i];
            else bob += v[i];
        }

        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}
