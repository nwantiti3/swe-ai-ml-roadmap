#include <bits/stdc++.h>
using namespace std;

// Reads n numbers and prints each one doubled, on its own line.
// SLOW on purpose: default I/O settings and endl (which flushes every time).
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cout << x * 2 << endl;
    }
    return 0;
}
