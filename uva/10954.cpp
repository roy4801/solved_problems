/*
 * UVA 10954 - Add All
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10954"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
int n, tmp, ans;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n && n)
	{
		while(!pq.empty()) pq.pop();
		ans = 0;

		for(int i = 0; i < n && cin >> tmp; i++)
			pq.push(tmp);

		while(pq.size() >= 2)
		{
			tmp = 0;
			tmp += pq.top(); pq.pop();
			tmp += pq.top(); pq.pop();
			ans += tmp;
			pq.push(tmp);
		}
		cout << ans << '\n';
	}
	return 0;
}
