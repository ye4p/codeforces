#include <iostream>
#include <vector>

int main()
{
    int loop{};
    std::cin >> loop;
    std::vector<int> vec;
    vec.reserve(3);
    for (int i = 0; i < loop; i++)
    {
        int num;
        std::cin >> num;
        vec.push_back(num);
    }
    for (int i = 0; i < loop; i++)
    {
        std::cout << vec[i] << "\n";
    }
    return 0;
}