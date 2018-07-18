/*
 * Uva 11687 - Digits
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int getNumOfDigit(int n)
{
    int d = 0;
    while(n > 9)
    {
        d++;
        n /= 10;
    }
    d++;
    return d;
}

int nextRecurrence(int digit, int times)
{
    times++;

    int n = getNumOfDigit(digit);
    if(digit == n)
    {
        return times;
    }
    else
    {
        return nextRecurrence(n, times);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11687.in", "r", stdin);
    freopen("./testdata/11687.out", "w", stdout);
    #endif
    char prev, c;
    int digit = 0;
    
    while((c = getchar()) != EOF && c != 'E')
    {
        if(c == '\n')
        {
            if(prev == '1' && digit == 1)
                printf("1\n");
            else
                printf("%d\n", nextRecurrence(digit, 1));
            digit = 0;
        }
        else
        {
            digit++;
        }

        if(digit)
            prev = c;
    }

    return 0;
}