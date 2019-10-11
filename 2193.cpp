/*
1111

n-1에 대해서
0 -> fn-2
1 -> 0 -> f(n-3)
*/
#include <iostream>

int memo[90] = {};

int solve(int n) {
  if (n == 0) {
    return 2;
  }
  if (n == 1) {
    return 3;
  }
  if (memo[n] > 0) {
    return memo[n];
  }

  int ans = solve(n-1) + solve(n-2);
  memo[n] = ans;
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  if (n == 1 || n == 2) {
    std::cout << 1 << std::endl;
    return 0;
  }
  if (n == 3) {
    std::cout << 2 << std::endl;
    return 0;
  }
  std::cout << solve(n-3) << std::endl;
  return 0;
}
