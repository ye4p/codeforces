#include <iostream>
#include <queue>
#include <utility>
#include <cstdint>

int main() {
    int n;
    std::cin >> n;

    std::vector<uint64_t> v;

    for (size_t i = 0; i < n; i++) {
        uint64_t tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::priority_queue<std::pair<uint64_t, int>> pq_front;
    
    uint64_t sum_front = 0;
    for (size_t i = 0; i < (n-1); i++) {
        sum_front += v[i];

        pq_front.push({sum_front, i});
    }
    
    uint64_t sum_back = 0;
    std::priority_queue<std::pair<uint64_t, int>> pq_back;
    for (size_t i = (n - 1); i > 0; i--) {
        sum_back += v[i];
        
        pq_back.push({sum_back, i});
    }


    
    while (true) {
        if (pq_front.empty() || pq_back.empty()) {
            // std::cout << "empty containers\n";
            break;
        }
        std::pair<uint64_t, int> front = pq_front.top();
        std::pair<uint64_t, int> back = pq_back.top();
        // std::cout << "pairs of " << front.first << " and " << back.first << std::endl;

        if (front.first == back.first) {
            if (front.second >= back.second) {
                // std::cout << front.second << std::endl;
                // std::cout << back.second << std::endl;
                pq_front.pop();
                pq_back.pop();
                continue;
            }
            std::cout << front.first;
            return 0;
        }

        if (front.first < back.first) {
            pq_back.pop();
            continue;
        }

        if (front.first > back.first) {
            pq_front.pop();
            continue;
        }
    }
    std::cout << 0 << "\n";

}
