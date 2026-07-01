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
            int maximum = hs[i];
            while (++r < hs.size())
            {
                tot += std::max(maximum, hs[r - 1]);
                maximum = std::max(maximum, hs[r]);
            }
            r = 0;
            while (++r <= i)
            {
                int l = r - 1;
                if (r == 1)
                {
                    l = hs.size() - 1;
                }
                tot += hs[l];
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