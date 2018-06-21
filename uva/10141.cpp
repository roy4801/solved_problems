#include <iostream>

using namespace std;

struct provider
{
	char name[81];
	float price;
	int i;

	provider()
	{
		price = 0.f;
		i = 0;
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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("./testdata/10141.in", "r", stdin);
    freopen("./testdata/10141.out", "w", stdout);
    #endif
    int n, p;

    while(scanf("%d %d ", &n, &p) != EOF && n != 0 && p != 0)
    {
    	provider pro[p];

    	// Skip input
    	skipInput(n);

    	for(int i = 0; i < p; i++)
    	{
    		scanf("%80s", pro[i].name);
    		scanf("%f %d ", &pro[i].price, &pro[i].i);

    		skipInput(pro[i].i);
    	}

    	for(int i = 0; i < p; i++)
    	{
    		printf("%s %f %d\n", pro[i].name, pro[i].price, pro[i].i);
    	}
    	putchar('\n');
    }

    return 0;
}