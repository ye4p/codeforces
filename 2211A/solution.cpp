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
        std::cin >> length;

        for (int j = 0; j < length; j++)
        {
            int num;
            std::cin >> num;
            vec.push_back(num);
                }
    }
}