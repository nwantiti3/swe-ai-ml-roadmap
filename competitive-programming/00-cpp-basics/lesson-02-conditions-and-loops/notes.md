# Module 00, Lesson 2: Conditions and loops

**Goal:** make a program decide (`if`) and repeat (`for`, `while`). Almost every contest problem is built from these two ideas.

**Prerequisite:** [Lesson 1](../lesson-01-structure-io-variables/notes.md)

---

## 1. Conditions: `if`, `else if`, `else`

```cpp
if (n % 2 == 0) {
    cout << "even\n";
} else {
    cout << "odd\n";
}
```

Code: [`examples/01_even_odd.cpp`](examples/01_even_odd.cpp)

A chain of conditions is checked from top to bottom. **The first true one runs, and the rest are skipped.**

```cpp
if (score >= 90) cout << "A\n";
else if (score >= 80) cout << "B\n";
else cout << "F\n";
```

Code: [`examples/02_grade.cpp`](examples/02_grade.cpp)

### Comparison operators

| Operator | Meaning |
|:-:|:--|
| `==` | equal to |
| `!=` | not equal to |
| `<` `<=` | less than, less than or equal |
| `>` `>=` | greater than, greater than or equal |

### Logical operators

| Operator | Meaning | Example |
|:-:|:--|:--|
| `&&` | and (both must be true) | `x > 0 && x < 10` |
| `\|\|` | or (at least one true) | `x < 0 \|\| x > 100` |
| `!` | not | `!ok` |

### Two classic traps

> **`=` is not `==`.** `if (x = 5)` assigns 5 to `x` and is always true. Use `==` to compare.

> **Negative remainders.** In C++, `-3 % 2` is `-1`, not `1`. Test evenness with `n % 2 == 0`, never `n % 2 == 1`.

### The ternary shortcut

```cpp
cout << (a % b == 0 ? "YES" : "NO") << '\n';   // condition ? valueIfTrue : valueIfFalse
```

Good for short choices. Use a normal `if` when the logic gets longer.

---

## 2. Loops

### `for`: when you know how many times

```cpp
for (int i = 1; i <= n; i++) {
    sum += i;
}
```

Three parts: **start** (`int i = 1`), **keep going while** (`i <= n`), **step** (`i++`).

Code: [`examples/03_sum_to_n.cpp`](examples/03_sum_to_n.cpp)

### `while`: when you repeat until something changes

```cpp
while (n > 0) {
    sum += n % 10;
    n /= 10;
}
```

Code: [`examples/05_digit_sum.cpp`](examples/05_digit_sum.cpp)

### `break` and `continue`

- `break` leaves the loop immediately.
- `continue` skips the rest of this round and goes to the next one.

Code: [`examples/09_break_continue.cpp`](examples/09_break_continue.cpp)

### Nested loops

A loop inside a loop. The inner loop runs fully for every round of the outer loop.

Code: [`examples/10_nested_loops.cpp`](examples/10_nested_loops.cpp)

If both loops run up to `n`, the work is about `n * n`. That matters when `n` is large (see Lesson 4).

---

## 3. Contest input patterns

You will see these in almost every problem.

**Pattern A: a count, then that many values**
```cpp
int n; cin >> n;
for (int i = 0; i < n; i++) { int x; cin >> x; /* use x */ }
```
Code: [`examples/04_max_min.cpp`](examples/04_max_min.cpp)

**Pattern B: multiple test cases**
```cpp
int t; cin >> t;
while (t--) { /* read and solve one test */ }
```
Code: [`examples/08_multiple_tests.cpp`](examples/08_multiple_tests.cpp)

**Pattern C: read until the input ends**
```cpp
while (cin >> x) { /* use x */ }
```
Code: [`examples/07_read_until_eof.cpp`](examples/07_read_until_eof.cpp)

To end input in the terminal when testing pattern C, press `Ctrl+D`.

---

## 4. Common loop patterns

**Running total (use `long long`)**
```cpp
long long sum = 0;
for (...) sum += x;
```

**Maximum / minimum.** Start from the first real value, not from `0` (all numbers might be negative).
```cpp
int mx = first;
if (x > mx) mx = x;
```

**Counting**
```cpp
int cnt = 0;
if (condition) cnt++;
```

**Prime check.** A composite number has a divisor up to `sqrt(n)`, so loop while `i * i <= n`. For `n = 10^9` that is only about 31,623 steps instead of a billion.

Code: [`examples/06_is_prime.cpp`](examples/06_is_prime.cpp)

---

## 5. How to debug a loop: trace it by hand

Take a tiny input and write the variables after every round.

`n = 3`, `sum = 0`:

| round | i | sum after |
|:-:|:-:|:-:|
| 1 | 1 | 1 |
| 2 | 2 | 3 |
| 3 | 3 | 6 |

If your code and your table disagree, the bug is in that round.

**Common loop bugs**
- **Off-by-one:** `i < n` versus `i <= n`. Check the first and last round.
- **Infinite loop:** the variable in the condition never changes (forgot `i++` or `n /= 10`). Stop it with `Ctrl+C`.
- **Wrong starting value:** `mx = 0` fails when every number is negative.
- **Overflow:** a running sum in `int`.

---

## Key rules
- The first true branch of an `if`/`else if` chain runs; the rest are skipped.
- `==` compares, `=` assigns.
- Test evenness with `% 2 == 0`.
- Use `for` for counted repetition and `while` for "until it changes".
- Start max/min from the first real value.
- Use `i * i <= n` for primality, and `long long` for the sums.

## Summary
- Conditions choose, loops repeat.
- Input comes in three shapes: count then values, multiple tests, read to the end.
- Tracing a tiny example by hand finds most loop bugs.

## Quick check

1. What does `cout << (-7 % 2);` print?
2. How many times does `for (int i = 0; i < 5; i++)` run its body?
3. How many times does `for (int i = 1; i <= 5; i += 2)` run its body?
4. Why does the prime check loop only up to `sqrt(n)`?

<details>
<summary>Answers</summary>

1. `-1`
2. 5 times (i = 0, 1, 2, 3, 4)
3. 3 times (i = 1, 3, 5)
4. If `n = a * b`, one of `a` and `b` is at most `sqrt(n)`. So if no divisor is found up to `sqrt(n)`, there is none.

</details>

**Next:** [Lesson 3: Functions, vectors, and strings](../lesson-03-functions-vectors-strings/notes.md). Practice now: [`exercises.md`](exercises.md)
