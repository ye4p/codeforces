#include <iostream>
#include <vector>

int main()
{
    int count;
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        int length;
        std::vector<int> vec;
        std::vector<int> answer;
        std::cin >> length;

        for (int j = 0; j < length; j++)
        {
            int num;
            std::cin >> num;
            vec.push_back(num);
        }

        std::vector<int> subvec;

        for (int k = 0; k < vec.size(); k++)
        {
            int count{};
            if (k == 0)
            {
                subvec.push_back(vec[0]);
                subvec.push_back(vec[1]);
                subvec.push_back(vec[2]);
            }
            else if ((k - 1) == vec.size())
            {
                subvec.push_back(vec[k]);
                subvec.push_back(vec[k - 1]);
                subvec.push_back(vec[k - 2]);
            }
            else
            {
                subvec.push_back(vec[k - 1]);
                subvec.push_back(vec[k]);
                subvec.push_back(vec[k + 1]);
            }
                }
    }
}