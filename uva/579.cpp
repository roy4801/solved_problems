/*
 * Uva 579 - Clock Hands
 * author: roy4801
 * AC(c++) 0.010
 */
#include <iostream>
#include <cmath>

using namespace std;

// 1 hr = 5 min_block
// 12 hr = 60 min_block
// 1 min_block = 6 degree 
//
// 1 min = 6 d (for min)
// 1 min for hr = 30 / 60 degree = 0.5 degree

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/579.in", "r", stdin);
	freopen("./testdata/579.out", "w", stdout);
	#endif
	int h, m;

	while(scanf("%d:%d", &h, &m) != EOF && (h != 0 || m != 0))
	{
		float a = abs((float)h * 30.f + (float)m * 0.5f - (float)m * 6);
		float b = 360.f - a;
		
		printf("%.3f\n", a > b ? b : a);
	}

	return 0;
}