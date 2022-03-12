/*
 * B - Hit and Blow
 * author: roy4801
 * AC(C++) 0.001
 */
#include <bits/stdc++.h>

using namespace std;

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

#define N 1000
int a[N+5], b[N+5];
int n;
set<int> A;
int ansA, ansB;
int main()
{
	while(cin >> n)
    {
        A.clear();
        ansA = ansB = 0;
        //
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            A.insert(a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            if(a[i] == b[i])
            {
                ansA++;
            }
            else
            {
                if(A.count(b[i]))
                    ansB++;
            }
        }
        printf("%d\n%d\n", ansA, ansB);
    }
}