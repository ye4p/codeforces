#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <unordered_set>

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
        int left = n - k;
        std::unordered_set<int> s;

        while ((right + 1) <= n && left >= 0) {
            u64 ak = vec[right];
            bool oob = false;
            while (s.find(ak) != s.end()) {
                ++right;
                if (right >= n) {
                    oob = true;
                    break;
                }
                ak = vec[right];
            }
            u64 amk1 = vec[left];
            while (s.find(amk1) != s.end()) {
                ++left;
                if (left >= n) {
                    oob = true;
                    break;
                }
                amk1 = vec[left];
            }
            if (oob) {
                ans.push_back(score);
                break;
            }
            
            if (ak >= amk1) {
                score += ak;
                // std::cout<< "added " << ak << ", ";
                s.insert(ak);

            } else {
                score += amk1;
                // std::cout<< "added " << amk1 << ", ";
                s.insert(amk1);
                if (left > right) --right;
            }
            ++right;
            --left;
        }

        // std::cout << score << "\n";
        ans.push_back(score);
    }
    for (u64 number : ans) {
        std::cout << number << "\n";
    }


}
