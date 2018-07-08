/*
 * Uva 10903 - Rock-Paper-Scissors
 * author: roy4801
 * AC(C++) 0.130
 */
#include <iostream>
#include <cstring>

using namespace std;

enum
{
    H_ROCK,
    H_PAPER,
    H_SCISSORS
};

int getGestureType(const char s[])
{
    if(strcmp("rock", s) == 0)
    {
        return H_ROCK;
    }
    else if(strcmp("paper", s) == 0)
    {
        return H_PAPER;
    }
    else if(strcmp("scissors", s) == 0)
    {
        return H_SCISSORS;
    }
}

void compete(const int a, const int b, const int l, const int r, int player, int win[], int loose[])
{
    switch(l)
    {
        case H_ROCK:
            if(r == H_SCISSORS)
            {
                win[a]++;
                loose[b]++;
            }
            else if(r == H_PAPER)
            {
                win[b]++;
                loose[a]++;
            }
        break;

        case H_PAPER:
            if(r == H_ROCK)
            {
                win[a]++;
                loose[b]++;
            }
            else if(r == H_SCISSORS)
            {
                win[b]++;
                loose[a]++;
            }
        break;

        case H_SCISSORS:
            if(r == H_PAPER)
            {
                win[a]++;
                loose[b]++;
            }
            else if(r == H_ROCK)
            {
                win[b]++;
                loose[a]++;
            }
        break;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10903.in", "r", stdin);
    freopen("./testdata/10903.out", "w", stdout);
    #endif
    int player, rounds;
    bool printLine = false;
    while(scanf("%d", &player) != EOF && player && scanf("%d", &rounds) != EOF)
    {
        if(printLine)
            putchar('\n');

        int win[player], loose[player];

        for(int i = 0; i < player; i++)
        {
            win[i] = loose[i] = 0;
        }

        for(int i = 0; i < rounds * player * (player-1) / 2; i++)
        {
            int p1, p2;
            char m1[10], m2[10];

            scanf("%d %s %d %s", &p1, m1, &p2, m2);

            compete(p1-1, p2-1, getGestureType(m1), getGestureType(m2), player, win, loose);
        }

        for(int i = 0; i < player; i++)
        {
            if(win[i] + loose[i])
                printf("%.3f\n", (float)win[i] / (float)(win[i] + loose[i]));
            else
                printf("-\n");
        }

        printLine = true;
    }

    return 0;
}