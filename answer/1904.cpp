#include <iostream>

long memo[1000000];
long solve(long n) {
  if (memo[n] > 0) {
    return memo[n];
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }

  int ans = (solve(n-1) + solve(n-2)) % 15746;
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
