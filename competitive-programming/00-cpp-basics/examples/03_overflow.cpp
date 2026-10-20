#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1000000000, b = 1000000000;
    long long wrong = (long long)(a * b);   // a * b is computed as int first, so it overflows
    long long right = (long long)a * b;     // convert one operand first, so the math is done in long long
    cout << "wrong: " << wrong << '\n';
    cout << "right: " << right << '\n';
    return 0;
}
