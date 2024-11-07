#include "prime.h"

int main() {
  long solution = 0;
  int longest_streak = 0;
  int *sieve = create_prime_sieve(1000);

  for (int a = -1000; a < 1000; a++) {
    for (int b = 1; b <= 1000; b++) {
      long current_streak = 0;
      for (int n = 0; n < 1000; n++) {
        int current_value = n * n + a * n + b;
        if (current_value > 0 && sieve[current_value]) {
          current_streak++;
        } else {
          if (current_streak > longest_streak) {
            longest_streak = current_streak;
            solution = a * b;
          }
          break;
        }
      }
    }
  }
  return solution != -59231;
}
