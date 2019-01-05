/*
 * UVA 1210 - Sum of Consecutive Prime Numbers
 * author: roy4801
 * AC(C++) 0.170
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1210"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define P 11000
#define N 7000000

int ans[N];

int lim;

vector<int> prime;
bool p[P+5];
void era()
{
	for(int i = 0; i <= P; i++)
		p[i] = true;
	p[0] = p[1] = false;
	for(int i = 2; i <= P; i++)
	{
		if(p[i])
		{
			prime.push_back(i);
			ans[i]++;
			for(int j = i*2; j <= P; j += i)
				p[j] = false;
		}
	}

	lim = prime.size();
}

void build()
{
	for(int i = 2; i <= lim; i++) // num of group
	{
		for(int j = 0; j < lim; j++) // start pos
		{
			int sum = 0;
			if(j+i > lim)
				break;

			for(int l = 0; l < i; l++) // times
			{
				sum += prime[j+l];
			}
			ans[sum]++;
			// cout << sum << '\n';
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	era();
	build();

	int in;
	while(cin >> in && in)
		cout << ans[in] << '\n';
	// cout << prime.back() << '\n';
	// int sum = 0;
	// for(auto i : prime)
	// 	sum += i;
	// cout << sum << '\n';


	return 0;
}