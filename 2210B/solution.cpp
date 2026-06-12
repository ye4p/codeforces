#include <iostream>
#include <vector>

int main()
{
    int test_cases;
    std::cin >> test_cases;
    std::vector<int> answer;
    for (int i = 0; i < test_cases; i++)
    {
        int chairs;
        std::cin >> chairs;
        std::vector<int> vec(chairs, 0);
        std::vector<int> permutation;
        for (int j = 0; j < chairs; j++)
        {
            int n;
            std::cin >> n;
            permutation.push_back(n);
        }
        int sat{};
        for (int j = 0; j < chairs; j++)
        {
            if (vec[j])
            {
                break;
            }
            vec[permutation[j] - 1] = 1;
            sat++;
        }
        answer.push_back(sat);
    }

    for (int a : answer)
    {
        std::cout << a << "\n";
    }
}