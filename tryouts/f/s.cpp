#include <iostream>
#include <cstdint>
#include <vector>

typedef uint64_t u64;

int main() {
    uint64_t n;
    std::cin >> n;

    std::vector<uint64_t> v;
    uint64_t total = 0;
    for (size_t i = 0; i < n; i++) {
        uint64_t num;
        std::cin >> num;
        total += num;
        v.push_back(num);
    }

    if (n <= 1) {
        std::cout << 0;
        return 0;
    }

    u64 nmax = 0;
    for (size_t i = 0; i < n; i++) {
        nmax =  std::max(nmax, v[i]); 
    }

    u64 cnt = 0;
    for (uint64_t number : v) {
        if (number == nmax) cnt++;
    }

    u64 avg = total / v.size();
    u64 cnt_new = 0;
    for (uint64_t number : v) {
        if (number > avg) cnt_new++;
    }
    std::cout << cnt_new;
    
}
