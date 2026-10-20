#include <bits/stdc++.h>
using namespace std;

int main() {
    int score;
    cin >> score;
    // else-if chain: the first true condition wins, the rest are skipped
    if (score >= 90) cout << "A\n";
    else if (score >= 80) cout << "B\n";
    else if (score >= 70) cout << "C\n";
    else if (score >= 60) cout << "D\n";
    else cout << "F\n";
    return 0;
}
