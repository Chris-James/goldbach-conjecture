/*
Goldbach's Conjecture
Author: Chris Impastato

Reads in a set of even numbers from 6 to 1000000
For each number n it determines the two odd primes whose sum is n.
Breaks ties by choosing the pair with the largest difference.
It then outputs it in the form: n = a + b.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int);

int main() {

  int n;
  scanf("%d", &n);

  while (n != 0) {

    int lo = 3;
    int hi = n - lo;
    int found_primes = 0;

    while (lo <= hi) {
      if ( is_prime(lo) && is_prime(hi) ) {
        found_primes = 1;
        break;
      }
      lo += 2;
      hi = n - lo;
    }
    found_primes ? printf("%d = %d + %d \n", n, lo, hi) : printf("Goldbach’s conjecture is wrong. \n");
    scanf("%d", &n);
  }

  return 0;
}

int is_prime(int target) {
  const int NOT_PRIME = 0;
  const int PRIME = 1;

  int bound = floor(sqrt(target));
  int divisor = 3;

  // First, check if the target is divisible by 2.
  if (target % 2 == 0) {
    return NOT_PRIME;
  }

  // Since we checked target's divisibility by 2 we no longer need to check even numbers.
  // Use a loop to check all odd numbers greater than 2.
  while (divisor <= bound) {
    if (target % divisor == 0) {
      return NOT_PRIME;
    }
    divisor += 2;
  }

  return PRIME;

}
