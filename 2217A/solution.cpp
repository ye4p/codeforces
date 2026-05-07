#include <iostream>
#include <string>

int handleArray(int n)
{
    int sum{};
    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        sum += number;
    }
    return sum;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;
    std::string response = "";
    for (int test = 0; test < test_cases; test++)
    {
        int n, k;
        std::cin >> n >> k;
        int sum = handleArray(n);

        if (
            (((sum % 2) == 0) && (((n * k) % 2) == 0)) ||
            (((sum % 2) == 1) && (((n * k) % 2) == 1)) ||
            (((sum % 2) == 1) && (((n * k) % 2) == 0)))
        {
            response += "yes\n";
        }
        else
        {
            response += "no\n";
        }
    }
    std::cout << response;
    return 0;
}
