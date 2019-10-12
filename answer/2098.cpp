/*

4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0

8
0 10 15 12 13 2 3 5
6 0 9 99 1 25 56 33
10 33 0 8 93 19 28 33
8 6 8 0 10 21 11 83
6 10 15 20 0 5 9 10
6 10 15 20 5 0 9 10
6 10 15 20 9 5 0 10
6 10 15 20 11 5 9 0

0 -> 1 -> 2 -> 3 : 10 + 9 + 12 = 31
1 -> 0 -> 2 -> 3 : 5 + 15 + 12 = 32
2 -> 0 -> 1 -> 3 : 6 + 10 + 10 = 26
3 -> 0 -> 1 -> 2

f pos, mask, n

  add pos in mask
  int ans
  int ans_pos
  for i in n
    if i != pos && ! i in mask
      int cur = f i, mask, n + map[pos][i]
      if ans > cur:
        ans = cur
        ans_pos = i
      ;
    ;
  ;
  dp[pos, mask] = ans;

    // std::cout << map[pos][0] << " : " << pos  << " -> " << 0 << " , " << std::bitset<8>(mask) << std::endl;

*/
#include <bitset>


#include <iostream>
int map[16][16];
int dp[16][1 << 16];

int travel(int pos, int mask, int n) {
  if (mask == (1 << n) - 1) {
    if (map[pos][0] == 0) {
      return 1000000000;
    }
    return map[pos][0];
  }

  if (dp[pos][mask] != 0) {
    return dp[pos][mask];
  }

  int min = 1000000000;
  int cur;
  for (int i = 0; i < n; i++) {
    if (map[pos][i] == 0 || (mask & (1 << i))) {
      continue;
    }
    cur = travel(i, mask | (1 << i), n) + map[pos][i];
    if (min > cur) {
      min = cur;
    }
  }
  dp[pos][mask] = min;
  return min;
}

int solve(int n) {
  return travel(0, 1, n);
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      std::cin >> map[i][j];
    }
  }
  std::cout << solve(n) << std::endl;

  return 0;
}
