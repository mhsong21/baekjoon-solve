/*
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
*/

#include <iostream>

int solve(int n) {
  if (n == 1) {
    return 9;
  }
  int memo[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  int curr[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  for (int i = 1; i < n; i++) {
    for (int d = 0; d < 10; d++) {
      if (d == 0) {
        curr[0] = memo[1];
      } else if (d == 9) {
        curr[9] = memo[8];
      } else {
        curr[d] = (memo[d + 1] + memo[d - 1]) % 1000000000;
      }
    }
    for (int d = 0; d < 10; d++) {
      memo[d] = curr[d];
    }
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans += memo[i];
    ans %= 1000000000;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;

  return 0;
}
