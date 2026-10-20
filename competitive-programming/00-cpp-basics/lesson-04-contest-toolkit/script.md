# Module 00, Lesson 4: Video script
**Title:** The contest toolkit: template, fast I/O, complexity, and testing
**Length:** about 14 minutes

---

## Intro (30 seconds)
You now know enough C++ to solve small problems. In a contest, that's not enough. You also need speed, a reliable setup, and a way to find bugs fast. Today is the toolkit.

## Part 1: The template (2 minutes)
[Show `01_template_sum.cpp`]

Every solution starts from the same shape. A `solve` function that handles one test case. A `main` that sets up fast input and output, and loops over the test cases. A shortcut `ll` for long long, and an `all` macro so we can write sort of all v.

Why bother? Because it removes silly mistakes, and every teammate can read every other teammate's code.

## Part 2: Fast I/O (2.5 minutes)
[Show the two lines]

These two lines make input and output much faster. The first stops C++ from syncing with the old C library. The second stops it from flushing the output before every input.

And the second rule: use backslash n, never `endl`. `endl` flushes the buffer every time.

[Run the timing experiment live: `time ./slow` and `time ./fast`]

Look at the difference on a million lines. In a contest with big inputs, this is the difference between accepted and time limit exceeded.

## Part 3: Complexity (3.5 minutes)
[Show the table]

Big-O tells us how the number of steps grows with the input size. One loop is order n. Sorting is n log n. Two nested loops, n squared.

Here's the rule of thumb: a computer does around a hundred million simple operations per second. So read the limit in the problem, compute the steps, and compare. If `n` is a hundred thousand and your idea is n squared, that's ten billion steps. Too slow, and you need a better idea before writing any code.

[Run `04_complexity_demo.cpp`]

Same `n`, one loop versus two. See how big the gap is already at fifty thousand.

## Part 4: Compiling and debugging (2 minutes)
[Show the flags table]

For normal runs, compile with `O2`. While debugging, add the sanitizer flags and the debug library flag. They catch out-of-bounds access and overflow and point to the exact line.

[Run `05_buggy.cpp` with the debug build]

Here are three planted bugs. An off-by-one in the loop, an int that overflows, and a variable that never got a value. The sanitizer finds the first for us. Read the first error from the top, fix it, and run again.

## Part 5: Testing and stress testing (2.5 minutes)
[Show the stress folder]

Always test edge cases: the smallest input, the largest, all negatives, all equal.

And when you get Wrong Answer and cannot see why, use a stress test. Write a slow, simple, obviously correct brute force. Write a generator of tiny random inputs. Run both on a thousand tests and compare. The first difference is a tiny failing case you can trace by hand.

[Run `bash stress.sh`, then break `fast.cpp` and run again]

Passed. Now I break the fast solution on purpose... and the stress test immediately shows a small failing input. That is how you find a bug in minutes instead of hours.

## Recap
- One template, `solve`, fast I/O, `long long`.
- `endl` is slow, use backslash n.
- Estimate complexity from `n` before coding.
- Debug build with sanitizers, edge cases, stress tests.

## Outro
That finishes Module 0. The exercises are in the description, including the bug hunt and your own stress test. Next module: the STL, with map, set, and priority queue, the data structures that turn slow ideas into fast ones. See you there.
