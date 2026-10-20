#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int first;
    cin >> first;
    int mx = first, mn = first;        // start from a real value, never from 0
    for (int i = 1; i < n; i++) {      // n - 1 numbers remain
        int x;
        cin >> x;
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }
    cout << mx << ' ' << mn << '\n';
    return 0;
}
