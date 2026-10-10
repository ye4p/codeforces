#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

typedef uint64_t u64;

int main() {
    int tc;
    std::cin >> tc;
    std::vector<u64> ans;
    while (tc--) {
        int n, k;
        std::vector<u64> vec;

        std::cin >> n >> k;
        for (size_t i = 0; i < n; ++i) {
            u64 num;
            std::cin >> num;
            vec.push_back(num);
        }

        u64 score = 0;

        int right = k - 1;
        int left = vec.size() - k;

        while ((right + 1) <= vec.size()) {
            if (vec[right] >= vec[left]) {
                score += vec[right];
                vec.erase(vec.begin() + right);
            } else {
                score += vec[left];
                vec.erase(vec.begin() + left);
            }
            left = vec.size() - k;
        }

        // std::cout << score << "\n";
        ans.push_back(score);
    }
    for (u64 number : ans) {
        std::cout << number << "\n";
    }


}
