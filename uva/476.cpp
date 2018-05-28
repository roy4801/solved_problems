/*
 * Uva 476 - Points in Figures: Rectangles
 * author: roy4801
 * AC(c++) 0.000
 */
#include <iostream>

using namespace std;

struct Point
{
	float x, y;
	Point()
	{
		x = y = 0.f;
	}
};

struct Rect
{
	Point upLeft, downRight;
	Rect()
	{
	}
};

bool insideRect(Rect &r, Point &p)
{
	if( (p.x > r.upLeft.x && p.x < r.downRight.x) && (p.y < r.upLeft.y && p.y > r.downRight.y) )
	{
		return true;
	}
	else
		return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/476.in", "r", stdin);
	freopen("./testdata/476.out", "w", stdout);
	#endif
	//
	Rect r[10];
	int num_r = 0;
	char rEnd;

	rEnd = getchar();
	while(rEnd != '*' && scanf("%f %f %f %f ", &r[num_r].upLeft.x, &r[num_r].upLeft.y, &r[num_r].downRight.x, &r[num_r].downRight.y) != EOF && 
		rEnd != '*' && 
		num_r <= 10)
	{
		// printf("%f %f %f %f\n", r[num_r].upLeft.x, r[num_r].upLeft.y, r[num_r].downRight.x, r[num_r].downRight.y);
		num_r++;
		rEnd = getchar();
	}

	Point now;
	int p = 1;
	while(scanf("%f %f", &now.x, &now.y) != EOF && (now.x != 9999.9f && now.y != 9999.9f))
	{
		int notIn = 0;
		// printf("%f %f\n", now.x, now.y);

		for(int i = 0; i < num_r; i++)
		{
			if(insideRect(r[i], now))
			{
				printf("Point %d is contained in figure %d\n", p, i+1);
			}
			else
			{
				notIn++;
			}
		}
		
		if(notIn == num_r)
		{
			printf("Point %d is not contained in any figure\n", p);
		}
		p++;
	}


	return 0;
}