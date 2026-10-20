# Module 00, Lesson 3: Video script
**Title:** Functions, vectors, and strings in C++
**Length:** about 14 minutes

---

## Intro (30 seconds)
So far, all our code lives inside `main`. Today we learn three tools that turn small programs into real solutions: functions, vectors, and strings.

## Part 1: Functions (3 minutes)
[Show `01_functions.cpp`]

A function is a named piece of code you can call again and again. It has a return type, a name, and parameters. `square` takes an int and returns an int. A function that returns nothing is `void`. Define it above `main`, so it is known when used.

Here is a famous one: Euclid's algorithm for the greatest common divisor. While `b` is not zero, replace `a` and `b` with `b` and the remainder. When `b` hits zero, `a` is the answer.

[Show `02_pass_by_ref.cpp`]

Now, an important detail. By default, a function gets a copy of its arguments, so changes inside don't reach the caller. Add an ampersand and the function works on the original. For big objects like vectors, use a const reference. It avoids a slow copy, and the const promises we won't change it.

## Part 2: Vectors (4 minutes)
[Show `03_vector_basics.cpp`]

A vector is a resizable list. Push back adds to the end, size tells you how many elements, and indexes start at zero. So the last valid index is size minus one.

The standard way to read numbers: make a vector of size `n`, then loop and read into each slot.

Two traps. The size is unsigned, so on an empty vector, size minus one becomes a gigantic number. Cast it to int. And going past the last index is a silent bug. Compile with the debug flag from Lesson 4 and it will shout instead.

[Show `04_sort_reverse.cpp`]

Sorting is one line. It takes n log n time, so a million elements is no problem. For a different order, pass a lambda, a tiny function that says whether `a` goes before `b`. Also useful: reverse, min element, max element, and accumulate for sums. Write zero L L, not plain zero, or the sum happens in int.

[Show `05_grid_2d.cpp`]

A vector of vectors makes a grid. Row first, then column.

## Part 3: Strings (3 minutes)
[Show `06_strings.cpp`]

A string works like a vector of characters. Size, indexing, plus-equals to join, substr to cut, and reverse works too.

Characters are numbers underneath. `a` plus one is `b`, and a digit character minus the character zero gives the digit's value.

`cin` reads one word. To read a whole line, use `getline`. But watch out: if `getline` comes right after `cin` of a number, the leftover newline gives you an empty line. Call `cin.ignore` first.

## Part 4: Pairs (1.5 minutes)
[Show `07_pairs.cpp`]

A pair holds two values, first and second. Sorting a vector of pairs sorts by first, then second. Need another order? Same trick: a lambda.

## Recap
- Functions: reuse code, pass big things by const reference.
- Vector: default container, indexes from zero.
- Sort and friends are one-liners.
- Strings are lists of characters, and getline reads lines.

## Outro
Nine exercises are waiting in the description. Do them alone first. Next lesson, the last in this module: the contest toolkit, with fast input and output, complexity, and how to test your code.
