/*
 * Uva 514_1 - Rails
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "514_1"
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
#define N 1000
int n;
int a[N+5]; // cars
int main()
{
	cin >> n;
	while(true)
	{
		for(int i = 0; i < n && cin >> a[i] && a[i]; i++);
		if(!a[0])
		{
			cin >> n;
			puts("");
			if(!n) break;
			continue;
		}
		//
		bool pass = true;
		stack<int> s; // 想要 stack
		int now = 1, i = 0; // 現在想要的數字, 處理到第幾個
		while(i < n)
		{
			if(a[i] == now)
			{
				now++;
				i++;
			}
			else if(!s.empty() && s.top() == a[i])
			{
				s.pop();
				i++;
			}
			else if(now <= n)
			{
				s.push(now++);
			}
			else
			{
				pass = false;
				break;
			}
		}
		// printf("%d %d\n", now, i);
		if(pass)
			puts("Yes");
		else
			puts("No");
	}
}