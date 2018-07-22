/*
 * Uva 12602 - Nice Licence Plates
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12602.in", "r", stdin);
	freopen("./testdata/12602.out", "w", stdout);
	#endif
	int cases;

	scanf("%d", &cases);

	while(cases--)
	{
		char ch[4];
		int right;

		scanf("%3s-%d", ch, &right);

		int chVal = (ch[0]-'A') * 26 * 26 + (ch[1]-'A') * 26 + (ch[2]-'A');

		printf("%s\n", abs(chVal - right) <= 100 ? "nice" : "not nice");
	}

	return 0;
}