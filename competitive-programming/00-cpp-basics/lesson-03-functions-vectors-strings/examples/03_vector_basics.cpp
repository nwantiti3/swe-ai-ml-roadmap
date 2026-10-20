#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;                   // empty
    v.push_back(10);                 // add to the end
    v.push_back(20);
    v.push_back(30);

    cout << v.size() << '\n';        // 3
    cout << v[0] << ' ' << v.back() << '\n';   // 10 30
    v.pop_back();                    // remove the last element
    cout << v.size() << '\n';        // 2

    vector<int> zeros(5, 0);         // 5 elements, all 0
    vector<int> a = {4, 8, 15};      // list initialization

    // Range-for: read each element
    for (int x : a) cout << x << ' ';
    cout << '\n';

    // Index loop. v.size() is unsigned, so cast to int when comparing with int
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << ' ';
    cout << '\n';

    // The standard way to read n numbers
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "read " << arr.size() << " numbers\n";
    return 0;
}
