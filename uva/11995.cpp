/*
 * UVA 11995 - I Can Guess the Data Structure
 * author: roy4801
 * AC(C++) 0.020
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11995"
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

int flag[3]; // pq, stk, q
int n;

const char *win_s[] = {"priority queue", "stack", "queue"};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int oper, in;
	while(cin >> n)
	{
		fill(flag, flag+3, 1);
		priority_queue<int> pq;
		stack<int> stk;
		queue<int> q;

		for(int i = 0; i < n && cin >> oper >> in; i++)
		{
			if(oper == 1) // put
			{
				pq.push(in);
				stk.push(in);
				q.push(in);
			}
			else if(oper == 2)
			{
				// pq
				if(pq.empty() || pq.top() != in)
					flag[0] = 0;
				if(!pq.empty())
					pq.pop();
				// stack
				if(stk.empty() || stk.top() != in)
					flag[1] = 0;
				if(!stk.empty())
					stk.pop();
				// queue
				if(q.empty() || q.front() != in)
					flag[2] = 0;
				if(!q.empty())
					q.pop();
			}
		}

		if(flag[0] + flag[1] + flag[2] > 1)
			puts("not sure");
		else if(flag[0])
			puts("priority queue");
		else if(flag[1])
			puts("stack");
		else if(flag[2])
			puts("queue");
		else
			puts("impossible");
	}

	return 0;
}
