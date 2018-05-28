/*
 * Uva 477 - Points in Figures: Rectangles and Circles
 * author: roy4801
 * AC(c++) 0.000
 */
#include <iostream>
#include <cmath>

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
	int id;
	Rect()
	{
		id = -1;
	}
};

struct Cir
{
	Point orig;
	float radius;
	int id;
	Cir()
	{
		radius = 0.f;
		id = -1;
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

bool insideCir(Cir &c, Point &p)
{
	if( (float)pow(p.x + (-c.orig.x), 2) + (float)pow(p.y + (-c.orig.y), 2) < (float)pow(c.radius, 2))
	{
		return true;
	}
	else
		return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/477.in", "r", stdin);
	freopen("./testdata/477.out", "w", stdout);
	#endif
	//
	Rect r[10];
	Cir c[10];

	int total = 1;
	int num_r = 0;
	int num_c = 0;
	char rEnd;

	// Input
	while( (rEnd = getchar()) != EOF && rEnd != '*' )
	{
		// printf("%c\n", rEnd);

		switch(rEnd)
		{
			case 'r':
				if(num_r <= 10)
				{
					scanf("%f %f %f %f ", &r[num_r].upLeft.x, &r[num_r].upLeft.y, &r[num_r].downRight.x, &r[num_r].downRight.y);
					// printf("%f %f %f %f\n", r[num_r].upLeft.x, r[num_r].upLeft.y, r[num_r].downRight.x, r[num_r].downRight.y);
					r[num_r].id = total++;
					num_r++;
				}
			break;

			case 'c':
				if(num_c <= 10)
				{
					scanf("%f %f %f ", &c[num_c].orig.x, &c[num_c].orig.y, &c[num_c].radius);
					// printf("%f %f %f\n", c[num_c].orig.x, c[num_c].orig.y, c[num_c].radius);
					c[num_c].id = total++;
					num_c++;
				}
			break;
		}
	}

	// Judge
	Point now;
	int p = 1;
	while(scanf("%f %f", &now.x, &now.y) != EOF && (now.x != 9999.9f && now.y != 9999.9f))
	{
		int notIn = 0;
		// printf("%f %f\n", now.x, now.y);
		// Judge Rect
		for(int i = 0; i < num_r; i++)
		{
			if(insideRect(r[i], now))
			{
				printf("Point %d is contained in figure %d\n", p, r[i].id);
			}
			else
			{
				notIn++;
			}
		}
		// Judge Circle
		for(int i = 0; i < num_c; i++)
		{
			if(insideCir(c[i], now))
			{
				printf("Point %d is contained in figure %d\n", p, c[i].id);
			}
			else
			{
				notIn++;
			}
		}
		
		if(notIn == num_r + num_c)
		{
			printf("Point %d is not contained in any figure\n", p);
		}
		p++;
	}

	return 0;
}