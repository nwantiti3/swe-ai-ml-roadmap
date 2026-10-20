# Templates

Reusable contest code. Every file here must compile and be tested before it is committed.

| File | Contents | Status |
|:--|:--|:-:|
| `template.cpp` | Main contest template: fast I/O, `ll`, `power()`, `solve()` structure | 🟢 |
| `dsu.cpp` | Disjoint set union | ⚪ planned |
| `dijkstra.cpp` | Shortest paths with `priority_queue` | ⚪ planned |
| `sieve.cpp` | Sieve of Eratosthenes | ⚪ planned |
| `fenwick.cpp` | Fenwick tree | ⚪ planned |

Compile: `g++ -std=c++17 -O2 file.cpp -o out`
Debug: `g++ -std=c++17 -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG file.cpp -o out`
