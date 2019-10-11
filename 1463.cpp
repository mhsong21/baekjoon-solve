/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

fx = 
if /3 -> f(x/3)
else if /2 -> f(x/2)
else -> f(x-1)

*/
#include <iostream>

int memo[1000001] = { 0 };

int solve(int n) {
  int candidates[3] = { 10000, 10000, 10000 };

  if (n == 1) {
    return 0;
  }

  if (memo[n] > 0) {
    return memo[n];
  }

  if (n % 3 == 0) {
    candidates[0] = memo[n/3];
  }
  if (n % 2 == 0) {
    candidates[1] = memo[n/2];
  }
  candidates[2] = memo[n-1];

  int answer = std::min(std::min(candidates[0], candidates[1]), candidates[2]) + 1;
  memo[n] = answer;
  return answer;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  std::cout << memo[n] << std::endl;
  return 0;
}
