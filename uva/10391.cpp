/*
 * Uva 10391 - Compound Words
 * author: roy4801
 * AC(C++) 0.010
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

size_t BKDRHash(const char str[])
{
    size_t seed = 131; // 31 131 1313 13131 131313 etc..
    size_t hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

inline size_t getHash(const string &s)
{
	return BKDRHash(s.c_str());
}

bool checkInHashList(vector<string> h[], const string &s, const size_t idx)
{
	size_t size = h[idx].size();
	
	if(size > 0)
	{
		for(int i = 0; i < size; i++)
			if(h[idx][i] == s)
			{
				// cout << "FOUND: " << h[idx][i] << '\n';
				return true;
			}
	}

	// cout << "NOT FOUND: " << s << '\n';
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10391.in", "r", stdin);
	freopen("./testdata/10391.out", "w", stdout);
	#endif
	USE_CPPIO();

	vector<string> l;
	string tmp;

	// Input
	while(cin >> tmp)
	{
		l.push_back(tmp);
	}

	const int size = l.size();
	vector<string> *hashed = new vector<string>[size];
	vector<string> final;

	for(string &s : l)
	{
		size_t retHash = getHash(s);
		hashed[retHash % size].push_back(s);
	}

	for(int i = 0; i < size; i++)
	{
		for(int a = 1; a <= l[i].length()-1; a++)
		{
			string sub_a = l[i].substr(0, a), sub_b = l[i].substr(0+a, l[i].length() - a);
			size_t sub_a_hash = getHash(sub_a) % size, sub_b_hash = getHash(sub_b) % size;

			if(checkInHashList(hashed, sub_a, sub_a_hash)
			&& checkInHashList(hashed, sub_b, sub_b_hash))
			{
				// cout << sub_a << ' ' << sub_b << '\n';
				// cout << sub_a_hash << ' ' << sub_b_hash << '\n';
				if(final.size() > 0 && final[final.size()-1] != l[i])
					final.push_back(l[i]);
				else if(final.size() == 0)
					final.push_back(l[i]);
			}
		}
	}

	for(string &s : final)
		cout << s << '\n';

	delete [] hashed;

	return 0;
}