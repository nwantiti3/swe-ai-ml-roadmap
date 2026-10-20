#include <bits/stdc++.h>
using namespace std;

// return type, name, parameters
int square(int x) {
    return x * x;
}

bool isEven(int x) {
    return x % 2 == 0;
}

// Euclid's algorithm for the greatest common divisor
long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// void = returns nothing
void printLine(const string& text) {
    cout << "== " << text << " ==\n";
}

int main() {
    printLine("functions");
    cout << square(7) << '\n';                // 49
    cout << isEven(10) << ' ' << isEven(7) << '\n';   // 1 0
    cout << gcdll(48, 18) << '\n';            // 6
    return 0;
}
