#include <iostream>
#include <queue>
#include <utility>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> before;
    std::vector<int> after;

    for (size_t i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        before.push_back(num);
    }

    for (size_t i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        after.push_back(num);
    }

    std::vector<int> diff;
    for (size_t i = 0; i < n; i++) {
        diff.push_back(after[i]-before[i]);
    }
    
    int total_sum = 0;
    int items = 0;
    std::vector<size_t> indexes; // The ones he didn't buy right now
    for (size_t i = 0; i < n; i++) {
        if (diff[i] > 0) {
            ++items;
            total_sum += before[i];
        } else {
            indexes.push_back(i);
        }
    }

    if (items >= k) {
        for (size_t i : indexes) {
            total_sum += after[i];
        }
    } else {
        std::priority_queue<std::pair<int,int>> pq;
        for (size_t i = 0; i < n; i++) {
            if (diff[i] <= 0) {
                pq.push({diff[i], i});
            }
        }
        // Now we have for example: 0, -1, -2, -4 etc.
        while (items < n) {
            std::pair<int, int> top = pq.top();
            pq.pop();

            if (items < k) {
                total_sum += before[top.second];
            } else {
                total_sum += after[top.second];
            }
            ++items;
        }

    }

    std::cout << total_sum << "\n";
}   
