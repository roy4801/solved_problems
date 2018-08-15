/*
 * Uva 482 - Permutation Arrays
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/482.in", "r", stdin);
    freopen("./testdata/482.out", "w", stdout);
    #endif
    int cases;

    cin >> cases;
    cin.ignore(2);

    while(cases--)
    {
        std::vector<std::pair<int, float> > permu;
        std::string in;

        getline(cin, in);

        std::stringstream ss(in);
        int tmp;

        while(ss >> tmp)
            permu.push_back(std::pair<int, float>(tmp, 0.f));

        for(int i = 0; i < permu.size() && cin >> permu[i].second; i++);

        std::sort(permu.begin(), permu.end(), 
            [&](std::pair<int, float> lhs, std::pair<int, float> lhs)
            {
                return lhs.first < rhs.first;
            });

        for(int i = 0; i < permu.size(); i++)
        {
            std::cout << permu[i].second << std::endl;
        }
    }

    return 0;
}