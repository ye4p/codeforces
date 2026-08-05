#include <iostream>
#include <vector>

int main() {
    int tc;
    std::cin >> tc;
    while(tc--) 
    {
        int n, k;
        std::cin >> n >> k;
        if ((n-k)<=1)
        {
            std::cout<<"-1\n";
            continue;
        }

        std::string s;

        if ((k+2) == n) {
            for (int i= 0; i< n/2; i++) {
                s+="1";
            }
            for (int i= 0; i< (n/2 + n%2); i++) {
                s+="0";
            }
        }


        for (int i = 0; i < (k+1); i++) {
            s+="1";
        }
        int count = n - (k+1);
        int even_odd = 0;
        while (count--) {
            s += char('0'+(even_odd++ % 2));
        }
        std::cout<<s<<"\n";
        
    }
}