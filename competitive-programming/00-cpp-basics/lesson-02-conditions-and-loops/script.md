# Module 00, Lesson 2: Video script
**Title:** Conditions and loops in C++: making programs decide and repeat
**Length:** about 12 minutes

---

## Intro (30 seconds)
Welcome back. In Lesson 1 our programs ran straight from top to bottom. Today they learn to decide and to repeat. Almost every contest problem is built from these two ideas.

## Part 1: if and else (2.5 minutes)
[Show `01_even_odd.cpp`]

An `if` runs a block only when its condition is true. Add `else` for the other case. Here, `n % 2 == 0` is true for even numbers.

[Show `02_grade.cpp`]

With a chain of `else if`, the computer checks from the top, and the first true condition wins. The rest are skipped, so order matters.

Two traps. First, a single equals sign assigns, a double equals compares. Writing a single one inside an `if` is a classic bug. Second, in C++ the remainder of a negative number is negative. Minus three mod two is minus one, so always test "equals zero".

For combining conditions, `&&` means and, double pipe means or, and exclamation means not.

## Part 2: for and while (3 minutes)
[Show `03_sum_to_n.cpp`]

A `for` loop has three parts: where to start, when to keep going, and how to step. This one runs `i` from one to `n`, adding to a running sum. The sum is a `long long`, remember Lesson 1.

[Show `05_digit_sum.cpp`]

A `while` loop repeats as long as its condition is true. To sum digits: take the last digit with mod ten, then remove it by dividing by ten. Repeat until nothing is left.

[Show `09_break_continue.cpp`]

`continue` skips the rest of this round. `break` leaves the loop. And [show `10_nested_loops.cpp`] a loop inside a loop runs the inner one fully for each round of the outer one. If both go up to `n`, that is about `n` times `n` steps. Keep that in mind, we will see why in Lesson 4.

## Part 3: contest input patterns (2.5 minutes)
[Show the three patterns]

Pattern A: a count, then that many numbers. Pattern B: multiple test cases, where you read `t` and loop `t` times. Pattern C: no count at all, so you read until the input ends with `while cin arrow x`. In the terminal you end input with Control D.

## Part 4: useful loop recipes (2 minutes)
[Show `04_max_min.cpp` and `06_is_prime.cpp`]

For max and min, start from the first real value, never from zero, because every number might be negative.

For primes, a composite number always has a divisor up to its square root. So we loop while `i` times `i` is at most `n`. For a number near a billion, that is about thirty-one thousand steps instead of a billion.

## Part 5: debugging by hand (1 minute)
Take a tiny input and write down the variables after every round. When your table and your code disagree, the bug is in that round. Watch for off-by-one errors, infinite loops where the variable never changes, wrong starting values, and overflow.

## Recap
- `if` chooses, loops repeat.
- Compare with double equals, test evenness with mod equals zero.
- Three input patterns: count, tests, until the end.
- Start max and min from the first value, loop to the square root for primes.

## Outro
Your task is the nine exercises in the description. Try each alone first. Next lesson: functions, vectors, and strings.
