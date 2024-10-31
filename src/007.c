#include "prime.h"

int main() {

  unsigned long prime = get_nth_prime(10001);

  return prime != 104743;
}
