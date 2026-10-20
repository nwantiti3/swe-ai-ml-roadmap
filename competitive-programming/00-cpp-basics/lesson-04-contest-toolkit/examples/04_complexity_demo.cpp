#include <bits/stdc++.h>
using namespace std;

// Compare O(n) and O(n^2) on the same n. Compile with -O2 and run it.
int main() {
    const int n = 50000;
    using clk = chrono::steady_clock;

    auto t0 = clk::now();
    long long a = 0;
    for (int i = 0; i < n; i++) a += i ^ 7;                 // n steps
    auto t1 = clk::now();

    long long b = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b += (i ^ j);                                    // n * n steps
    auto t2 = clk::now();

    auto ms = [](auto d) { return chrono::duration_cast<chrono::milliseconds>(d).count(); };
    cout << "O(n):   " << ms(t1 - t0) << " ms (result " << a << ")\n";
    cout << "O(n^2): " << ms(t2 - t1) << " ms (result " << b << ")\n";
    return 0;
}
