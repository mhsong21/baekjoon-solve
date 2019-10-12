/*

3
26 40 83
49 60 57
13 89 99

f(n) => 
min
  input.r + f(n-1, r)
  input.g + f(n-1, g)
  input.b + f(n-1, b)


solve(n, r) => 
min
  input.g + f(n-1, g)
  input.b + f(n-1, b)

ans = min(solve(n, r), solve(n, g), solve(n, b))
*/

#include <iostream>

struct H {
  int red = 0;
  int green = 0;
  int blue = 0;
};

struct H input[1000];
int memo[3000];

int dp(int n, int color) {
  if (n == 0) {
    int ans;
    switch(color) {
      case 0: ans = std::min(input[0].green, input[0].blue); break;
      case 1: ans = std::min(input[0].red, input[0].blue); break;
      case 2: ans = std::min(input[0].red, input[0].green); break;
    };
    return ans;
  }
  if (memo[n*3 + color] > 0) {
    return memo[n*3 + color];
  }
  int ans = 0;
  if (color == 0) {
    ans = std::min(
      input[n].green + dp(n-1, 1),
      input[n].blue + dp(n-1, 2)
    );
  } else if (color == 1) {
    ans = std::min(
      input[n].red + dp(n-1, 0),
      input[n].blue + dp(n-1, 2)
    );
  } else if (color == 2) {
    ans = std::min(
      input[n].red + dp(n-1, 0),
      input[n].green + dp(n-1, 1)
    );
  }
  memo[n * 3 + color] = ans;
  return ans;
}

int solve(int n) {
  int r = dp(n, 0);
  int g = dp(n, 1);
  int b = dp(n, 2);
  return std::min(std::min(r, g), b);
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int red, green, blue;
    std::cin >> red >> green >> blue;
    struct H tmp = {red, green, blue};
    input[i] = tmp;
  }
  std::cout << solve(n-1) << std::endl;
  return 0;
}
