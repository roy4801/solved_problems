/*
 * Uva 458 - The Decoder
 * author: roy4801
 * AC(C++)
 */
#include <iostream>
#include <cstring>

using namespace std;

// code -7 = passwd

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("458.in", "r", stdin);
	freopen("458.out", "w", stdout);
	#endif
	char str[100];
	
	while(cin >> str)
	{
		for(int i = 0; i < strlen(str); i++)
		{
			str[i] -= 7;
		}
		cout << str << endl;
	}
	return 0;
}
