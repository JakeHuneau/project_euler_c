#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b) {
  return strcmp((const char *)a, (const char *)b);
}

int main() {
  // Data is known to be 5163 names with a max length of 11
  enum { NUM_NAMES = 5163, MAX_NAME_LENGTH = 12 };
  char names[NUM_NAMES][MAX_NAME_LENGTH] = {0};

  FILE *file = fopen("input/0022_names.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int current_ch; // use int for fgetc to detect EOF
  int name_index = 0;
  int letter_index = 0;
  while ((current_ch = fgetc(file)) != EOF) {
    if (current_ch == ',') {
      // Null terminate for C string
      names[name_index][letter_index] = '\0';
      name_index++;
      letter_index = 0;
      continue;
    }
    if (current_ch == '"' || current_ch == '\n') {
      continue; // Don't care about the quotes
    }
    names[name_index][letter_index] = current_ch;
    letter_index++;
  }
  names[name_index][letter_index] = '\0'; // Null-terminate the last name
  fclose(file);

  qsort(names, NUM_NAMES, MAX_NAME_LENGTH, compare_strings);

  unsigned long long sum = 0;

  for (int i = 0; i < NUM_NAMES; i++) {
    unsigned long long current = 0;
    for (int c = 0; c < MAX_NAME_LENGTH; c++) {
      if (names[i][c] == '\0') {
        sum += (current * (i + 1));
        break;
      }
      current += (names[i][c] - 'A' + 1);
    }
  }

  printf("%llu\n", sum);

  return 0;
}
