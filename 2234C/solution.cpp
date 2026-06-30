#include <iostream>
#include <vector>

int main()
{
    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int num;
        std::cin >> num;
        std::vector<int> hs;
        while (num--)
        {
            int n;
            std::cin >> n;
            hs.push_back(n);
        }

        //
        std::vector<int> res;
        for (int i = 0; i < hs.size(); i++)
        {
            int tot{};
            int r = i;
            while (++r < hs.size())
            {
                tot += hs[r - 1];
            }
        }
    }
}