#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>

int solve(int min, int max) {
  bool memo[1000000];
  if (min == 1) {
    min = 2;
  }
  for (int i = 2; i*i <= max; i++) {
    if (!memo[i]) {
      for (int j = i*i; j <= max; j += i) {
        memo[j] = true;
      }
    }
  }

  std::ostringstream s;
  for (int i = min; i <= max; i++) {
    if (!memo[i]) {
      s << i << std::endl;
    }
  }
  std::cout << s.str();
  return 0;
}

int main() {
  int min, max;
  std::cin >> min;
  std::cin >> max;
  std::clock_t s = std::clock();
  solve(min, max);
  std::clock_t e = std::clock();

  std::cout << (e - s)/(1000) << std::endl;
  return 0;
}
