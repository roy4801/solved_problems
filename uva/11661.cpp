/*
 * Uva 11661 - Burger Time?
 * author: roy4801
 * AC(C++) 0.070
 */
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11661.in", "r", stdin);
    freopen("./testdata/11661.out", "w", stdout);
    #endif
    int len;

    while(scanf("%d ", &len) != EOF && len)
    {
        vector<int> r, d;
        char c;
        int pos = 0;

        while((c = getchar()) != '\n')
        {
            switch(c)
            {
                case 'R':
                    r.push_back(pos);
                break;

                case 'D':
                    d.push_back(pos);
                break;

                case 'Z':
                    r.push_back(pos);
                    d.push_back(pos);
                break;
            }
            pos++;
        }

        int min = 2000001;
        for(int i = 0; i < r.size(); i++)
        {
            for(int j = 0; j < d.size(); j++)
            {
                if(min > abs(r[i] - d[j]))
                    min = abs(r[i] - d[j]);
            }
        }

        printf("%d\n", min);
    }

    return 0;
}