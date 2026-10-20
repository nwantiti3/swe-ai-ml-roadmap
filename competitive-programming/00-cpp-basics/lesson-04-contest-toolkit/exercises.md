# Module 00, Lesson 4: Exercises

Rules: try each exercise alone for 20 to 30 minutes first. Use hints one at a time. Put your solutions in a `solutions/` folder next to this file. Log mistakes in [`../../../error-log.md`](../../../error-log.md).

Difficulty: ⭐ easy · ⭐⭐ medium · ⭐⭐⭐ challenge

---

## Exercise 1 ⭐ Use the template
Copy `templates/template.cpp` and use it to solve: read two integers (each up to 10⁹) and print their product.

Input: `1000000000 1000000000` → Output: `1000000000000000000`

- Hint 1: put the logic inside `solve()`.
- Hint 2: use `ll`.

## Exercise 2 ⭐ Measure fast I/O
Follow the "Measure it yourself" steps in the notes. Write down the two times you measured, and explain in two sentences why they differ.

- Hint 1: use `time ./slow < big.txt > /dev/null`.
- Hint 2: look at what `endl` does.

## Exercise 3 ⭐ Sum of n numbers
First line: `n` (1 ≤ n ≤ 2·10⁵). Second line: `n` integers, each up to 10⁹. Print the sum.

Input:
```
3
1000000000 1000000000 1000000000
```
Output: `3000000000`

- Hint 1: start from `examples/01_template_sum.cpp`, but try writing it yourself first.

## Exercise 4 ⭐⭐ Count pairs
First line: `n` and `k` (n ≤ 2000). Second line: `n` integers. Print how many pairs of positions `i < j` have `a[i] + a[j] == k`.

Input:
```
5 6
1 5 3 3 2
```
Output: `2`

- Hint 1: two nested loops, with `j` starting after `i`.
- Hint 2: what is the complexity? Is it fast enough for `n = 2000`?
- **Think about it** ⭐⭐⭐: what if `n = 2·10⁵`? Your `O(n²)` solution is too slow. Write down any idea you have; we will see good ones in the STL module.

## Exercise 5 ⭐⭐ Complexity worksheet
For each case, decide: **OK** or **TLE** (assume 1 second and about 10⁸ operations).

| # | `n` | Algorithm |
|:-:|:--|:--|
| a | 10⁵ | `O(n²)` |
| b | 10⁵ | `O(n log n)` |
| c | 2000 | `O(n²)` |
| d | 10⁶ | `O(n log n)` |
| e | 10⁵ | `O(n³)` |
| f | 20 | `O(2ⁿ)` |
| g | 10⁶ | `O(n²)` |
| h | 500 | `O(n³)` |

<details>
<summary>Answers</summary>

- a: 10¹⁰, **TLE**
- b: about 1.7·10⁶, **OK**
- c: 4·10⁶, **OK**
- d: about 2·10⁷, **OK**
- e: 10¹⁵, **TLE**
- f: about 10⁶, **OK**
- g: 10¹², **TLE**
- h: about 1.25·10⁸, **borderline** (usually OK with a simple inner loop)

</details>

## Exercise 6 ⭐⭐ Run the stress test
In `examples/stress/`:
1. Run `bash stress.sh` and confirm all tests pass.
2. Break `fast.cpp` on purpose (start `cur` at `0`). Run again. What failing input does it print?
3. Trace that input by hand and explain the bug in one sentence.
4. Put the lesson into `error-log.md`.

- Hint 1: the failing input will be tiny. Trace what happens to the first element.

## Exercise 7 ⭐⭐ Bug hunt
`examples/05_buggy.cpp` has 3 bugs. Find them using the debug build:

```bash
g++ -std=c++17 -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG 05_buggy.cpp -o buggy
echo "3 2000000000 2000000000 5" | ./buggy
```

- Hint 1: read the first error message from the top.
- Hint 2: one bug is in the first loop, one in the types, and one is a variable with no starting value.

<details>
<summary>Answers</summary>

1. `i <= n` reads one element too many (`a[n]` is out of bounds). Fix: `i < n`.
2. `int sum` overflows. Fix: `long long sum`.
3. `int best;` has no starting value. Fix: `int best = a[0];` (or `INT_MIN`).

After fixing, the output is `4000000005 2000000000`.

</details>

## Exercise 8 ⭐⭐⭐ Your own stress test
Choose any exercise from Lesson 2 or 3 where you wrote a fast solution (for example, "count pairs"). Write a brute force, a generator, and a script, and run 1000 tests. Copy your work to `templates/stress/`.

---

## After solving
- Explain each solution out loud in your own words.
- Write every mistake in `error-log.md` with a rule for next time.
- Update `progress.md`.
