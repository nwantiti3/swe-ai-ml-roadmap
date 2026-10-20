#include <bits/stdc++.h>
using namespace std;

// Random small test generator. Usage: ./gen SEED
int main(int argc, char** argv) {
    int seed = argc > 1 ? atoi(argv[1]) : 1;
    mt19937 rng(seed);
    int n = rng() % 8 + 1;                  // 1..8 numbers
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << (int)(rng() % 21) - 10 << ' ';   // values -10..10
    }
    cout << '\n';
    return 0;
}
