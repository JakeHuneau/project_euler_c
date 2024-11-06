// Use this for tracking if we had a value we already hit
typedef struct {
  int quotient;
  int remainder;
} DivisionResult;

int main() {
  enum { MAX = 1000 };
  int solution = 0;
  int longest_loop = 0;
  for (int d = 1; d < 1000; d++) {
    DivisionResult divisions[MAX];
    int numerator = 10;
    int denominator = d;
    int remainder;
    int quotient;
    int loop_length = 0;
    for (int i = 0; i < MAX && loop_length == 0; i++) {
      remainder = numerator % denominator;
      quotient = numerator / denominator;
      divisions[i].quotient = quotient;
      divisions[i].remainder = remainder;
      // Check if we've already seen this value. If so, we've hit a loop
      for (int j = 0; j < i; j++) {
        if (divisions[j].remainder == divisions[i].remainder &&
            divisions[j].quotient == divisions[i].quotient) {
          // Gotta check where the loop started
          loop_length = i - j + 1;
          if (loop_length > longest_loop) {
            longest_loop = loop_length;
            solution = d;
          }
          break;
        }
      }
      numerator = remainder * 10;
      if (remainder == 0) {
        break;
      }
    }
  }

  return solution != 983;
}
