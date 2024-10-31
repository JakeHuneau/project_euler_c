// 014.c
#include "util.h"
#include <stdlib.h>

int main() {
  long max_value = 1000000;
  // Make a map of known sequence lengths
  unsigned long *sequence_lengths = calloc(max_value, sizeof(unsigned long));

  unsigned long longest = 0;
  unsigned long longest_length = 0;
  unsigned long long current_collatz;
  unsigned long current_length;

  for (unsigned long i = 1; i < max_value; i++) {
    current_collatz = i;
    current_length = 1;
    while (current_collatz != 1) {
      current_length++;
      current_collatz = get_next_collatz(current_collatz);
      if (current_collatz < max_value &&
          sequence_lengths[current_collatz] != 0) {
        current_length += sequence_lengths[current_collatz];
        current_collatz = 1;
      }
    }
    sequence_lengths[i] = current_length;
    if (current_length > longest_length) {
      longest = i;
      longest_length = current_length;
    }
  }

  free(sequence_lengths);

  return longest != 837799;
}
