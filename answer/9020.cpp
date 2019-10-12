#include <iostream>
#include <vector>

bool memo[1000000];
int solve(int k) {
  for (int i = 2; i*i <= k; i++) {
    if (!memo[i]) {
      for (int j = i*i; j <= k; j += i) {
        memo[j] = true;
      }
    }
  }

  std::vector<int> primes;
  for (int i = 2; i <= k; i++) {
    if (!memo[i]) {
      primes.push_back(i);
    }
  }

  int diff = 999999999;
  int ans_1 = -1;
  int ans_2 = -1;
  for (int i = 0; i < primes.size(); i++) {
    int m = primes[i];
    int n = k - m;
    if (n > m) {
      std::swap(m, n);
    }
    if (!memo[m] && !memo[n] && (m - n) < diff) {
      diff = m-n;
      ans_1 = m;
      ans_2 = n;
    }
  }
  std::cout << ans_2 << " " << ans_1 << std::endl;
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    solve(k);
  }
  return 0;
}
