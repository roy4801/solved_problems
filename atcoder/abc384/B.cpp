#include <bits/stdc++.h>
using namespace std;

int ok(int div, int r)
{
	if(div == 1 && 1600 <= r && r <= 2799)
		return 1;
	if(div == 2 && 1200 <= r && r <= 2399)
		return 1;
	return 0;
}

int main()
{
	int n, r;
	while(cin >> n >> r)
	{
		int d, a;
		for(int i = 0; i < n; i++)
		{
			cin >> d >> a;
			if(ok(d, r))
			{
				r += a;
			}
		}
		cout << r << '\n';
	}
}