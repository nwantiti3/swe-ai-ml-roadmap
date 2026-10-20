#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;                 // long long: the sum can pass 2 * 10^9
    for (int i = 1; i <= n; i++) {     // i = 1, 2, ..., n
        sum += i;
    }
    cout << sum << '\n';
    return 0;
}
