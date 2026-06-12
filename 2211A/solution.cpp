#include <iostream>
#include <vector>

int main()
{
    int count;
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        int length;
        std::cin >> length;

        std::vector<int> vec;
        std::vector<int> answer;

        for (int j = 0; j < length; j++)
        {
            int num;
            std::cin >> num;
            vec.push_back(num);
        }
        if (length == 1)
        {
            std::cout << length;
        }
        else
        {
            for (int j = 0; j < vec.size(); j++)
            {
                std::cout << 2 << " ";
            }
        }
        std::cout << "\n";
    }
}