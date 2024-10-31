/**
 * Uses Disparate variation of Gaussian algorithm
 * w = (d + floor(2.6 m - 0.2) + y + floor(y/4) + floor(c/4) - 2c) mod 7
 * c = first 2 digits of year
 * y = last 2 digs of year
 * d = day of the month (1 - 31)
 * m = month (March = 1, ..., Feb = 12)
 * w = day of week (0 = Sunday, ..., 6 = Saturday)
 */
int day_of_week(int year, int month, int day) {
  if (month == 11 | month == 12) {
    year--;
  }
  int c = year / 100;
  int y = year % 100;
  int m = (month + 9) % 12 + 1;
  return (day + (int)(2.6 * m - 0.2) + y + (int)(y / 4) + (int)(c / 4) -
          2 * c) %
         7;
}

int main() {
  int sol = 0;
  for (int year = 1901; year < 2001; year++) {
    for (int month = 1; month < 13; month++) {
      if (day_of_week(year, month, 1) == 0) {
        sol++;
      }
    }
  }
  return sol != 171;
}
