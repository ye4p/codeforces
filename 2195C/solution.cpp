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
        std::vector<int> vec;
        for (int i = 0; i < num; i++)
        {
            int n;
            std::cin >> n;
            vec.push_back(n);
        }

        // need to determine whether something is dice roll sequence or no
        // Therefore, need to only check neighbours of the sequence to see if they are adjacent.
        // Check if next number is equals to current number or if next number equals to 7 - x of current number

        int cnt = 0;
        int sqn = 0;
        for (int i = 0; i < (vec.size() - 1); i++)
        {
            if (vec[i] == vec[i + 1] || (7 - vec[i]) == vec[i + 1])
            {
                cnt++;
                sqn++;
            }
            else
            {
                sqn = 0;
            }
            if (sqn == 2)
            {
                cnt--;
                sqn = 0;
            }
        }
        std::cout << cnt << "\n";
    }
}