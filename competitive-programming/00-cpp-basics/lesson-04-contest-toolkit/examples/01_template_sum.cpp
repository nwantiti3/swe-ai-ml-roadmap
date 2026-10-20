#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

// Problem: read n numbers (each up to 10^9) and print their sum.
void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);   // do not keep C and C++ I/O in sync (faster)
    cin.tie(nullptr);              // do not flush cout before every cin (faster)

    int t = 1;
    // cin >> t;                   // uncomment for multiple test cases
    while (t--) solve();
    return 0;
}
