/*
 * CF 1650 A Deletions of Two Adjacent Letters
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "{pid}"
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

int main()
{
    string s, t;
	int n;
    cin >> n;
    while(n-- && cin >> s >> t)
    {
        int i = 0, j = 0;
        int cnt = 0;
        while(i < s.size() && j < t.size())
        {
            if(s[i++] == t[j] && i % 2 != 0)
                cnt++, j++;
        }
        printf("%s\n", cnt == t.size() ? "YES" : "NO");
    }
}
/*
5
abcde
c
abcde
b
x
y
aaaaaaaaaaaaaaa
a
contest
t
*/