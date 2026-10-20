#include <bits/stdc++.h>
using namespace std;

// Maximum subarray sum, brute force O(n^2). Slow but obviously correct.
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    long long best = a[0];
    for (int i = 0; i < n; i++) {
        long long s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            best = max(best, s);
        }
    }
    cout << best << '\n';
    return 0;
}
