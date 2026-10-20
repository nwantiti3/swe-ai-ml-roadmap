# Module 00, Lesson 3: Functions, vectors, and strings

**Goal:** organize code into functions, store many values in a `vector`, and work with text using `string`.

**Prerequisite:** [Lesson 2](../lesson-02-conditions-and-loops/notes.md)

---

## 1. Functions

A function is a named piece of code you can reuse.

```cpp
int square(int x) {          // return type, name, parameters
    return x * x;
}
```

Call it: `square(7)` gives `49`.

- A function that returns nothing has the type `void`.
- Define a function **before** the place that uses it (above `main`).
- Variables declared inside a function exist only there. This is called **scope**.

Example with Euclid's algorithm for the greatest common divisor:

```cpp
long long gcdll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

Code: [`examples/01_functions.cpp`](examples/01_functions.cpp)

### Pass by value, by reference, by const reference

| Style | Syntax | Meaning |
|:--|:--|:--|
| by value | `int a` | the function gets a **copy**; changes are lost |
| by reference | `int& a` | the function changes the **original** |
| by const reference | `const vector<int>& v` | no copy, and the function promises not to change it |

Pass big objects like vectors and strings by `const&`. Copying a vector of 10^6 elements into every call is slow.

Code: [`examples/02_pass_by_ref.cpp`](examples/02_pass_by_ref.cpp)

---

## 2. Arrays and `vector`

A `vector` is a resizable list. It is the array you will use in almost every solution.

```cpp
vector<int> v;               // empty
v.push_back(10);             // add to the end
v.size();                    // number of elements
v[0];                        // first element (index starts at 0)
v.back();                    // last element
v.pop_back();                // remove the last element
vector<int> z(5, 0);         // 5 zeros
vector<int> a = {4, 8, 15};  // fixed starting values
```

### Reading `n` numbers (the standard pattern)

```cpp
int n; cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];
```

### Looping

```cpp
for (int x : a) cout << x << ' ';                  // range-for: each element
for (int i = 0; i < (int)a.size(); i++) ...        // index loop
```

> **Trap: `size()` is unsigned.** `v.size() - 1` on an empty vector wraps to a huge number, and comparing `i < v.size()` mixes signed and unsigned. Cast: `(int)v.size()`.

> **Trap: out-of-bounds.** Valid indexes are `0` to `size() - 1`. `a[n]` is a bug and may silently corrupt memory. A debug build with `-D_GLIBCXX_DEBUG` catches it.

Code: [`examples/03_vector_basics.cpp`](examples/03_vector_basics.cpp)

### Sorting and other useful functions

```cpp
sort(v.begin(), v.end());                       // ascending
sort(v.begin(), v.end(), greater<int>());       // descending
reverse(v.begin(), v.end());
*min_element(v.begin(), v.end());               // smallest (note the *)
*max_element(v.begin(), v.end());               // largest
accumulate(v.begin(), v.end(), 0LL);            // sum as long long
```

`sort` takes `O(n log n)` time, fast enough for 10^6 elements.

**Custom order with a lambda** (a tiny unnamed function):

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return abs(a - 5) < abs(b - 5);       // true means "a goes before b"
});
```

Code: [`examples/04_sort_reverse.cpp`](examples/04_sort_reverse.cpp)

> `accumulate(..., 0)` with a plain `0` sums in `int` and can overflow. Use `0LL`.

### 2D vectors (grids)

```cpp
vector<vector<int>> grid(r, vector<int>(c));   // r rows, c columns
grid[i][j] = 5;                                // row i, column j
```

Code: [`examples/05_grid_2d.cpp`](examples/05_grid_2d.cpp)

---

## 3. Strings

```cpp
string s = "hello";
s.size();                // 5
s[0];                    // 'h'
s += " world";           // concatenate
s.substr(0, 5);          // "hello" (start index, length)
reverse(s.begin(), s.end());
```

- Characters are small numbers: `'a' + 1` is `'b'`, and `'7' - '0'` is the number `7`.
- `to_string(123)` turns a number into text. `stoi("456")` turns text into a number.
- `cin >> s` reads one word (stops at a space). `getline(cin, line)` reads a whole line.

> **Trap: `getline` after `cin >>`.** After `cin >> n`, the newline stays in the buffer, so the next `getline` reads an empty line. Fix: call `cin.ignore();` before `getline`.

Code: [`examples/06_strings.cpp`](examples/06_strings.cpp)

---

## 4. Pairs

```cpp
pair<int, string> p = {3, "three"};
p.first; p.second;
vector<pair<int,int>> v;
sort(v.begin(), v.end());       // sorts by first, then by second
```

Pairs are handy for "value and its index", "score and name", or points `(x, y)`.

Code: [`examples/07_pairs.cpp`](examples/07_pairs.cpp)

---

## Key rules
- Pass vectors and strings by `const&` (or `&` if you must change them).
- Indexes start at 0 and end at `size() - 1`.
- Cast `v.size()` to `int` when comparing or subtracting.
- Use `accumulate(..., 0LL)` for sums.
- Use `getline` for lines, and `cin.ignore()` if it follows `cin >>`.
- `sort` is `O(n log n)`. Use it freely.

## Summary
- Functions make code reusable and testable.
- `vector` is your default container, and `sort` and friends come with it.
- Strings behave like vectors of characters.

## Quick check

1. After `void f(int a) { a = 5; }` and `f(x);`, does `x` change?
2. What is the last valid index of a vector with 8 elements?
3. What does `cout << ('9' - '0' + 1);` print?
4. Why `0LL` in `accumulate`?

<details>
<summary>Answers</summary>

1. No. It was passed by value (a copy).
2. 7.
3. `10`.
4. So the sum is computed in `long long`. With plain `0` it is `int` and can overflow.

</details>

**Next:** [Lesson 4: The contest toolkit](../lesson-04-contest-toolkit/notes.md). Practice now: [`exercises.md`](exercises.md)
