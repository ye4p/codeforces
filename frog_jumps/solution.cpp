#include <iostream>
#include <vector>

int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        std::string s;
        std::cin >> s;
        int max_gap = 0;
        int gap = 0;
        bool any_left = false;
        for (char c : s) {
            if (c == 'L') {
                gap++;
            } else {
                gap = 0;
            }
            max_gap = std::max(max_gap, gap);
        }
        std::cout << (max_gap ? max_gap + 1 : 1)<< std::endl;
    }
}
