#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n;
	char a, b;
	string s;
	while(cin >> n >> a >> b >> s)
	{
		for(int i = 0; i < n; i++)
			if(s[i] != a)
				s[i] = b;
		cout << s << '\n';
	}
}