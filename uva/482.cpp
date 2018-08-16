/*
 * Uva 482 - Permutation Arrays
 * author: roy4801
 * AC(C++) 0.000
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
        std::vector<std::pair<int, std::string> > permu;
        std::string in;

        getline(cin, in);

        std::stringstream ss(in);
        int tmp;

        while(ss >> tmp)
            permu.push_back(std::pair<int, std::string>(tmp, ""));

        for(int i = 0; i < permu.size() && cin >> permu[i].second; i++);

        std::sort(permu.begin(), permu.end(), 
            [&](std::pair<int, std::string> lhs, std::pair<int, std::string> rhs)
            {
                return lhs.first < rhs.first;
            });

        for(int i = 0; i < permu.size(); i++)
        {
            std::cout << permu[i].second << std::endl;
        }

        if(cases > 0)
        	cout << '\n';
        cin.ignore(2);
    }

    return 0;
}