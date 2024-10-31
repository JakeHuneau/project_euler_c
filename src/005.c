int main() {
  unsigned long long solution = 2;

  while (1) {
    int solved = 1;
    for (int i = 2; i <= 20; i++) {
      if (solution % i != 0) {
        solved = 0;
        break;
      }
    }
    if (solved) {
      break;
    }
    solution += 2;
  }

  return solution != 232792560;
}
