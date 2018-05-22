#include <iostream>

using namespace std;

// [ ]餘數定理

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10127.in", "r", stdin);
	#endif
	int cases;
	int n;

	while(scanf("%d", &n) != EOF)
	{
		int tmp = 1, ans = 1;
		while(tmp % n)
		{
			tmp %= n;
			tmp *= 10;
			tmp += 1;
			ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}