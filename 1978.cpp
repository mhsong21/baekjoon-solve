#include <iostream>

int solve(int k) {
  if (k == 1) return 0;
  for (int i = 2; i < k; i++) {
    if (k % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    ans += solve(k);
  }
  std::cout << ans << std::endl;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

int input[100];

int solve(int n) {
  std::vector<int> memo;

  int max = -1;
  for (int i = 0; i < n; i++) {
    if (input[i] > max) {
      max = input[i];
    }
  }

  for (int i = 2; i <= max; i++) {
    bool isPrime = true;
    for (int j = 0; j < memo.size(); j++) {
      if (i % memo[j] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      memo.push_back(i);
    }
  }

  int ans = 0;
  int j = 0;
  for (int i = 0; i < memo.size(); i++) {
    if (input[j] < memo[i]) {
      j++;
    }
    if (input[j] == memo[i]) {
      while (input[j] == memo[i]) {
        j++;
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < 100; i++) {
    input[i] = 999999;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> input[i];
  }
  std::sort(input, input + 100);
  std::cout << solve(n) << std::endl;
}
*/