/*
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

*/
#include <iostream>

int solve(int x1, int y1, int r1, int x2, int y2, int r2) {
  if (x1 == x2 && y1 == y2) {
    if (r1 == r2) return -1;
    return 0;
  }

  int d1 = (y2 - y1)*(y2 - y1) + (x2-x1)*(x2-x1);
  int d2 = (r2 + r1)*(r2 + r1);
  int d3 = (r2 - r1)*(r2 - r1);

  if (d1 > d3 && d1 < d2) return 2;
  else if (d1 == d2 || d1 == d3) return 1;
  else return 0;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    std::cout << solve(x1, y1, r1, x2, y2, r2) << std::endl;
  }
  return 0;
}
