// #include <iostream>
// #include <string>
// #include <cmath>

// int main()
// {
//     int test_cases;
//     std::cin >> test_cases;
//     while (test_cases--)
//     {
//         int length;
//         std::cin >> length;
//         std::string s;

//         std::string num;
//         std::cin >> num;
//         s += num;

//         uint64_t number = 0;
//         int i = -1;
//         for (int j = length - 1; j > -1; j--)
//         {
//             i++;
//             if (s[j] == '0')
//                 continue;
//             number += std::pow(2, i);
//         }
//         // Now converted to its actual value

//         // Create the perfect number
//         uint64_t perfect = 0;
//         i = 0;
//         for (int j = length - 1; j > -1; j--)
//         {
//             perfect += std::pow(2, i++);
//         }

//         int count = 0;
//         while (number != perfect)
//         {
//             uint64_t newNum = number;
//             if (number & 1)
//             {
//                 newNum |= (1 << (length - 1));
//             }
//             newNum |= number >> 1;
//             count++;
//             number = newNum;
//         }
//         std::cout << count << "\n";
//     }
// }

#include <iostream>
#include <string>

int main()
{
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--)
    {
        int length;
        std::cin >> length;
        std::string s;

        std::string num;
        std::cin >> num;
        s += num;
        int count = 0;
        int biggest = 0;
        for (int i = 0; i < s.length() * 2; i++)
        {
            if (s[i % s.size()] == '1')
            {
                count = 0;
                continue;
            }
            count++;
            biggest = std::max(biggest, count);
        }
        std::cout << biggest << "\n";
    }
}