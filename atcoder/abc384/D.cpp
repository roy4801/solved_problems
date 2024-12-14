#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> A;

bool input()
{
	if(!(cin >> n >> s))
		return 0;
	A.resize(n);
	for(int i = 0; i < n; i++)
		if(!(cin >> A[i]))
			return 0;
	return 1;
}

void solve()
{
	for(int i = 0; i < n; i++)
	{
		if(s % A[i] == 0)
		{
			s /= A[i];
		}
	}
	cout << s << '\n';
}

int main()
{
	while(input())
	{
		solve();
	}
}