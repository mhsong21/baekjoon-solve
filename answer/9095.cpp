/*

정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
n = 1 + n-1
n = 2 + n-2
n = 3 + n-3

*/

#include <iostream>

int solve(int n) {
  int memo[1000] = {};
  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 4;
  for (int i = 4; i <= n; i++) {
    int ans = memo[i-1] + memo[i-2] + memo[i-3];
    memo[i] = ans;
  }
  return memo[n];
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
  }

  return 0;
}
