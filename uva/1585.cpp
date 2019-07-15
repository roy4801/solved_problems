/*
 * UVA 1585 - Score
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1585"
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
int n, sc, now;
string s;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> n;
	while(n-- && cin >> s)
	{
		sc = 0;
		now = 1;

		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == 'O')
			{
				sc += now;
				now++;
			}
			else
				now = 1;
		}
		cout << sc << '\n';
	}

	return 0;
}