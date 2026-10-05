#include <iostream>

int main() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::vector<std::vector<int>> v;
    for (size_t i = 0; i < n; i++) {
        std::vector<int> temp;
        for (size_t j = 0; j < n; j++) {
            char c;
            std::cin >> c;
            int num;
            if (c == '#') {
                num = 0;
            } else {
                num = 1;
            }

            temp.push_back(num);
        }
        v.push_back(temp);
    }

    //std::vector<std::vector<int>> vec;
    //for (size_t i = 0; i < m; i++) {
    //    std::vector<int> temp;
    //    for(size_t j = 0; j < n; j++) {
    //        temp.push_back(v[n][m]);
    //    }
    //    vec.push_back(temp);
    //}

    std::vector<int> white_cnt;
    for (size_t i = 0; i < m; i++) {
        int cnt = 0;
        for(size_t j = 0; j < n; j++) {
            if (v[n][m] == 1) {
                cnt++;
            }
        }
        vec.push_back(cnt);
    }
}
