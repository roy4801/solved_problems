/*
 * Uva 10018 - Reverse and Add
 * author: roy4801
 * AC(c++)
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void add(char num[], int &l)
{
    char tmp[10] = {0};

    for(int i = 0; i < l; i++)
    {
        tmp[i] += num[i] + num[l-1 - i];
        // printf(".%d", tmp[i]);

        if(tmp[i] > 9)
        {
            tmp[i] -= 10;
            tmp[i+1]++;

            if(i == l - 1)
            {
                l++;
                break;
            }
        }
    }
    // Copy tmp[] to num[]
    for(int i = 0; i < l; i++)
    {
        num[i] = tmp[i];
        // printf("%d ", num[i]);
    }
}

void print(char c[], int l)
{
    // printf("strlen(c): %d", strlen(c));
    for(int i = l-1; i >= 0; i--)
    {
        printf("%c", c[i] + '0');
    }
}

bool isPalindrome(char num[], int l)
{
    int half, size = l;
    
    if(size % 2 != 0)
    {
        half = (size + 1) / 2;
    }
    else
    {
        half = size / 2;
    }

    // check if it is a palindrome
    int tmp = 0;
    for(int i = 0; i < half; i++)
    {
        if(num[i] == num[size-1 - i])
        {
            tmp++;
        }
    }
    // Result
    if(tmp == half)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10018.in", "r", stdin);
    freopen("./testdata/10018.out", "w", stdout);
    #endif
    int cases;
    char num[10];

    scanf("%d ", &cases);

    while(cases--)
    {
        int times = 0;

        scanf("%s", num);

        int l = strlen(num);
        std::reverse(num, num + l);
        for(int i = 0; i < l; i++) num[i] -= '0';

        do
        {
            times++;
            add(num, l); // l will be changed here
        }
        while(!isPalindrome(num, l));

        printf("%d ", times);
        print(num, l);
        putchar('\n');
    }

    return 0;
}