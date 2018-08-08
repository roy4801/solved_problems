/*
 * Uva 119 - Greedy Gift Givers
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/119.in", "r", stdin);
    freopen("./testdata/119.out", "w", stdout);
    #endif
    int people;
    bool first = true;

    while(scanf("%d", &people) != EOF)
    {
        if(!first)
            putchar('\n');

        char tmp[13];
        char name[people][13];
        int money[people];
        std::map<std::string, int> nameToIdx;

        memset(money, 0, people * sizeof(int));

        // Read the names
        for(int i = 0; i < people; i++)
        {
            scanf("%s", &name[i]);
            nameToIdx[name[i]] = i;
        }

        // Give the presents
        for(int i = 0; i < people && scanf("%s", tmp) != EOF; i++)
        {
            // The testdata promised that they won't give a name that we can not find it
            // std::map<std::string, int>::iterator it = nameToIdx.find(tmp);
            int n = nameToIdx[tmp];
            int give, tmpMoney;
            
            scanf("%d %d", &tmpMoney, &give);

            // One might give zero present
            money[n] -= give ? (tmpMoney / give) * give : 0;

            for(int a = 0; a < give && scanf("%s", tmp) != EOF; a++)
            {
                money[nameToIdx[tmp]] += tmpMoney / give;
            }
        }

        for(int i = 0; i < people; i++)
        {
            printf("%s %d\n", name[i], money[i]);
        }

        first = false;
    }

    return 0;
}