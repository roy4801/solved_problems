#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Item
{
	Item()
	{
		price = 0.f;
		good = 0;
		next = NULL;
	}
	~Item()
	{
		delete next;
	}
	char name[80];
	float price;
	int good;

	struct Item *next;
};

map<string, int> strToInt;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("./testdata/10141.in", "r", stdin);
    freopen("./testdata/10141.out", "w", stdout);
    #endif
    int n, p;

    while(scanf("%d %d", &n, &p) != EOF && n != 0 && p != 0)
    {
    	Item i[n];
    	char in[81];
    	float p;
    	int 

    	for(int i = 0; i < n; i++)
    	{
    		scanf("%s", in);

    		strToInt[in] = i;
    	}

    	for(int i = 0; i < p; i++)
    	{
    		scanf("%s", in);


    	}

    }

    return 0;
}