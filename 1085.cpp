#include <iostream>
#include <algorithm>

int solve(int x, int y, int w, int h) {
  int candidate[4] = { w - x, x, h - y, y };
  return *std::min_element(candidate, candidate + 4);
}

int main() {
  int x, y, w, h;
  std::cin >> x >> y >> w >> h;
  int ans = solve(x, y, w, h);
  std::cout << ans << std::endl;
}