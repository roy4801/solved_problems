/*
 * Uva 11577 - Letter Frequency
 * author: roy4801
 * AC(C++) 0.010
 */
#include <iostream>
#include <utility>
#include <algorithm>
#include <cctype>

using namespace std;

bool alphaCompare(const pair<char, int> &lhs, const pair<char, int> &rhs)
{
    return (lhs.second > rhs.second ? true : (lhs.second == rhs.second ? lhs.first < rhs.first : false));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11577.in", "r", stdin);
    freopen("./testdata/11577.out", "w", stdout);
    #endif
    int cases;
    char c;

    scanf("%d ", &cases);

    while(cases--)
    {
        pair<char, int> alpha[26];

        while((c = getchar()) != EOF && c != '\n')
        {
            if(isalpha(c))
            {
                alpha[tolower(c) - 'a'].first = tolower(c);
                alpha[tolower(c) - 'a'].second++;
            }
        }

        sort(alpha, alpha + 26, alphaCompare);

        int num = -1, count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(num != alpha[i].second)
            {
                count++;
            }
            num = alpha[i].second;

            if(count >= 2)
                break;

            putchar(alpha[i].first);
        }
        putchar('\n');
    }

    return 0;
}