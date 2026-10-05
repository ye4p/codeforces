#include <iostream>
#include <vector>
#include <utility>

int main() {
    int n, m;

    std::cin >> n >> m;

    std::vector<int> v;

    std::vector<std::pair<int, int>> v2;

    for (size_t i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        v.push_back(num);
    }


    for (size_t i = 0; i < (n-1); i++) {
        int x, y;
        std::cin >> x >> y;
        v2.push_back({x, y});
    }

    int paths = _;
    if (v[0]) --paths;
    

}
