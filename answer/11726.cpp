#include <iostream>

int memo[1000] = {};

int solve(int n) {
  if (memo[n] > 0) {
    return memo[n];
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }

  int ans = (solve(n-1) + solve(n-2)) % 10007;
  memo[n] = ans;
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;

  for (int i = 0; i < n; i++) {
    std::cout << memo[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}
