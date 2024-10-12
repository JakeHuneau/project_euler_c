// util.h
#ifndef UTIL_H
#define UTIL_H

int is_even(int);
unsigned long long get_triangle_number(unsigned long);
typedef struct {
  unsigned long *array;
  int size;
} Factors;
Factors get_factors(unsigned long num);
unsigned long long get_next_collatz(unsigned long long);

#endif
