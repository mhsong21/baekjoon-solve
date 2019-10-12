#include <iostream>

long memo[100];
long solve(long n) {
  if (memo[n] > 0) {
    return memo[n];
  }
  if (n == 1 || n == 2 || n == 3) {
    return 1;
  }
  if (n == 4 || n == 5) {
    return 2;
  }

  long ans = solve(n-1) + solve(n-5);
  memo[n] = ans;
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    long ans = solve(k);
    std::cout << ans << std::endl;
  }
  return 0;
}
