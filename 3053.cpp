#include <iostream>

double pi = 3.14159265358979323846;

void solve(int r) {
  std::cout.precision(6);
  std::cout << std::fixed << pi * r * r << std::endl;
  std::cout << std::fixed << 2 * r * r << std::endl;
}

int main() {
  int r;
  std::cin >> r;
  solve(r);
}
