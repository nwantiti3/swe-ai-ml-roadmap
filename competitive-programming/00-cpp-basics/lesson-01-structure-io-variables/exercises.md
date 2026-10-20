# Module 00, Lesson 1: Exercises

Try each one alone for 20 to 30 minutes before using hints. Use hints one at a time. Put your solutions in a `solutions/` folder next to this file, and log any mistake in [`../../../error-log.md`](../../../error-log.md).

## Exercise 1: Sum and product
Read two integers. Print their sum on the first line and their product on the second line.

**Example**

Input:
```
3 4
```
Output:
```
7
12
```

- Hint 1: read with `cin >> a >> b`.
- Hint 2: print each result followed by `'\n'`.

## Exercise 2: Big multiplication
Read two integers, each up to 10^9. Print their product.

**Example**

Input:
```
1000000000 1000000000
```
Output:
```
1000000000000000000
```

- Hint 1: run it with `int` first. What do you get?
- Hint 2: what type can hold 10^18?
- Hint 3: see where the conversion to `long long` must happen (see `examples/03_overflow.cpp`).

## Exercise 3: Average
Read three integers. Print their average with exactly 2 decimals.

**Example**

Input:
```
1 2 4
```
Output:
```
2.33
```

- Hint 1: dividing two integers drops the decimals.
- Hint 2: make at least one side of the division a `double`.
- Hint 3: look up `fixed` and `setprecision(2)` from `<iomanip>`.

## After solving
- Explain each solution out loud in your own words.
- Write any mistake you made in `error-log.md`.
- Update the status in `progress.md`.
