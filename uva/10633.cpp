/*
 * Uva 10633 - Rare Easy Problem
 * author: roy4801
 * AC(C++)
 */
#include <iostream>

using namespace std;

#define DEBUG 0

int main()
{
	#if DEBUG
	freopen("10633.in", "r", stdin);
	#endif
	
	unsigned long long int input;
	while(cin >> input && input != 0)
	{
		unsigned long long int prev = input / 9 * 10 + input % 9 - 1;
		if(prev - prev / 10 == input)
			cout << prev << ' ';
		cout << input / 9 * 10 + input % 9 << endl;
	}
	return 0;
}
