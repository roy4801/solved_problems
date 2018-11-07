/*
 * UVA 11997 - K Smallest Sums
 * author: roy4801
 * ref: SunTalk
 * AC(C++) 0.180
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11997"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 750

#define F first
#define S second
typedef pair<int, int> P;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int n, in;
    int one[N], two[N];
    P tmp;
    
    while(cin >> n)
    {
        for(int i = 0; i < n && cin >> in; i++)
            one[i] = in;
        sort(one, one + n);
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n && cin >> in; j++)
                two[j] = in;
            sort(two, two + n);
            
            priority_queue<P, vector<P>, greater<P> > pq; // (sum, idx)
            
            for(int j = 0; j < n; j++)
                pq.emplace(one[j] + two[0], 0);
            
            for(int j = 0; j < n; j++)
            {
                tmp = pq.top();
                pq.pop();
                one[j] = tmp.F;
                
                pq.emplace(tmp.F - two[tmp.S] + two[tmp.S+1], tmp.S+1);
            }
        }
        
        for(int i = 0; i < n; i++)
            printf(i != n-1 ? "%d " : "%d\n", one[i]);
    }

	return 0;
}