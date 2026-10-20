#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;                  // number of test cases
    while (t--) {              // runs exactly t times
        int a, b;
        cin >> a >> b;
        cout << (a % b == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
