#include <bits/stdc++.h>
using namespace std;

// Same job as 02_io_slow.cpp, with fast I/O and '\n'.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cout << x * 2 << '\n';
    }
    return 0;
}
