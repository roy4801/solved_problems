/*
 * UVA 1610 - Party Games
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1610"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int n;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	string in;
	while(cin >> n && n)
	{
		vector<string> sl;

		for(int i = 0; i < n && cin >> in; i++)
			sl.push_back(in);
		sort(sl.begin(), sl.end());

		int fir = (sl.size()-1) / 2, sec = fir+1;
		string a = sl[fir], b = sl[sec];
		string res;

		// for(auto &i : sl)
		// 	cout << i << '\n';

		if(a.length() >= b.length())
		{
			int i = 0, j = 0;
			while(true)
			{
				if(j < b.length()-1)
				{
					if(a[i] == b[j])
						res += a[i];
					else if(a[i] < b[j])
					{
						res += a[i]+1;
						break;
					}
				}
				else/* if(j == b.length()-1)*/
				{
					if(a[i] == b[j])
					{
						res += a[i]+1;
						// cout << "exit : i=" << i << " j=" << j << '\n';
						break;
					}
					else if(a[i] == 'Z' || a[i] < b[j])
						res += a[i];
				}

				if(i == a.length()-1 && j == b.length()-1)
					break;
				if(i < a.length()-1)
					i++;
				if(j < b.length()-1)
					j++;
			}

		}
		else
		{
			cout << "-----------------------" << '\n';
			cout << a << '\n' << b << "\n\n";
			int i = 0;
			while(i < a.length() && i < b.length() && a[i] == b[i])
			{
				res += a[i];
				i++;
			}
			if(i < a.length())
				res += a[i] + 1;
		}

		cout << res << '\n';
		cout << ">> " << res << '\n';

		// cout << sl[fir] << '\n' << sl[sec] << '\n';
		cout << "-----------------------" << '\n';
	}

	return 0;
}