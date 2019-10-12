#include <iostream>

long memo[91];
long solve(long n) {
  if (memo[n] > 0) {
    return memo[n];
  }

  if (n == 0) {
    return 0;
  }
  if (n == 1 || n == 2) {
    return 1;
  }
  long ans = solve(n-1) + solve(n-2);
  memo[n] = ans;
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  long ans = solve(n);
  std::cout << ans << std::endl;
  return 0;
}
