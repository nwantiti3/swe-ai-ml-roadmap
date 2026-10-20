#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

// Fast modular exponentiation: b^e mod m
ll power(ll b, ll e, ll m = MOD) {
    ll r = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

void solve() {
    // problem logic here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;   // uncomment when the problem has multiple test cases
    while (t--) solve();
    return 0;
}
