#include <iostream>
#include <algorithm>

void solve(int x1, int y1, int x2, int y2, int x3, int y3) {
  int x_arr[3] = { x1, x2, x3 };
  int y_arr[3] = { y1, y2, y3 };

  std::sort(x_arr, x_arr+3);
  std::sort(y_arr, y_arr+3);
  int x = x1+x2+x3 - 2 * x_arr[1];
  int y = y1+y2+y3 - 2 * y_arr[1];
  std::cout << x << " " << y << std::endl;
}

int main() {
  int x1, x2, x3, y1, y2, y3;
  std::cin >> x1 >> y1;
  std::cin >> x2 >> y2;
  std::cin >> x3 >> y3;
  solve(x1, y1, x2, y2, x3, y3);
}