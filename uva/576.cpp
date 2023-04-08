/*
 * Uva 576 - Hiaku Review
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "576"
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

bool check(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
    string s;
	while(getline(cin, s))
    {
        if(s == "e/o/i")
            break;

        string tmp;
        stringstream ss(s);
        int ans[] = {5, 7, 5};
        int idx = 0;
        bool fail = false;
        while(getline(ss, tmp, '/'))
        {
            int n = 0;
            for(int i = 0; i < tmp.size(); i++)
            {
                if(check(tmp[i]))
                {
                    if(i >= 1 && check(tmp[i-1]))
                    {
                        continue;
                    }
                    n++;
                }
            }
            if(ans[idx++] != n)
            {
                printf("%d\n", idx);
                fail = true;
                break;
            }
        }

        if(idx == 3 && !fail)
        {
            puts("Y");
        }
    }
}