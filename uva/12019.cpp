/*
 * Uva 12019 - Doom's Day Algorithm
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

const int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12019.in", "r", stdin);
    freopen("./testdata/12019.out", "w", stdout);
    #endif
    int cases;
    int m, d;
    int firstDay = 5;

    scanf("%d", &cases);

    while(cases-- && scanf("%d %d", &m, &d) != EOF)
    {
        firstDay += d;

        for(int i = 0; i < m - 1; i++)
            firstDay += md[i];

        printf("%s\n", week[firstDay % 7]);
        firstDay = 5;
    }

    return 0;
}