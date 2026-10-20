#include <bits/stdc++.h>
using namespace std;

void swapByValue(int a, int b) {     // works on COPIES, the caller sees no change
    int t = a; a = b; b = t;
}

void swapByRef(int& a, int& b) {     // & = work on the originals
    int t = a; a = b; b = t;
}

// const reference: no copy of a big vector, and we promise not to change it
long long sumAll(const vector<int>& v) {
    long long s = 0;
    for (int x : v) s += x;
    return s;
}

int main() {
    int x = 1, y = 2;
    swapByValue(x, y);
    cout << x << ' ' << y << '\n';   // 1 2 (unchanged)
    swapByRef(x, y);
    cout << x << ' ' << y << '\n';   // 2 1 (swapped)

    vector<int> v = {1, 2, 3, 4};
    cout << sumAll(v) << '\n';       // 10
    return 0;
}
