# Module 00, Lesson 3: Exercises

Rules: try each exercise alone for 20 to 30 minutes first. Use hints one at a time. Put your solutions in a `solutions/` folder next to this file. Log mistakes in [`../../../error-log.md`](../../../error-log.md).

Difficulty: ⭐ easy · ⭐⭐ medium · ⭐⭐⭐ challenge

---

## Exercise 1 ⭐ Reverse
First line: `n`. Second line: `n` integers. Print them in reverse order, separated by spaces.

Input:
```
5
1 2 3 4 5
```
Output: `5 4 3 2 1`

- Hint 1: store the numbers in a `vector`.
- Hint 2: use `reverse`, or loop from the end.

## Exercise 2 ⭐ Sort
First line: `n`. Second line: `n` integers. Print them in ascending order.

Input:
```
4
3 1 4 2
```
Output: `1 2 3 4`

- Hint 1: `sort(v.begin(), v.end())`.
- **Bonus** ⭐: print them in descending order.

## Exercise 3 ⭐ Count occurrences
First line: `n`. Second line: `n` integers. Third line: an integer `x`. Print how many times `x` appears.

Input:
```
6
1 2 2 3 2 5
2
```
Output: `3`

- Hint 1: a counter and a loop.

## Exercise 4 ⭐ Palindrome
Read a string (no spaces). Print `YES` if it reads the same backwards, otherwise `NO`.

Input: `level` → Output: `YES`
Input: `abca` → Output: `NO`

- Hint 1: compare the string with its reversed copy.
- Hint 2: or compare `s[i]` with `s[n - 1 - i]`.

## Exercise 5 ⭐⭐ Count vowels
Read a full line (it may contain spaces). Print how many vowels (`a e i o u`, any case) it has.

Input: `Hello World` → Output: `3`

- Hint 1: you need `getline`, not `cin >>`.
- Hint 2: convert each character with `tolower`.

## Exercise 6 ⭐⭐ Row sums
First line: `r` and `c`. Then `r` rows of `c` integers. Print the sum of each row, one per line.

Input:
```
2 3
1 2 3
4 5 6
```
Output:
```
6
15
```

- Hint 1: `vector<vector<int>>`.
- **Bonus** ⭐⭐: also print the sum of each column.

## Exercise 7 ⭐⭐ Count the primes
Write a function `bool isPrime(int n)`. Read `n` (1 ≤ n ≤ 10^5) and print how many primes there are from 1 to `n`.

Input: `10` → Output: `4` (2, 3, 5, 7)
Input: `100` → Output: `25`

- Hint 1: reuse your prime check from Lesson 2, now inside a function.
- Hint 2: call it in a loop and count the `true` results.

## Exercise 8 ⭐⭐ Second largest
First line: `n` (n ≥ 2). Second line: `n` integers. Print the second largest **distinct** value. If there is none, print `NONE`.

Input:
```
5
4 9 9 7 1
```
Output: `7`

Input:
```
3
5 5 5
```
Output: `NONE`

- Hint 1: sort first.
- Hint 2: look for the first value different from the maximum.
- **Bonus** ⭐⭐⭐: solve it in one pass without sorting.

## Exercise 9 ⭐⭐⭐ Sort pairs
First line: `n`. Then `n` lines, each with a name (one word) and a score. Print the names sorted by score from highest to lowest. If scores tie, sort alphabetically by name.

Input:
```
4
ali 80
sara 95
omar 80
lina 70
```
Output:
```
sara
ali
omar
lina
```

- Hint 1: store `pair<int, string>`.
- Hint 2: you need a custom comparator (lambda) with two rules.

---

## After solving
- Explain each solution out loud in your own words.
- Write every mistake in `error-log.md` with a rule for next time.
- Update `progress.md`.
