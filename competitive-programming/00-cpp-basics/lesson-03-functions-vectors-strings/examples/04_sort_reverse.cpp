#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 7};

    sort(v.begin(), v.end());                          // ascending
    for (int x : v) cout << x << ' ';                  // 1 2 5 7 9
    cout << '\n';

    sort(v.begin(), v.end(), greater<int>());          // descending
    for (int x : v) cout << x << ' ';                  // 9 7 5 2 1
    cout << '\n';

    reverse(v.begin(), v.end());                       // reverse the order
    for (int x : v) cout << x << ' ';                  // 1 2 5 7 9
    cout << '\n';

    // Custom order with a lambda: sort by distance from 5
    sort(v.begin(), v.end(), [](int a, int b) {
        return abs(a - 5) < abs(b - 5);
    });
    for (int x : v) cout << x << ' ';
    cout << '\n';

    cout << *min_element(v.begin(), v.end()) << ' '    // 1
         << *max_element(v.begin(), v.end()) << '\n';  // 9

    // Sum of a vector. Note 0LL: the sum is long long
    long long total = accumulate(v.begin(), v.end(), 0LL);
    cout << total << '\n';                             // 24
    return 0;
}
