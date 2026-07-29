#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int num;
        std::cin >> num;
        std::vector<int> hs;
        while (num--)
        {
            int n;
            std::cin >> n;
            hs.push_back(n);
        }

        //
        std::vector<int> res;
        for (int i = 0; i < hs.size(); i++)
        {
            std::vector<int> intermediate(hs.size(), 0);

            // At first we do pass to the left
            int index = i-1;
            int max=0;
            while (index >= 0) {
                max = std::max(max, hs[index]);
                intermediate[index] = max;

                index--;
            }

            // We reached the left bound, now need to wrap and continue iteration until that i value.
            index = hs.size()-1;
            while (index > i) {
                max = std::max(max, hs[index]);
                intermediate[index]=max;

                index--;
            }

            // std::cout<<"intermediate:\n";
            // for (int number : intermediate) {
            //     std::cout<< number << ", ";
            // }
            // std::cout<<"\n";

            // Now after we have intermediate values, we need to iterate to the right to finalize them.
            max = hs[i];
            index = i + 1;
            while (index < hs.size()) {
                if (intermediate[index] > max) intermediate[index]=max;
                max = std::max(hs[index], max);

                index++;
            }

            index = 0;
            while (index < i) {
                if (intermediate[index] > max) intermediate[index]=max;
                max = std::max(hs[index], max);

                index++;
            }

            // std::cout<<"final:\n";
            // for (int number : intermediate) {
            //     std::cout<< number << ", ";
            // }
            // std::cout<<"\n";
            
            int sum = std::accumulate(intermediate.begin(), intermediate.end(), 0);
            res.push_back(sum);

        }

        
        // output
        for (int i : res)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}