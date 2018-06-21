/*
 * Uva 10141 - Request for Proposal
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct provider
{
	char name[81];
	float price;
	int i;

	provider()
	{
		name[0] = '\0';
		price = 0.f;
		i = 0;
	}
	provider(const provider &other)
	{
		strcpy(name, other.name);
		price = other.price;
		i = other.i;
	}
	provider& operator=(const provider& rhs)
	{
		strcpy(name, rhs.name);
		price = rhs.price;
		i = rhs.i;
	}
};

void skipInput(const int times)
{
	char c;
	int count = 0;

	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			count++;

		if(count == times)
			return;
	}
}

struct compare
{
	bool operator()(const provider a, const provider b)
	{
		if(a.i > b.i)
		{
			return true;
		}
		else if(a.i == b.i)
		{
			if(a.price < b.price)
			{
				return true;
			}
		}
		return false;
	}
}providerCompare;



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("./testdata/10141.in", "r", stdin);
    freopen("./testdata/10141.out", "w", stdout);
    #endif
    int n, p;
    int now = 1;
    bool first = true;

    while(scanf("%d %d ", &n, &p) != EOF && n != 0 && p != 0)
    {
    	if(first)
    	{
    		first = false;
    	}
    	else
    	{
    		putchar('\n');
    	}

    	provider pro[p];

    	// Skip input
    	skipInput(n);

    	for(int i = 0; i < p; i++)
    	{
    		fgets(pro[i].name, 81, stdin);
    		if(pro[i].name[strlen(pro[i].name)-1] == '\n')
    			pro[i].name[strlen(pro[i].name)-1] = '\0';
    		
    		scanf("%f %d ", &pro[i].price, &pro[i].i);

    		skipInput(pro[i].i);
    	}

    	sort(pro, pro + p, providerCompare);

    	// for(int i = 0; i < p; i++)
    	// {
    	printf("RFP #%d\n", now++);
		printf("%s\n", pro[0].name);
    	// }
    }

    return 0;
}