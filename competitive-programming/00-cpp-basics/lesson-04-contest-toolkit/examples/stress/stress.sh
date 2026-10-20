#!/bin/bash
# Stress test: compare a fast solution with a brute force on many random tests.
# Usage: bash stress.sh
set -e
g++ -std=c++17 -O2 brute.cpp -o brute
g++ -std=c++17 -O2 fast.cpp  -o fast
g++ -std=c++17 -O2 gen.cpp   -o gen

for i in $(seq 1 1000); do
    ./gen $i > in.txt
    ./brute < in.txt > out_brute.txt
    ./fast  < in.txt > out_fast.txt
    if ! cmp -s out_brute.txt out_fast.txt; then
        echo "DIFFERENT on test $i"
        echo "--- input:";  cat in.txt
        echo "--- brute:";  cat out_brute.txt
        echo "--- fast:";   cat out_fast.txt
        exit 1
    fi
done
echo "All 1000 tests passed"
