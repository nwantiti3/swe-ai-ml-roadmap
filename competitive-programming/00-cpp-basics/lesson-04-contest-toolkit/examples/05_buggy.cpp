#include <bits/stdc++.h>
using namespace std;

// This program has 3 bugs. Find them using the debug flags from the notes,
// BEFORE you look at the answers in exercises.md.
// Expected: for input "3 / 2000000000 2000000000 5" print "4000000005 2000000000"
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n; i++) cin >> a[i];

    int sum = 0;
    int best;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        best = max(best, a[i]);
    }
    cout << sum << ' ' << best << '\n';
    return 0;
}
