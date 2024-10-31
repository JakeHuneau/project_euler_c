int main() {
  // ExE grid has E+1 corners.
  // 2x2 has 9 corners
  enum { CORNERS = 21 };

  // Each grid entry is the number of ways to get to bottom right
  unsigned long long grid[CORNERS][CORNERS];
  for (int i = 0; i < CORNERS; i++) {
    for (int j = 0; j < CORNERS; j++) {
      grid[i][j] = 0;
    }
  }

  // Populate the two entrances to the end
  grid[CORNERS - 1][CORNERS - 2] = 1;
  grid[CORNERS - 2][CORNERS - 1] = 1;

  // Work backwards by counting the ways to get to a known location
  unsigned long long current_count;
  for (int row = CORNERS - 1; row >= 0; row--) {
    for (int col = CORNERS - 1; col >= 0; col--) {
      current_count = grid[row][col];
      if (col + 1 < CORNERS) {
        current_count += grid[row][col + 1];
      }
      if (row + 1 < CORNERS) {
        current_count += grid[row + 1][col];
      }
      grid[row][col] = current_count;
    }
  }

  return grid[0][0] != 137846528820;
}
