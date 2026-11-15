/* fastest-primes: count primes <= N (1 <= N <= 5,000,000).
 *
 * Odd-only Sieve of Eratosthenes. Only odd numbers >= 3 are stored
 * (index i represents 2*i+3); 2 is counted separately. Marking starts
 * at p*p and steps by p in index space (= 2p in value space).
 *
 * Reads N from stdin, prints the count on stdout.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long n;
    if (scanf("%ld", &n) != 1)
        return 0;
    if (n < 2) {
        printf("0\n");
        return 0;
    }

    /* m = number of odd integers in [3, n] */
    long m = (n - 1) / 2;
    unsigned char *is_comp = calloc((size_t)m, 1);
    if (!is_comp)
        return 1;

    long count = 1; /* prime 2 */
    for (long i = 0; i < m; i++) {
        if (!is_comp[i]) {
            long p = 2 * i + 3;
            count++;
            if (p * p <= n) {
                long start = (p * p - 3) / 2;
                for (long j = start; j < m; j += p)
                    is_comp[j] = 1;
            }
        }
    }

    printf("%ld\n", count);
    free(is_comp);
    return 0;
}
