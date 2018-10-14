// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define PROB "2559"

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int size;
	stack<int> s;

	while(scanf("%d", &size) != EOF && size)
	{
		// int h[size], left[size]/*left idx*/, right[size]/*right idx*/;
		vector<int> h(size), left(size), right(size);
		for(int i = 0; i < size && scanf("%d", &h[i]) != EOF; i++);

		for(int i = 0; i < size; i++)
		{
			while(s.size() && h[s.top()] >= h[i])
				s.pop();

			left[i] = s.size()!=0 ? s.top()+1 : 0;

			s.push(i);
		}

		while(s.size()) s.pop(); // clear

		for(int i = size-1; i >= 0; i--)
		{
			while(s.size() && h[s.top()] >= h[i]) 
				s.pop();

			right[i] = (s.size()!=0 ? s.top()- 1 : size-1) ;

			s.push(i);
		}

		long long int maxN = LLONG_MIN;
		for(int i = 0; i < size; i++)
		{
			// printf("%-2d: %2d %2d %2d\n", i, left[i], right[i], h[i]);
			maxN = max(maxN, (long long int)(abs(right[i] - left[i]) + 1LL) * (long long int)h[i]);
		}

		printf("%I64d\n", maxN);
	}
	
	return 0;
}