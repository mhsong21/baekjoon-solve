#include <iostream>
#include <sstream>

std::string solve(int x, int y) {
    std::ostringstream os;
    if (y >= 45) {
        os << x << " " << (y - 45);
    } else if (x == 0) {
        os << 23 << " " << y + 15;
    } else {
        os << x - 1 << " " << y + 15;
    }
    return os.str();
}

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << solve(x, y) << std::endl;
    return 0;
}
