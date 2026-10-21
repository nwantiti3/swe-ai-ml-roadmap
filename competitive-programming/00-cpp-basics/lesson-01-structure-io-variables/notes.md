# Module 00, Lesson 1: Program structure, I/O, and variables

**Goal:** write, compile, and run a small C++ program that reads input and prints output.

## 1. Your first program

```cpp
#include <bits/stdc++.h>   // includes almost the whole standard library
using namespace std;       // lets us write cout instead of std::cout

int main() {
    cout << "Hello, ICPC!" << '\n';
     // note: noticing the difference bwtewwn here and C

    return 0;
}
```

Code: [`examples/01_hello.cpp`](examples/01_hello.cpp)

- `main()` is where every C++ program starts.
- `cout <<` prints. `'\n'` starts a new line.
- Every statement ends with `;`.
- To leave some notes to be read and noticed while coding or revising. type `//` then write your note

### Compile and run

```bash
g++ -std=c++17 -O2 hello.cpp -o hello
./hello
```

## 2. Variables and types

```cpp
int a = 5;            // whole numbers up to about 2 billion
long long b = 1e12;   // big whole numbers, up to about 9 * 10^18
double c = 3.14;      // decimals
char d = 'x';         // one character
string s = "hello";   // text
bool ok = true;       // true or false
```

| Type | Typical use | Approximate limit |
|:--|:--|:--|
| `int` | counters, small values | about ±2.1 · 10^9 |
| `long long` | sums, products, large values | about ±9.2 · 10^18 |
| `double` | decimals | about 15 digits of precision |

> **Contest rule #1:** if a value, or the result of a multiplication, could pass about 2 billion, use `long long`. Overflow is the most common silent bug.

## 3. Reading input and doing math

```cpp
int x, y;
cin >> x >> y;          // reads two numbers separated by spaces or newlines
cout << x + y << '\n'; 
```

Code: [`examples/02_add.cpp`](examples/02_add.cpp)

Operators: `+  -  *  /` and `%` (remainder).

> **Careful:** with integers, `7 / 2` is `3`, because the decimal part is dropped. Use `7.0 / 2` to get `3.5`.

## 4. Overflow in action

Code: [`examples/03_overflow.cpp`](examples/03_overflow.cpp)

`a * b` with two `int` values is computed in `int`. If the real result is too big, it wraps around to a wrong number **before** it is stored anywhere. Storing it in a `long long` afterward does not fix it. Convert one operand first: `(long long)a * b`.

## Key rules
- Every statement ends with `;`.
- `int` is not enough when values or products can pass about 2·10^9. Use `long long`.
- Integer division drops the decimal part.
- Use `'\n'` instead of `endl` for output (faster).
- Compile and run your code before trusting it.

## Summary
- A C++ program starts in `main()`.
- `cin >>` reads, `cout <<` prints.
- Choose the type by the size of the numbers, not by habit.
- Overflow happens silently, so check the limits before coding.

**Next:** Lesson 2, conditions and loops. Practice: [`exercises.md`](exercises.md)
