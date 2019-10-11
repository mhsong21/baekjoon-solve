/*
1. 둘 다 원 밖
2. 하나 만 원 밖
3. 둘 다 원 안
*/

#include <iostream>

struct p {
  int x;
  int y;
  int r;
};

struct p p_list[50];

int dist(int x, int y, struct p tmp) {
  int d = (tmp.x - x)*(tmp.x - x) + (tmp.y - y)*(tmp.y - y);
  if (d > tmp.r*tmp.r) {
    return 1;
  } else if (d == tmp.r*tmp.r) {
    std::cout << "D?D?D??D" << std::endl;
    return 0;
  } else {
    return -1;
  }
}

int solve(int x1, int y1, int x2, int y2, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    struct p tmp = p_list[i];
    int memo1 = dist(x1, y1, tmp);
    int memo2 = dist(x2, y2, tmp);

    if (memo1 * memo2 == -1) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int n;
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      int x, y, r;
      std::cin >> x >> y >> r;
      struct p tmp = { x, y, r };
      p_list[j] = tmp;
    }

    std::cout << solve(x1, y1, x2, y2, n) << std::endl;
  }
  return 0;
}
 