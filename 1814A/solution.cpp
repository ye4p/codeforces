#include <iostream>

int main() {
    int tc;
    std::cin << tc;
    while (tc--) {
        int n, k;
        std::cin >> n >> k;
        if (((n % k) % 2) == 0) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}
