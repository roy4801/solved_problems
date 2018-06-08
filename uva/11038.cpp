/*
 * Uva 11038 - How many 0's?
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

typedef long long int int_64;

int_64 countZeros(int_64 num)
{
	// cout << "n:" << num << endl;
	int_64 count = 0LL;
	int_64 mul = 1;
	int_64 orig = num;

	while(num > 9)
	{
		if(num % 10 == 0)
		{
			/*
			 * 30324
			 *  ^
			 * num             30
			 * orig            30324
			 * mul              1000
			 * orig%(num*mul)    324
			 * num*mul         30000
			 *
			 */
			count += (num / 10LL - 1LL) * mul + (orig % (num * mul)) + 1LL; // +1 means ...0***.. (其後都是零的情況)
		}
		else
			count += (num / 10) * mul;

		mul *= 10LL;
		num /= 10LL;
	}

	return count;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11038.in", "r", stdin);
	freopen("./testdata/11038.out", "w", stdout);
	#endif
	int_64 n, m;

	while(scanf("%lld %lld", &m, &n) != EOF && n != -1 && m != -1)
	{
		int_64 answer = countZeros(n)- countZeros(m-1);

		if(m == 0)
			answer++;
		
		printf("%lld\n", answer);
	}

	return 0;
}