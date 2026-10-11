#include <iostream>
#include <cstdint>
#include <algorithm>

#typedef uint64_t u64;

int main() {
    int tc;
    std::cin >> tc;
    
    while (tc--) {
        u64 n, x;
        std::cin >> n >> x;

        std::vector<u64> vec(n);
        for (size_t i = 0; i < n; ++i) {
            u64 temp;
            std::cin >> temp;
            vec.push_back(temp);
        }

        u64 coins = 0;
        u64 greatest_gcd = 0;
        u64 greatest_ind = 0;
        for (size_t i = 0; i < n; ++i) {
            u64 greatest = gcd(x, vec[i]);
            if (greatest > greatest_gcd) {
                greatest_gcd = greatest;
                greatest_index = i;
            }
        }
    }
}

int gcd(u64 a1, u64 a2) {
    if (a1 == a2) return a1;
    u64 minimum = std::min(a1, a2);
    u64 maximum = std::max(a1, a2);

    int biggest = 1;
    
    while (minimum > 0) {
        if (maximum % minimum != 0) {
            biggest = minimum;
            break;
        }
        --minimum;
    }

    return biggest;
}
