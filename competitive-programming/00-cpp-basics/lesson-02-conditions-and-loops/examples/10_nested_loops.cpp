#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Outer loop = rows, inner loop = columns. Total work: about n * n / 2.
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= row; col++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
