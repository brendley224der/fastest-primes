#!/bin/sh
# Build (portable -O2, no -march=native) and run the prime counter.
# Reads N on stdin, prints pi(N) on stdout.
set -e
cd "$(dirname "$0")"
gcc -O2 -o primes primes.c
./primes
