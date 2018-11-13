/*
 * UVA 200 - Rare Order
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "200"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> P;
#define MP make_pair
#define F first
#define S second

#define V 26

vector<int> e[V];
int conn[V];

map<char, int> mp;
char iToc[V];
int now;
string up, down;

int n; // vertex

void addEdge(char a, char b)
{
	if(!mp.count(a))
	{
		mp.insert(MP(a, now++));
		iToc[mp[a]] = a;
	}
	if(!mp.count(b))
	{
		mp.insert(MP(b, now++));
		iToc[mp[b]] = b;
	}

	// cout << "addEdge " << a << " = " << mp[a] << ' ' << b << " = " << mp[b] << '\n';

	e[mp[a]].push_back(mp[b]);
}

string topo_sort()
{
	n = now;
	string res;

	for(int i = 0; i < n; i++)
		conn[i] = 0;

	for(int i = 0; i < n; i++)
		for(int j : e[i])
		{
			conn[j]++;
		}

	queue<int> q;
	for(int i = 0; i < n; i++)
		if(!conn[i])
			q.push(i);

	int i;
	for(i = 0; i < n; i++)
	{
		if(q.empty()) break;

		int f = q.front(); q.pop();

		// cout << "Pick " << f << '\n';

		conn[f] = -1;
		res += iToc[f];

		for(int j : e[f])
		{
			conn[j]--;
			if(!conn[j])
				q.push(j);
		}
	}

	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	string in;

Read:
	if(cin >> up)
		while(up != "#")
		{
			int i = 0, j = 0;
			if(cin >> down && down != "#")
			{
				while(i < up.size() && j < down.size())
				{
					if(up[i] != down[j])
					{
						addEdge(up[i], down[j]);
						// cout << up[i] << ' ' << down[j] << '\n';
						break;
					}
					if(i < up.size())
						i++;
					if(j < down.size())
						j++;
				}
			}
			if(down == "#")
			{
				auto res = topo_sort();
				cout << res << '\n';

				for(int i = 0; i < V; i++)
					e[i].clear();
				mp.clear();
				now = 0;
				for(int i = 0; i < V; i++)
					iToc[i] = 0;

				goto Read;
			}
			up = down;
		}
	return 0;
}