/*
 * Uva 10696 - f91
 * author: roy4801
 * AC(C++)  0.090
 */
#include <iostream>

using namespace std;

int f91(const int n)
{
    if(n <= 100)
    {
        return f91(f91(n + 11));
    }
    else if (n > 100)
    {
        return n - 10;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10696.in", "r", stdin);
    freopen("./testdata/10696.out", "w", stdout);
    #endif
    int num;

    while(scanf("%d", &num) != EOF && num)
    {
        printf("f91(%d) = %d\n", num, f91(num));
    }

    return 0;
}
