#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

typedef uint64_t u64;

int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, k;
        std::vector<u64> vec;

        std::cin >> n >> k;
        for (size_t i = 0; i < n; ++i) {
            u64 num;
            std::cin >> num;
            vec.push_back(num);
        }

        u64 score = std::accumulate(vec.begin(), vec.end(), 0ULL);
        
        u64 ak = vec[k - 1];
        u64 amk1 = vec[n - k + 1];

        if (ak >= amk1) {
            
        } else {

        }

        --n;
    }
}
