/*
 * UVA 11997 - K Smallest Sums
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11997"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Term
{
	int val, idx;
	Term(int val, int idx)
	{
		this->val = val;
		this->idx = idx;
	}
	friend bool operator>(const Term &lhs, const Term &rhs)
	{
		return lhs.val > rhs.val;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int n, in;
	bool first = true;

	while(scanf("%d", &n) != EOF)
	{
		priority_queue<Term, vector<Term>, greater<Term> > pq;
		int fir[n], sec[n];

		for(int i = 0; i < n && sacnf("%d", &fir[i]) != EOF; i++);
		for(int i = 0; i < n && scanf("%d", &sec[i]) != EOF; i++);

	}

	return 0;
}