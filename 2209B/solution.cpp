#include <iostream>
#include <vector>

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::vector<int> vec;

        int values;
        std::cin >> values;
        while (values--)
        {
            int num;
            std::cin >> num;
            vec.push_back(num);
        }

        std::vector<int> res;

        for (int i = 0; i < vec.size(); i++)
        {
            int smaller = 0;
            int bigger = 0;
            for (int j = i + 1; j < vec.size(); j++)
            {
                if (vec[i] > vec[j])
                    smaller++;
                if (vec[i] < vec[j])
                    bigger++;
            }
            res.push_back(std::max(bigger, smaller));
        }

        for (int n : res)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
}