/*
계단 오르는 데는 다음과 같은 규칙이 있다.

계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

fn::
fn-1 -> fn-2 | fn-3 :: fn-2 -> fn-4
fn-2 -> fn-3 | fn-4 :: same

0 1 2 3 4

4 + 2
4 + 3 + 1
*/

#include <iostream>
int memo[300] = {};
int st[300] = {};
int dp(int n) {
  if (memo[n] > 0) {
    return memo[n];
  }

  int max = -1;
  int comp = st[n-1] + dp(n-3);
  if (comp > max) {
    max = comp;
  }
  comp = dp(n-2);
  if (comp > max) {
    max = comp;
  }

  int ans = st[n] + max;
  memo[n] = ans;
  return ans;
}

int solve(int n) {
  memo[0] = st[0];
  memo[1] = st[0] + st[1];
  memo[2] = std::max(st[0], st[1]) + st[2];
  int ans = dp(n);
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> st[i];
  }
  std::cout << solve(n-1) << std::endl;
  return 0;
}
