#include <stdio.h>

unsigned long reverse_number(unsigned long n) {
  unsigned long reversed = 0;

  while (n != 0) {
    reversed = reversed * 10 + (n % 10); // Grab last digit
    n /= 10; // remove last digit
  }

  return reversed;
}

int is_palindrome(unsigned long n) {
  return reverse_number(n) == n;
}

int main() {
  unsigned long solution = 0;
  unsigned long current_value = 0;
  
  for (int i = 1; i < 1000; i++) {
    for (int j = 1; j < 1000; j++) {
      current_value = i * j;
      if (is_palindrome(current_value)) {
        if (current_value > solution) {
          solution = current_value;
        }
      }
    }
  }
  printf("%lu\n", solution);
  return 0;
}

