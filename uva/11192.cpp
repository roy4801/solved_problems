/*
 * Uva 11192 - Group Reverse
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11192"
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
int n;
string s;
int main()
{
	while(cin >> n >> s)
	{
		int num = s.size() / n;
		for(int i = 0; i < s.size();)
		{
			reverse(s.begin()+i, s.begin()+i+num);
			i += num;
		}
		cout << s << '\n';
	}
}