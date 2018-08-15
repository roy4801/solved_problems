/*
 * Uva 893 - Y3K Problem
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>

using namespace std;

int calcLeapYear(const int y)
{
	return (y / 4 - y /100 + y / 400);
}

bool isLeapYear(const int y)
{
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int dayLimit(const int month, const int year)
{
	static const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return isLeapYear(year) && month == 2 ? d[1] + 1 : d[month - 1];
}

// void ifNextYear(int &y, int &m, int &d)
// {
// 	if(d > dayLimit(m, y))
// 	{
// 		d -= dayLimit(m, y);
// 		m++;
// 	}

// 	if(m > 12)
// 	{
// 		y++;
// 		m -= 12;
// 	}
// }

int baseday(int D, int M, int Y)
{
	static int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	int sum = D;
	for (int i = 0; i < Y; ++ i)
		if ((i%4 == 0 && i%100 != 0) || i%400 == 0)
			sum += 366;
		else sum += 365;
	for (int i = 0; i < M; ++ i)
		sum += month[i];
	if ((Y%4 == 0 && Y%100 != 0) || Y%400 == 0)
		if (M > 2)
			sum ++;
	return sum;
}


int64_t calcDaysFromZero(int y, int m, int d)
{
	int64_t day = 0;

	day += 366; // the year of 0
	day += (y-1) * 365;

	for(int i = 1; i < m; i++)
		day += dayLimit(i, y);

	day += d;

	day += y / 4 - y / 100 + y / 400;

	return day;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/893.in", "r", stdin);
	freopen("./testdata/893.out", "w", stdout);
	#endif
	int plus, day, month, year;

	// while(scanf("%d %d %d %d", &plus, &day, &month, &year) != EOF && plus && day && month && year)
	// {


	// 	printf("%d %d %d\n", day ,month, year);
	// }

	printf("%lld %d\n", calcDaysFromZero(1000, 1, 1), baseday(1, 1, 1000));
	printf("%lld %d\n", calcDaysFromZero(2000, 1, 1), baseday(1, 1, 2000));
	printf("%lld %d\n", calcDaysFromZero(3000, 1, 1), baseday(1, 1, 3000));
	printf("%lld %d\n", calcDaysFromZero(4000, 1, 1), baseday(1, 1, 4000));

	return 0;
}