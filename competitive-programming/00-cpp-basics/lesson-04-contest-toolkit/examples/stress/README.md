# Stress test kit

Finds bugs by comparing a fast solution with a slow but obviously correct one on thousands of random tiny inputs.

| File | Role |
|:--|:--|
| `brute.cpp` | slow, simple, trusted solution |
| `fast.cpp` | the solution you want to test |
| `gen.cpp` | random test generator (takes a seed) |
| `stress.sh` | compiles everything and compares outputs |

Run: `bash stress.sh`

If a test fails, the script prints the input and both answers. Shrink that input by hand, trace it, and find the bug.

Reuse: copy this folder into `templates/stress/` and replace `brute.cpp`, `fast.cpp`, and `gen.cpp` for each new problem.
