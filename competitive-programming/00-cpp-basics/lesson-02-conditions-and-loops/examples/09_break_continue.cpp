#include <bits/stdc++.h>
using namespace std;

int main() {
    // continue: skip the rest of this round. break: leave the loop.
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 1) continue;   // skip odd numbers
        if (i > 8) break;           // stop after 8
        cout << i << ' ';
    }
    cout << '\n';                   // prints: 2 4 6 8
    return 0;
}
