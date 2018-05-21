#include <iostream>
#include <map>
#include <vector>

using namespace std;

// AC(C++) 0.050

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11991.in", "r", stdin);
	freopen("./testdata/11991.out", "w", stdout);
	#endif
	
	int num, query; // n m
	
	while(scanf("%d %d", &num, &query) != EOF)
	{
		map<int, vector<int> > m;
		int tmp;

		for(int i = 0; i < num; i++)
		{
			scanf("%d", &tmp);

			// tmp對到的vector(每個數字不一定只有一個)存放數字的位置
			// 例如： m[3].push_back(0+1) 數字3有一個數字在1號位置
			m[tmp].push_back(i+1);
		}

		int order, number;
		for(int i = 0; i < query; i++)
		{
			scanf("%d %d", &order, &number);

			// 如果數字的數量 >= 要查的第幾個（次序） = 數字存在
			// 否則輸出 0
			printf("%d\n", m[number].size() >= order ? m[number][order-1] : 0);
		}
	}

	return 0;
}