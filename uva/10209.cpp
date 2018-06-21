/*
 * Uva 10209 - Is This Integration ?
 * author: roy4801
 * AC(C++) 0.020
 */
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10209.in", "r", stdin);
	freopen("./testdata/10209.out", "w", stdout);
	#endif
	double side;

	while(scanf("%lf", &side) != EOF)
	{
		double square = side * side;
		double sixSector = (side * side * M_PI * 60.0 / 360.0);
		double quarterSector = (side * side * M_PI * 90.0 / 360.0);
		double regularTri = side * sqrt(pow(side, 2.0) - pow(side/2.0, 2.0)) / 2.0;
		double sickle = quarterSector - sixSector - (sixSector - regularTri);
		double plate = square - (square - quarterSector) * 2.0;
		double mid = square - 4.0 * sickle;

		printf("%.3lf %.3lf %.3lf\n", mid, (plate - mid) * 2.0, square - 2.0 * plate + mid);
	}

	return 0;
}