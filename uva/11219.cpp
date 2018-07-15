/*
 * Uva 11219 - How old are you?
 * author: roy4801
 * (C++)
 */
#include <iostream>

using namespace std;

bool isLeapYear(const int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else
        return false;
}

int getDayOfMonth(const int y, const int m)
{
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if(isLeapYear(y))
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
    }
}

int getDistance(int now_y, int now_m, int now_d, int bir_y, int bir_m, int bir_d)
{
    int day = 0;

    // whole year
    for(int i = bir_y+1; i < now_y; i++)
    {
        if(isLeapYear(i))
            day += 366;
        else
            day += 365;
    }

    // birthday
    day += getDayOfMonth(bir_y, bir_m) - bir_d;
    bir_m++;

    if(bir_m > 12)
    {
        bir_y++;
        bir_m = 1;
    }
    else
        for(int i = bir_m; i <= 12; i++)
            day += getDayOfMonth(bir_y, i);
    
    // now
    day += now_d;

    for(int i = 1; i < now_m; i++)
        day += getDayOfMonth(now_y, i);

    

    return day;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11219.in", "r", stdin);
    freopen("./testdata/11219.out", "w", stdout);
    #endif
    int cases, t = 1;
    int ny, nm, nd;
    int by, bm, bd;

    scanf("%d", &cases);

    while(cases-- && scanf("%d/%d/%d", &nd, &nm, &ny) != EOF 
        && scanf("%d/%d/%d", &bd, &bm, &by) != EOF)
    {
        printf("Case #%d: ", t++);
        if(ny >= by)
        {
            if(ny - by > 130)
            {
                printf("Check birth date\n");
            }
            else if(ny == by)
            {
                if(nm < bm)
                {
                    printf("Invalid birth date\n");
                }
                else if(nm == bm)
                {
                    if(nd < bd)
                    {
                        printf("Invalid birth date\n");
                    }
                    else if(nd = bd)
                    {
                        printf("0\n");
                    }
                }
            }
            else
            {
                int dis;
                if((dis = getDistance(ny, nm, nd, by, bm, bd)) >= 365)
                {
                    printf("d:%d disy:%d\n", dis, dis / 365);
                }
                else
                    printf("0\n");
            }
        }
        else
        {
            printf("Invalid birth date\n");
        }

        printf("%d %d %d\n%d %d %d\n\n", nd, nm, ny, bd, bm, by);
    }

    return 0;
}