// Counts letters up to a thousand
int count_letters(int number) {
  // One, Two, Three, ..., nine
  int digit_counts[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
  // ten, eleven, twelve, ..., nineteen
  int teen_counts[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
  // ten, twenty, thirty, ..., ninety
  int tens_counts[] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};

  int count = 0;

  // First get all the digits
  int thousands_digit = number / 1000;
  number %= 1000;
  int hundreds_digit = number / 100;
  number %= 100;
  int tens_digit = number / 10;
  number %= 10;

  if (thousands_digit) {
    count += digit_counts[thousands_digit];
    count += 8; // Thousand
  }
  if (hundreds_digit) {
    count += digit_counts[hundreds_digit];
    count += 7; // hundred
  }
  if ((thousands_digit || hundreds_digit) && (tens_digit || number)) {
    count += 3; // and
  }
  if (tens_digit > 1) {
    count += tens_counts[tens_digit];
    count += digit_counts[number];
  } else if (tens_digit == 1) {
    count += teen_counts[number];
  } else {
    count += digit_counts[number];
  }
  return count;
}

int main() {
  unsigned int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    sum += count_letters(i);
  }
  return sum != 21124;
}
