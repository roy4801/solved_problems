/*
 * Uva 621 - Secret Research
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <string>

using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/621.in", "r", stdin);
	freopen("./testdata/621.out", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false);

	int cases;
	std::string in; // cuz the description of the problem didn't gave us the length of str

	cin >> cases;
	cin.ignore(1, '\n');

	while(cases-- && cin >> in)
	{
		size_t len = in.length();

		if( (len == 1 && (in[0] == '1' || in[0] == '4'))
		|| (len == 2 && in[0] == '7' && in[1] == '8') )
		{
			cout << '+';
		}
		else if(len > 2)
		{
			if(in[len - 2] == '3' && in[len - 1] == '5')
			{
				cout << '-';
			}
			else if(in[0] == '1' && in[1] == '9' && in[2] == '0')
			{
				cout << '?';
			}
			else if(in[0] == '9' && in[len-1] == '4')
			{
				cout << '*';
			}
		}
		else
			cout << '?';

		cout << '\n';
	}

	return 0;
}