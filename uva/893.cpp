/*
 * Uva 893 - Y3K Problem
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstdint>

using namespace std;

bool isLeapYear(const int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 || y == 0;
}

int dayLimit(const int month, const int year)
{
    static const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return isLeapYear(year) && month == 2 ? d[1] + 1 : d[month - 1];
}

int64_t calcDaysFromZero(int y, int m, int d)
{
    int64_t day = 0;

    // the year of 0
    day += 366;

    // all days between 1 ~ year-1
    day += (y-1) * 365;

    // calc this year
    for(int i = 1; i < m; i++)
        day += dayLimit(i, y);
    day += d;

    // calc the excess day of leap years
    y--;
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

    while(scanf("%d %d %d %d", &plus, &day, &month, &year) != EOF && (plus || day || month || year))
    {
        int64_t now = calcDaysFromZero(year, month, day) + (int64_t)plus;

        // Reset the date
        year = day = 0;
        month = 1;

        int target = 0; // from year 0
        
        while(now > 0)
        {
            bool whole = false;

            if(isLeapYear(target++) && now > 366)
            {
                now -= 366;
                year++;
                whole = true;
            }
            else if(now > 365)
            {
                now -= 365;
                year++;
                whole = true;
            }
            
            // Not the whole year
            if(!whole)
            {
                // printf("%d %d %d\n", day ,month, year);
                for(int i = 1; i <= 12; i++)
                {
                    // printf("%lld %d\n", now ,dayLimit(i, year));
                    if(now > dayLimit(i, year))
                    {
                        now -= dayLimit(i, year);
                        month++;
                    }
                    else
                    {
                        day += now;
                        now = 0;
                        break;
                    }
                }

                // break;
            }
        }


        printf("%d %d %d\n", day ,month, year);
    }
    
    // printf("%lld %d\n", calcDaysFromZero(2459377, 1, 1), baseday(1, 1, 2459377));

    return 0;
}