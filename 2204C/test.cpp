#include <iostream>

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int a, b, c, m;
        std::cin >> a >> b >> c >> m;
        int alice{};
        int bob{};
        int carol{};
        for (int i = 1; i <= m; i++)
        {
            bool is_alice = i % a ? false : true;
            bool is_bob = i % b ? false : true;
            bool is_carol = i % c ? false : true;

            int count = is_alice + is_bob + is_carol;

            if (!count)
                continue;

            if (is_alice)
                alice += 6 / count;
            if (is_bob)
                bob += 6 / count;
            if (is_carol)
                carol += 6 / count;
        }
        std::cout << alice << " " << bob << " " << carol << "\n";
    }
}