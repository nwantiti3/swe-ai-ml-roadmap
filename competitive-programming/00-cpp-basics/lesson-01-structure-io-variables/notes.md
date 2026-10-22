# Module 00, Lesson 1: Program structure, I/O, and variables

**Goal:** write, compile, and run a small C++ program that reads input and prints output.

## 1. Your first program

```cpp
#include <bits/stdc++.h>   // includes almost the whole standard library
using namespace std;       // lets us write cout instead of std::cout

int main() {
    cout << "Hello, ICPC!" << '\n';
     // note: noticing the difference between here and C

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
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1000000000, b = 1000000000;
    long long wrong = (long long)(a * b);   // a * b is computed as int first, so it overflows
    long long right = (long long)a * b;     // convert one operand first, so the math is done in long long
    cout << "wrong: " << wrong << '\n';
    cout << "right: " << right << '\n';
    return 0;
}
``` 

Code: [`examples/03_overflow.cpp`](examples/03_overflow.cpp)

`a * b` with two `int` values is computed in `int`. If the real result is too big, it wraps around to a wrong number **before** it is stored anywhere. Storing it in a `long long` afterward does not fix it. Convert one operand first: `(long long)a * b`.

TO make all is clarified, here a detailed explanation for code 4

```cpp
long long wrong = (long long)(a * b);   // WRONG
long long right = (long long)a * b;     // RIGHT
```

In the second line, the parentheses are around `long long` only, not around `a*b`.

## Why the first one is wrong

C++ always evaluates the **inside of the parentheses first**:

```
(long long)(a * b)
            ^^^^^
step 1: a * b is calculated. Both are int, so the math is done in int.
        The real answer (10^18) doesn't fit, so it wraps around to -1486618624.
step 2: (long long) converts that already-broken number to long long.
```

The cast arrives too late: you are converting a wrong number into a bigger box. The box is bigger, but the number is still -1486618624.

An analogy: a calculator with a 10-digit display shows garbage after an overflow. Writing the garbage on a bigger sheet of paper doesn't fix it.

## Why the second one is right

```
(long long)a * b
```

A cast applies only to the thing right after it, so this means `((long long)a) * b`.

```
step 1: (long long)a   turns a into a long long.
step 2: long long * int. C++ promotes b to long long as well,
        so the multiplication is done in long long.
        Result: 1000000000000000000. Correct.
```

You convert **before** the multiplication, so the multiplication itself has room.

## Your second line

```cpp
long long right = long long (a*b);
```

This has two problems:

1. It **doesn't compile**. In C++, the function-style form `type(value)` works only with a one-word type name, and `long long` has two words. You would get an error like "expected primary-expression before 'long'".
2. If you fix the syntax (for example, `ll(a*b)`), it is the same as the wrong line, because `a*b` is still calculated first, in `int`.

## All the variants

| Code | Multiplication done in | Result |
|:--|:--|:-:|
| `(long long)(a * b)` | `int` | ❌ wrong |
| `long long x = a * b;` | `int` | ❌ wrong |
| `(long long)a * b` | `long long` | ✅ |
| `a * (long long)b` | `long long` | ✅ |
| `1LL * a * b` | `long long` | ✅ |
| `static_cast<long long>(a) * b` | `long long` | ✅ |

Rule: **convert one of the numbers before the `*`, not the result after it.**

## The best habit

Avoid the cast problem by declaring the variables as `long long` in the first place:

```cpp
long long a = 1000000000, b = 1000000000;
cout << a * b << '\n';    // correct, no cast needed
```

Here is your program with the fix:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1000000000, b = 1000000000;
    long long wrong = (long long)(a * b);   // multiplies in int first
    long long right = (long long)a * b;     // converts a first
    cout << "wrong: " << wrong << '\n';     // -1486618624
    cout << "right: " << right << '\n';     // 1000000000000000000
    return 0;
}
```

## Quick check

What does each line print, if `a = 100000` and `b = 100000` (both `int`)?

```cpp
cout << a * b << '\n';
cout << (long long)(a * b) << '\n';
cout << (long long)a * b << '\n';
cout << 1LL * a * b << '\n';
```


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
