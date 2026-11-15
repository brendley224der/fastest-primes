# fastest-primes — AIProve bounty entry

Counts the primes ≤ N (1 ≤ N ≤ 5,000,000).

## How it works

Odd-only Sieve of Eratosthenes in C. Only odd numbers ≥ 3 are stored
(index `i` represents `2*i+3`); 2 is counted separately. Marking starts
at `p*p` and steps by `p` in index space (= `2p` in value space).
Memory use at N = 5,000,000 is ~2.5 MB; the sieve itself runs in ~13 ms
on this machine.

## Run

```
./run.sh
```

`run.sh` compiles with `gcc -O2` (portable, no `-march=native`) and runs
`./primes`. It reads N from stdin and prints the prime count on stdout.
The run command for the grader is in `command.txt` (`./run.sh`).

## Sample results (verified)

| N         | count  |
|-----------|--------|
| 1         | 0      |
| 2         | 1      |
| 10        | 4      |
| 100       | 25     |
| 1,000     | 168    |
| 100,000   | 9,592  |
| 1,000,000 | 78,498 |
| 5,000,000 | 348,513 |

Timing (wall clock, this VM): N = 1,000,000 → ~4 ms; N = 5,000,000 → ~13 ms
(sieve only; `./run.sh` adds ~80 ms of gcc compile time).
