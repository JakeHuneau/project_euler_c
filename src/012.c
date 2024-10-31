#include "util.h"
#include <stdlib.h>

int main() {
  unsigned long long num = 1;
  unsigned long long triangle_num;
  while (1) {
    triangle_num = get_triangle_number(num);
    Factors factors = get_factors(triangle_num);
    if (factors.size > 500) {
      free(factors.array);
      break;
    }
    free(factors.array);
    num++;
  }

  return triangle_num != 76576500;
}
