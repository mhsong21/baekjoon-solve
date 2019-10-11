#include <iostream>
#include <algorithm>

void solve(int a, int b, int c) {
  int arr[3] = { a, b, c };
  std::sort(arr, arr+3);
  if (arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) {
    std::cout << "right" << std::endl;
  } else {
    std::cout << "wrong" << std::endl;
  }
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  while (a!=0&&b!=0&&c!=0) {
    solve(a, b, c);
    std::cin >> a >> b >> c;
  }
}
