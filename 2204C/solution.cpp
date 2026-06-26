#include <iostream>

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int a, b, c, m;
        std::cin >> a >> b >> c >> m;
        uint64_t alice{};
        uint64_t bob{};
        uint64_t carol{};

        int alice_days = m / alice;
        int alice_bob = alice_days / bob;
        int alce_carlo = alice_days / carol;

        std::cout
            << alice << " " << bob << " " << carol << "\n";
    }
}