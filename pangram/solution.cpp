#include <iostream>
#include <array>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if (n < 26) {
        std::cout << "NO";
        return 0;
    }


    std::array<int, 26> arr{};

    for (char c : s) {
        char c2 = c - 'A';
        if ((int)c2 > 25) {
            c2 -= ('a'-'A');
        }
        arr[c2]++;
    }

    for (int i : arr) {
        if (!i) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout<<"YES";
}
