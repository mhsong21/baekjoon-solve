#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>

bool memo[1000000];
int memoize(int min, int max) {
  for (int i = 2; i*i <= max; i++) {
    if (!memo[i]) {
      for (int j = i*i; j <= max; j += i) {
        memo[j] = true;
      }
    }
  }
  return 0;
}

int solve(int min, int max) {
  int sum = 0;
  for (int i = min+1; i <= max; i++) {
    if (!memo[i]) {
      sum++;
    }
  }
  return sum;
}

int main() {
  int n;
  int max = -1;
  memo[1] = false;

  std::cin >> n;
  while (n != 0) {
    int two = 2*n;
    if (max < two) {
      memoize(n, two);
      max = two;
    }
    std::cout << solve(n, two) << std::endl;
    std::cin >> n;
  }
  return 0;
}
