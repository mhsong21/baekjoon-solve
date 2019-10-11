/*
연속 합

n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

    std::cout << "Answer ";
    std::cout << start;
    std::cout << " ~ ";
    std::cout << end;
    std::cout << " is recorded";
    std::cout << memo[start][end];
    std::cout << std::endl;

*/
#include <iostream>

int memo[100000] = {};
int n;
int input[100000] = { 0 };

int solve() {
  int max = -100000000;

  for (int i = 0; i < n; i++) {
    int cur = input[i] + memo[i - 1];
    if (cur < input[i]) {
      cur = input[i];
    }
    memo[i] = cur;

    if (cur > max) {
      max = cur;
    }
  }

  return max;
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];
  }
  std::cout << solve() << std::endl;

  return 0;
}


/*

- Wrong
int solve(int n, int *input) {
  int max = -1001;
  int max_i = -1;
  for (int i = 0; i < n; ++i) {
    if (max < input[i]) {
      max = input[i];
      max_i = i;
    }
  }

  int answer = -1001;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    if (i < max_i) {
      for (int j = i; j <= max_i; j++) {
        sum += input[j];
      }
    } else {
      for (int j = i; j >= max_i; j--) {
        sum += input[j];
      }
    }

    if (answer < sum) {
      answer = sum;
    }
  }

  return answer;
}
*/