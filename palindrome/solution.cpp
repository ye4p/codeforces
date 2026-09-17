#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::cin >> n;
        
        std::vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            vec.push_back(num);
        }

        std::unordered_map<int, int> m;
        for (int el : vec) {
            m[el]++;
        }

        int value = -1;
        int more = 0;
        bool t = false;

        for (const auto &[first, second] : m) {
            if (second >=3) {
                t = true;
                std::cout << "YES\n";
                break;
            }
            if (second>=2) {
                more++;
                value = first;
            }
        }

        if (t) continue;
        if (!more) {
            std::cout << "NO\n";
            continue;   
        }
        
        if (value == -1) {
            std::cout << "NO\n";
            continue;
        }

        for (int i = 0; i < vec.size(); i++) {
            if (m.find(vec[i])->second == 2) {
                if (((i <= 0) || (i > 0 && vec[i-1] != vec[i])) && ((i >= (vec.size())) || (i < (vec.size()) && vec[i+1] != vec[i]))) {
                    t = true;
                    std::cout<< "YES\n";
                    break;
                }
            }

        }

        if (t) continue;

        std::cout<< "NO\n";

    }
}
