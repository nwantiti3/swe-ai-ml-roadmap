# Module 00, Lesson 4: The contest toolkit

**Goal:** write fast solutions with a reliable template, estimate whether an algorithm will be fast enough, and test and debug like a contestant.

**Prerequisite:** [Lesson 3](../lesson-03-functions-vectors-strings/notes.md)

---

## 1. The contest template

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve() {
    // read input, compute, print answer
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
```

Why this shape:
- `solve()` handles **one test case**. For multiple tests, uncomment `cin >> t;`.
- `ll` saves typing `long long` everywhere.
- `all(v)` lets you write `sort(all(v))`.
- The full version is in [`templates/template.cpp`](../../../templates/template.cpp).

Code: [`examples/01_template_sum.cpp`](examples/01_template_sum.cpp)

---

## 2. Fast input and output

Two lines make `cin` and `cout` much faster:

```cpp
ios::sync_with_stdio(false);   // stop syncing with C's stdio
cin.tie(nullptr);              // don't flush cout before each cin
```

And **use `'\n'`, not `endl`.** `endl` flushes the output buffer on every line, which is very slow for many lines.

**Rule:** after `sync_with_stdio(false)`, do not mix `cin/cout` with `scanf/printf` in the same program.

### Measure it yourself

```bash
(echo 1000000; seq 1 1000000) > big.txt
g++ -O2 examples/02_io_slow.cpp -o slow
g++ -O2 examples/03_io_fast.cpp -o fast
time ./slow < big.txt > /dev/null
time ./fast < big.txt > /dev/null
```

Code: [`02_io_slow.cpp`](examples/02_io_slow.cpp), [`03_io_fast.cpp`](examples/03_io_fast.cpp)

---

## 3. Complexity: will it be fast enough?

**Big-O** describes how the number of steps grows with the input size `n`.

| Complexity | Name | Example |
|:--|:--|:--|
| `O(1)` | constant | read one element `a[i]` |
| `O(log n)` | logarithmic | binary search |
| `O(n)` | linear | one loop over the data |
| `O(n log n)` | linearithmic | `sort` |
| `O(n²)` | quadratic | two nested loops |
| `O(n³)` | cubic | three nested loops |
| `O(2ⁿ)` | exponential | try all subsets |

### The rule of thumb

A computer does about **10⁸ simple operations per second**. Contest time limits are usually 1 to 2 seconds. So:

| Input limit `n` | Complexity you can afford |
|:--|:--|
| `n ≤ 10` | `O(n!)` |
| `n ≤ 20` | `O(2ⁿ)` |
| `n ≤ 500` | `O(n³)` |
| `n ≤ 5,000` | `O(n²)` |
| `n ≤ 10⁶` | `O(n log n)` |
| `n ≤ 10⁷ to 10⁸` | `O(n)` |

**How to use it:** read the limit in the problem, compute `n²` or `n log n`, and check if it stays under about 10⁸. If `n = 10⁵` and your idea is `O(n²)`, that is 10¹⁰ steps, too slow. You need a better idea *before* you write code.

Code: [`examples/04_complexity_demo.cpp`](examples/04_complexity_demo.cpp)

> **Always estimate complexity before coding.** It is the cheapest way to avoid a Time Limit Exceeded (TLE).

---

## 4. Compile flags you should know

| Purpose | Command |
|:--|:--|
| Normal | `g++ -std=c++17 -O2 file.cpp -o out` |
| Warnings | add `-Wall -Wextra` |
| Debug (catches many bugs) | `g++ -std=c++17 -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG file.cpp -o out` |

The debug build is slower, but it reports out-of-bounds access, uninitialized-style bugs through warnings, and signed overflow.

**Reading warnings:** treat them as hints. A warning about "comparison between signed and unsigned" or "may be used uninitialized" often points at a real bug.

---

## 5. Testing your solution

### Test with a file instead of typing

```bash
./out < in.txt            # read input from a file
./out < in.txt > out.txt  # and save the output
```

### Test edge cases

Before submitting, always try:
- the smallest input (`n = 1`)
- the largest input (check speed and overflow)
- all equal values, all negative values, zeros
- a case with a single answer, and a case with no answer

### Stress testing

When a solution gives Wrong Answer and you can't see why:
1. Write a **brute force**: slow, simple, obviously correct.
2. Write a **generator** of small random inputs.
3. Run both on thousands of inputs and compare. The first difference is a tiny failing case you can trace by hand.

The kit in [`examples/stress/`](examples/stress/) does this for the maximum subarray sum problem (the fast solution is a preview of an idea from a later module). Run:

```bash
cd examples/stress
bash stress.sh
```

Then **break `fast.cpp` on purpose** (for example, start `cur` at `0`) and watch the stress test catch it.

---

## 6. Typical contest errors

| Verdict | Common cause |
|:--|:--|
| Wrong Answer | overflow, off-by-one, uninitialized variable, unhandled edge case |
| Runtime Error | index out of bounds, division by zero, deep recursion |
| Time Limit Exceeded | wrong complexity, slow I/O (`endl`, no `sync_with_stdio(false)`), infinite loop |
| Compile Error | missing `;`, wrong type, a library not included |

**Debugging checklist**
1. Re-read the problem statement. Did you solve the right problem?
2. Check types and overflow.
3. Check the first and last iteration of every loop.
4. Initialize every variable.
5. Run the debug build.
6. Stress test.

Try [`examples/05_buggy.cpp`](examples/05_buggy.cpp): it has 3 planted bugs.

---

## Key rules
- Use one shared template: `solve()`, fast I/O, `ll`.
- `'\n'`, never `endl`.
- Estimate complexity from `n` before coding: about 10⁸ operations per second.
- Compile with sanitizers while debugging.
- Test edge cases, and stress test when stuck.

## Summary
- A good template removes silly mistakes.
- Complexity decides whether an idea can work at all.
- Testing is part of solving, not something extra.

## Quick check

1. `n = 2·10⁵`. Is an `O(n²)` solution fast enough? Why?
2. Why is `endl` slow?
3. You get Wrong Answer, and the code looks right. Name two quick things to try.

<details>
<summary>Answers</summary>

1. No. `(2·10⁵)² = 4·10¹⁰`, far above about 10⁸ operations per second times the time limit.
2. It flushes the output buffer every time. `'\n'` does not.
3. Examples: run the debug build with sanitizers; check overflow; test edge cases (`n = 1`, negatives); write a brute force and stress test.

</details>

**Module complete.** Next: Module 01, STL and the contest toolkit. Practice now: [`exercises.md`](exercises.md)
