#include <iostream>
#include <vector>

int main() {
    int tc;
    std::cin >> tc;
    while(tc--) 
    {
        int len;
        std::cin >> len;

        std::vector<int> a(len);
        std::vector<int> b(len);

        for (int i = 0; i < len; i++) {
            int n;
            std::cin>>n;
            a.push_back(n);
        }
        for (int i = 0; i < len; i++) {
            int n;
            std::cin>>n;
            b.push_back(n);
        }

        // testing


        // output
        
    }
}