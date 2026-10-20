#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> p = {3, "three"};
    cout << p.first << ' ' << p.second << '\n';

    vector<pair<int, int>> v = {{3, 9}, {1, 7}, {2, 8}, {1, 5}};

    // Default: sort by first, then by second
    sort(v.begin(), v.end());
    for (auto [a, b] : v) cout << a << ',' << b << ' ';   // 1,5 1,7 2,8 3,9
    cout << '\n';

    // Custom: sort by second, descending
    sort(v.begin(), v.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
        return x.second > y.second;
    });
    for (auto [a, b] : v) cout << a << ',' << b << ' ';   // 3,9 2,8 1,7 1,5
    cout << '\n';
    return 0;
}
