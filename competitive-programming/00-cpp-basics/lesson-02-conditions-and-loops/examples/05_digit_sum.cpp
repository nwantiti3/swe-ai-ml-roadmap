#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;   // last digit
        n /= 10;         // remove the last digit
    }
    cout << sum << '\n';
    return 0;
}
