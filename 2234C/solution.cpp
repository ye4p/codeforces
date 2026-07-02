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
            int l = i;
            int maximum = hs[i];
            while (++r < hs.size())
            {
                tot += std::max(maximum, hs[r - 1]);
                maximum = std::max(maximum, hs[r]);
            }

            maximum = hs[i];
            while (--l >= 0)
            {
                maximum = std::max(maximum, hs[l]);
                tot += std::max(maximum, hs[l]);
            }
            res.push_back(tot);
        }

        // output
        for (int i : res)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}