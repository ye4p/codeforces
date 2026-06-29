#include <iostream>
#include <numeric>
#include <vector>
#include <cstdint>

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        uint64_t a, b, c, m;
        std::cin >> a >> b >> c >> m;

        std::vector<uint64_t> vec = {a, b, c};
        std::vector<uint64_t> res;

        for (int i = 0; i < 3; i++)
        {
            uint64_t alice, bob, carol;
            if (i == 0)
            {
                alice = vec[0];
                bob = vec[1];
                carol = vec[2];
            }
            else if (i == 1)
            {
                alice = vec[1];
                bob = vec[0];
                carol = vec[2];
            }
            else
            {
                alice = vec[2];
                bob = vec[0];
                carol = vec[1];
            }

            uint64_t alice_days = m / alice;
            uint64_t bob_days = m / bob;
            uint64_t carol_days = m / carol;

            uint64_t alice_bob = std::lcm(alice, bob);
            uint64_t alice_carol = std::lcm(alice, carol);
            uint64_t bob_carol = std::lcm(bob, carol);

            uint64_t alice_and_bob = m / alice_bob;
            uint64_t alice_and_carol = m / alice_carol;
            uint64_t together = m / (std::lcm(alice, bob_carol));

            uint64_t total_alice = 2 * together + 3 * ((alice_and_bob - together) + (alice_and_carol - together)) + 6 * (alice_days - alice_and_carol - alice_and_bob + together);
            res.push_back(total_alice);
        }
        std::cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    }
}