#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // n % 2 is 0 for even numbers. For negative odd numbers it is -1, not 1,
    // so always test "== 0" instead of "== 1".
    if (n % 2 == 0) {
        cout << "even\n";
    } else {
        cout << "odd\n";
    }
    return 0;
}
