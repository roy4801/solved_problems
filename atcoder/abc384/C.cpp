#include <bits/stdc++.h>
using namespace std;

using P = pair<int, string>;
int sc[5];

bool input()
{
	for(int i = 0; i < 5; i++)
		if(!(cin >> sc[i]))
			return 0;
	return 1;
}

int main()
{
	while(input())
	{
		vector<P> v;
		int up = pow(2,5)-1;
		for(int i = 0; i <= up; i++)
		{
			bitset<5> flag(i);
			string s;
			int score = 0;
			for(int i = 0; i < 5; i++)
			{
				if(flag[i])
				{
					score += sc[i];
					s += "ABCDE"[i];
				}
			}
			v.emplace_back(score, s);
		}
		
		sort(v.begin(), v.end(), [](P& lhs, P& rhs) {
			return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first;
		});
		
		for(auto [score, s] : v)
			cout << s << '\n'; // score << ' '
	}
}