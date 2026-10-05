#include <iostream>
#include <string>
#include <vector>

void yes(std::vector<std::vector<int>> &v, int i, int s1, int s2) {
    std::cout << "YES\n";
    for (size_t j = 0; j < v.size(); j++) {
        std::string s;
        for (size_t k = 0; k < 5; k++) {
            if (k == 2) {
                s+= '|';
                continue;
            }
            int hor = k;
            if (k > 2) hor = k-1;
            if (i == j && (s1 == hor || s2 == hor)) {
                s += "+";
                continue;
            }
            if (v[j][hor] == 0) {
                s+= 'O';
                continue;
            }
            if (v[j][hor] == 1) {
                s+='X';
                continue;
            }
        }
        s+='\n';
        std::cout << s;
    }
}



int main() {
    int rows;
    std::cin >> rows;
    std::vector<std::vector<int>> v;
    for (size_t i = 0; i < rows; i++) {
        std::string s;
        std::cin >> s;
        std::vector<int> temp;
        temp.push_back(s[0] =='O' ? 0 : 1);
        temp.push_back(s[1] =='O' ? 0 : 1);
        temp.push_back(s[3] =='O' ? 0 : 1);
        temp.push_back(s[4] =='O' ? 0 : 1);
        v.push_back(temp);
    }

    for (size_t i=0; i < rows; i++) {
        int s1 = 0;
        int s2 = 1;
        if (v[i][s1] == 0 && v[i][s2] == 0) {
            yes(v, i, s1, s2);
            return 0;
        }
        s1 += 2;
        s2 += 2;
        if (v[i][s1] == 0 && v[i][s2] == 0) {
            yes(v, i, s1, s2);
            return 0;
        }
    }
    std::cout << "NO";
}
