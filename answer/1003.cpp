// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n‐1) + fibonacci(n‐2);
//     }
// }

#include <iostream>
#include <utility>

std::pair<int, int> memo[40];
std::pair<int, int> solve(int n) {
  if (memo[n].first + memo[n].second > 0) {
    return memo[n];
  }

  if (n == 0) {
    return std::make_pair(1, 0);
  }
  if (n == 1) {
    return std::make_pair(0, 1);
  }
  auto one = solve(n-1);
  auto two = solve(n-2);
  auto ans = std::make_pair(one.first + two.first, one.second + two.second);
  memo[n] = ans;
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    std::pair<int, int> ans = solve(k);
    for (int j = 0; j < k; j++) {
      std::cout << memo[j].first << " " << memo[j].second << std::endl;
    }
  }
  return 0;
}
