# Module 00, Lesson 2: Exercises

Rules: try each exercise alone for 20 to 30 minutes first. Use hints one at a time. Put your solutions in a `solutions/` folder next to this file. Log any mistake in [`../../../error-log.md`](../../../error-log.md).

Difficulty: ⭐ easy · ⭐⭐ medium · ⭐⭐⭐ challenge

---

## Exercise 1 ⭐ Even or odd
Read an integer `n` (it can be negative). Print `even` or `odd`.

Input: `7` → Output: `odd`
Input: `-4` → Output: `even`

- Hint 1: use `%`.
- Hint 2: what does `-3 % 2` give in C++?

## Exercise 2 ⭐ Sign
Read an integer. Print `negative`, `zero`, or `positive`.

Input: `-5` → Output: `negative`

- Hint 1: you need three branches.
- Hint 2: use `if`, `else if`, `else`.

## Exercise 3 ⭐ Sum from 1 to n
Read `n` (1 ≤ n ≤ 10^5). Print `1 + 2 + ... + n`.

Input: `100` → Output: `5050`

- Hint 1: a `for` loop and a running total.
- Hint 2: which type for the total?
- **Bonus** ⭐⭐: now `n` can be up to 10^9. A loop is too slow to rely on. Find a formula for the sum. Which type is needed? Test with `1000000000` (answer: `500000000500000000`).

## Exercise 4 ⭐ Max and min
First line: `n`. Second line: `n` integers. Print the maximum and the minimum.

Input:
```
5
3 -1 9 4 0
```
Output: `9 -1`

- Hint 1: you need two variables updated inside a loop.
- Hint 2: what should they start as? Test with all negative numbers.

## Exercise 5 ⭐⭐ Digit sum
Read `n` (0 ≤ n ≤ 10^18). Print the sum of its digits.

Input: `9875` → Output: `29`
Input: `0` → Output: `0`

- Hint 1: `n % 10` is the last digit. `n / 10` removes it.
- Hint 2: which type holds 10^18?
- Hint 3: does your loop handle `n = 0`?

## Exercise 6 ⭐⭐ Prime or not
Read `n` (1 ≤ n ≤ 10^9). Print `prime` or `not prime`.

Input: `97` → Output: `prime`
Input: `1` → Output: `not prime`
Input: `1000000007` → Output: `prime`

- Hint 1: try dividing by numbers from 2.
- Hint 2: how far do you really need to go? Think about `i * i <= n`.
- Hint 3: watch the type of `i` when `n` is near 10^9. Is `i * i` safe in `int`?

## Exercise 7 ⭐⭐ Multiple tests
First line: `t`. Then `t` lines, each with two positive integers `a` and `b`. For each line print `YES` if `a` is divisible by `b`, otherwise `NO`.

Input:
```
3
10 5
7 2
9 3
```
Output:
```
YES
NO
YES
```

- Hint 1: read `t`, then loop `t` times.
- Hint 2: `a % b == 0`.

## Exercise 8 ⭐ FizzBuzz
Read `n`. For each `i` from 1 to `n`, print `Fizz` if `i` is divisible by 3, `Buzz` if divisible by 5, `FizzBuzz` if divisible by both, otherwise `i`.

Input: `15` → Output (one per line): `1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz`

- Hint 1: which case must be checked first?

## Exercise 9 ⭐⭐⭐ Read until the end
The input has an unknown amount of integers (no count). Print how many are positive, how many are negative, and how many are zero.

Input: `5 -2 0 7 -9 0`
Output: `positive 2, negative 2, zero 2`

- Hint 1: pattern C, `while (cin >> x)`.
- Hint 2: test it in the terminal with `Ctrl+D`, or with `echo "5 -2 0" | ./a.out`.

---

## After solving
- Explain each solution out loud in your own words.
- Write every mistake in `error-log.md` with a rule for next time.
- Update `progress.md`.
