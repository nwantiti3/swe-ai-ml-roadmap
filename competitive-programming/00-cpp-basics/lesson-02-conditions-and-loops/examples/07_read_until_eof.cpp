#include <bits/stdc++.h>
using namespace std;

int main() {
    // Use this when the input has no count: read until the input ends.
    long long x, sum = 0;
    int count = 0;
    while (cin >> x) {
        sum += x;
        count++;
    }
    cout << "count = " << count << ", sum = " << sum << '\n';
    return 0;
}
