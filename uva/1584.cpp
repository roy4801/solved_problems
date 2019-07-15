/*
 * UVA 1584 - Circular Sequence
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1584"
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
int n;
string s, mins, tmp;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> n;
	while(n-- && cin >> s)
	{
		mins = s;
		for(int i = 1; i < s.size(); i++)
		{
			tmp = s.substr(i, s.size()-i) + s.substr(0, i);
			mins = min(mins, tmp);
		}
		cout << mins << '\n';
	}

	return 0;
}