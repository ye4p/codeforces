#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cstdint>

uint64_t hash(int i, int j, int k, int l) {
    uint64_t number = i*1000;
    number += j;
    number *= 1000;
    number += k;
    number *= 1000;
    number += l;
    return number;
}

int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::cin >> n;

        std::vector<int> v(n);
        for (size_t i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            v.push_back(num);
        }
        
        std::unordered_multimap<int, std::vector<int>> m;
        for (size_t i = 0; i < v.size(); ++i) {
            auto it = m.find(i);
            if (it == m.end()) {
                m.insert({v[i],{i}});
            } else {
                it->second.push_back(i);
            }
        }


        for (auto it : m) {
            if (it.second.size() < 2) {
                m.erase(it.first);
            }
        }

        // Now only elements with 2+ occurences are left.
        
        int tuples = 0;
        std::unordered_set<uint64_t> seen;
        
    }
}
