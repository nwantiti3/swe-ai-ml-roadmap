# Module 00, Lesson 1: Video script
**Title:** Your first C++ program: structure, input, output, and variables
**Length:** about 8 to 10 minutes

---

## Intro (30 seconds)
Welcome back. In this lesson we write our first C++ program, and by the end you will be able to read numbers, calculate with them, and print the result. We will also see the most common bug in programming contests: overflow.

## Part 1: Hello, world (2 minutes)
[Show `01_hello.cpp` on screen]

Every C++ program starts in a function called `main`. Everything inside the curly braces runs, from top to bottom.

The first line, `#include bits slash stdc++.h`, gives us almost the whole standard library in one line. The line `using namespace std` saves us from typing `std::` in front of everything.

To print, we use `cout` and the two arrows. We end with a single-quoted backslash n, which starts a new line. And notice the semicolon: every statement ends with one.

[Switch to terminal. Type the compile command and run it]

We compile with `g++`, using C++17 and the `O2` optimization flag, and then we run the result. There it is.

## Part 2: Variables and types (2 minutes)
[Show the variables snippet]

A variable is a named box that holds a value, and its type decides what fits inside. An `int` holds whole numbers up to about two billion. A `long long` holds up to about nine quintillion. A `double` holds decimals, a `char` one character, a `string` text, and a `bool` true or false.

Here is the first big rule of contests: if a number, or the result of a multiplication, could pass two billion, use `long long`.

## Part 3: Reading input (2 minutes)
[Show `02_add.cpp`]

To read, we use `cin` with arrows pointing the other way. This line reads two numbers, one after the other, separated by spaces or new lines. Then we print their sum.

[Run it with input `3 4`, output `7`]

The operators are plus, minus, times, divide, and percent for the remainder. One trap: with integers, seven divided by two gives three, not three and a half. The decimal part is dropped. If you need the decimal, make one side a `double`.

## Part 4: Overflow (2 minutes)
[Show `03_overflow.cpp`, run it]

Look at this. Ten to the nine times ten to the nine should be ten to the eighteen, but the first line prints something wrong.

Why? Both numbers are `int`, so the computer multiplies them as `int`. The real answer does not fit, so it wraps around, and this happens silently, with no error. Storing the result in a `long long` afterward is too late, because the damage is already done.

The fix is on the second line: convert one number to `long long` first. Then the multiplication is done in `long long`, and the answer is correct.

## Recap (30 seconds)
- A program starts in `main`.
- `cin` reads, `cout` prints.
- Pick the type by the size of your numbers.
- Overflow is silent, so check your limits.

## Outro
Your task: solve the three exercises in the description, alone, before using the hints. In the next lesson, we learn conditions and loops. See you there.
