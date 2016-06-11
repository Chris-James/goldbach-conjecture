/*
Goldbach's Conjecture

"Every even number greater than or equal to 4 can be expressed as the sum of two prime numbers."

Verify Goldbach's conjecture as expressed by Euler for any even numbers less than a million submitted by user.

Author: Chris Impastato
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

    while (lo <= hi) {
      if ( is_prime(lo) && is_prime(hi) ) {
        printf("%d = %d + %d \n", n, lo, hi);
        break;
      }
      lo += 2;
      hi = n - lo;
    }
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
