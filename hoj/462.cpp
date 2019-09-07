/*
 * HOJ 462 - 失落的維京戰機
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "462"
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
int kase;
string in;
int tmp, ans;
char c;
bool md; // mul or div flag
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> in)
	{
		deque<int> num;
		deque<char> opt;
		for(auto c : in)
		{
			if(isdigit(c))
			{
				if(md)
				{
					if(opt.back() == '*')
						tmp = num.back() * (c-'0');
					else if(opt.back() == '/')
						tmp = num.back() / (c-'0');
					opt.pop_back();
					num.pop_back();
					num.PB(tmp);
					tmp = 0;
					md = false;
				}
				else
					num.PB(c-'0');
			}
			else
			{
				if(c == '*' || c == '/')
					md = true;
				opt.PB(c);
			}
		}
		ans = num.front(); num.pop_front();
		while(!opt.empty())
		{
			c = opt.front(); opt.pop_front();
			if(c == '+')
				ans += num.front();
			else if(c == '-')
				ans -= num.front();
			num.pop_front();
		}
		cout << ans << '\n';
	}
	return 0;
}
