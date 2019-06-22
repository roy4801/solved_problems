/*
 * UVA 1203 - Argus
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1203"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
typedef tuple<int, int, int> Item; // (time, query_num, period)
string in;
int q, p, cur; // query_num, period, next
int n;
priority_queue<Item, vector<Item>, greater<Item>> pq;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO();
	while(cin >> in && in != "#" && cin >> q >> p)
		pq.push(make_tuple(p, q, p));

	cin >> n;
	while(n--)
	{
		tie(cur, q, p) = pq.top(); pq.pop();
		cout << q << '\n';
		pq.push(make_tuple(cur+p, q, p));
	}

	return 0;
}
