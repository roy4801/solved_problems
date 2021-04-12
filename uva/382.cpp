/*
 * Uva 382 - Perfection
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "382"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 60000
int n;
int f[N+5];
int main()
{
    puts("PERFECTION OUTPUT");
	while(cin >> n && n)
    {
        char *s[] = {"DEFICIENT", "PERFECT", "ABUNDANT"}, *str;
        int sum = 0;
        for(int i = 1; i < n; i++)
            if(n % i == 0)
                sum += i;
        sum -= n;
        if(sum > 0)
            str = s[2];
        else if(sum < 0)
            str = s[0];
        else
            str = s[1];
        printf("%5d  %s\n", n, str);
    }
    puts("END OF OUTPUT");
}