#include <iostream>
#include <algorithm>

int main() {
    int x[3];
    std::cin >> x[0] >> x[1] >> x[2];
    std::sort(x, x+3);
    std::cout << x[1] << std::endl;
}
