#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello";
    cout << s.size() << '\n';               // 5 (same as s.length())
    cout << s[0] << ' ' << s.back() << '\n';   // h o
    s += " world";                          // concatenation
    cout << s << '\n';
    cout << s.substr(0, 5) << '\n';         // hello (start index, length)

    string r = s;
    reverse(r.begin(), r.end());            // reverse works on strings too
    cout << r << '\n';

    // Characters are numbers
    char c = 'a';
    cout << (char)(c + 1) << '\n';          // b
    cout << ('7' - '0') << '\n';            // 7  (digit character to number)

    cout << to_string(123) + "!" << '\n';   // number to string
    cout << stoi("456") + 1 << '\n';        // string to number: 457

    // Reading a whole line (with spaces)
    string line;
    getline(cin, line);
    int vowels = 0;
    for (char ch : line) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowels++;
    }
    cout << "vowels: " << vowels << '\n';
    return 0;
}
