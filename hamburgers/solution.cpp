#include <iostream>
#include <cstdint>
#include <vector>
#include <limits>

typedef int64_t u64;

void update_remainder(std::vector<int64_t> &remainder, std::vector<int64_t> &recipe) {
    for (size_t i = 0; i < 3; ++i) {
        remainder[i] -= recipe[i];
    }
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<u64> amnt;

    for (size_t i = 0; i < 3; ++i) {
        u64 n;
        std::cin >> n;
        amnt.push_back(n);
    }

    std::vector<u64> prices;

    for (size_t i = 0; i < 3; ++i) {
        u64 p;
        std::cin >> p;
        prices.push_back(p);
    }

    u64 r;
    std::cin >> r;

    std::vector<int64_t> recipe(3, 0);

    for (char c : s) {
        if (c == 'B') recipe[0]++;
        else if (c == 'S') recipe[1]++;
        else recipe[2]++;
    }

    int64_t burger_total_price = 0;
    for (size_t i = 0; i < 3; ++i) {
        burger_total_price += recipe[i] * prices[i];
    }

    int64_t max_burgers = INT64_MAX;

    for (size_t i = 0; i < 3; ++i) {
        int64_t b = recipe[i] ? (amnt[i] / recipe[i]) : INT64_MAX;
        max_burgers = std::min(b, max_burgers);
    }
    
    std::vector<int64_t> remainder;
    for (size_t i = 0; i < 3; ++i) {
        int64_t rem = amnt[i] - (max_burgers * recipe[i]);
        remainder.push_back(rem);
    }  
    
    bool have_money = true;

    // for (size_t time = 0; time < 3; ++time) {
    while (true) {
        int64_t total_price = 0;

        for (size_t i = 0; i < 3; ++i) {
            int64_t to_buy = recipe[i] - remainder[i];
            if (to_buy > 0) {
                total_price += to_buy * prices[i];
                remainder[i] += to_buy;
            }
        }

        update_remainder(remainder, recipe);

        r -= total_price;
        if (r < 0) {
            have_money = false;
            break;
        }
        ++max_burgers;
        if (total_price == burger_total_price) {
            break;
        }
    }

    if (!have_money) {
        std::cout << max_burgers;
        return 0;
    } 
    
    // Now, it has to be aligned, meaning you should have zero of everything, so now you can easily calculate the remaining amount of burgers that you can buy.
    int64_t price = 0;
    for (size_t i = 0; i < 3; ++i) {
        price += recipe[i] * prices[i];
    }
    max_burgers += r / price;

    std::cout << max_burgers;
}
