#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    bool prime = (n >= 2);
    // A composite number has a divisor <= sqrt(n), so checking i * i <= n is enough.
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime = false;
            break;               // stop as soon as we know
        }
    }
    cout << (prime ? "prime" : "not prime") << '\n';
    return 0;
}
