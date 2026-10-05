#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

static int n;

bool check(std::string &t, std::string &p, std::vector<int> &map, std::unordered_map<char, std::vector<int>> &seen) {
    //int prev = 0;
    //int p_index = 0;
    //for (size_t i = prev; i < n; i++) {
    //    if (map[i] == 0) continue;
    //    if (t[i] == p[p_index]) {
    //        p_index++;
    //        prev = i + 1;
    //        if ((p_index + 1) > p.size()) {
    //           return true;
    //        }
    //    }
    //}
    //return false;
    int prev = 0;
    int index = -1;
    for (char c : p) {
        auto it = seen.find(c);
        int i = 0;
        while (i < it->second.size()) {
            // std::cout << "ind "<< it->second[i] << " for char " << c <<" is : " << map[it->second[i]] << " and index is "<< index << std::endl;
            if (map[it->second[i]] == 1 && it->second[i] > index) {
                index = it->second[i];
                break;
            }
            ++i;
        }
        if (i == it->second.size())  {
            // std::cout << "return false for char " << c << std::endl;
            return false;
        }
    }

    return true;
}


int main() {
    std::string t;
    std::string p;

    std::cin >> t;
    std::cin >> p;

    n = t.size();

    std::vector<int> perm;
    for (size_t i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        perm.push_back(num);
    }

    std::unordered_map<char, std::vector<int>> seen;
    for (size_t i = 0; i < n; ++i) {
        auto it = seen.find(t[i]);
        if (it == seen.end()) { // didn't find
            std::vector<int> temp;
            temp.push_back(i);
            seen.insert({t[i], temp});
        } else {
            it->second.push_back(i);
        }
    } 

    std::vector<int> map(n, 1);

    int removed = 0;
    for (size_t i = 0; i < n; ++i) {
        //perm[i] // need to remove this one
        map[perm[i]-1] = 0;

        // need to check if can read the word p from word t
        bool res = check(t, p, map, seen);
        if (!res) {
            break;
        }
        ++removed;
    }

    std::cout << removed << "\n";
}
