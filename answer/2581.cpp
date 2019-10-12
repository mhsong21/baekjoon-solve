
#include <iostream>
#include <vector>
#include <algorithm>

int solve(int min, int max) {
  std::vector<int> memo;

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

  int sum = 0;
  int minPrime = -1;
  for (int i = 0; i < memo.size(); i++) {
    if (memo[i] >= min) {
      if (minPrime == -1) {
        minPrime = memo[i];
      }
      sum += memo[i];
    }
  }

  if (minPrime == -1) {
    std::cout << minPrime << std::endl;
  } else {
    std::cout << sum << std::endl;
    std::cout << minPrime << std::endl;
  }
  return 0;
}

int main() {
  int min, max;
  std::cin >> min;
  std::cin >> max;
  solve(min, max);
  return 0;
}
