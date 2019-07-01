/*
 * UVA 11849 - CD
 * author: roy4801
 * AC(C++)
 * 0.840 unordered_set
 * 1.500 set
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11849"
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
int n, m, tmp, cnt;
unordered_set<int> cd;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n >> m && (n || m))
	{
		cnt = 0;
		cd.clear();

		for(int i = 0; i < n && cin >> tmp; i++)
			cd.insert(tmp);
		for(int i = 0; i < m && cin >> tmp; i++)
			if(cd.count(tmp))
				cnt++;

		cout << cnt << '\n';
	}

	return 0;
}