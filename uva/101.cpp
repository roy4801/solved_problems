/*
 * Uva 101 - The Blocks Problem
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstring>

using namespace std;

enum act_type
{
    NONE,
    MOVE,
    PILE
};

enum way_type
{
    ONTO,
    OVER
};

// target must be the last one
void putBack(int num, int stack[num][num], int size[num], int nowPos[num], const int targetPile, const int target)
{
    stack[targetPile][size[targetPile]++] = stack[nowPos[target]][size[nowPos[target]] - 1];

    stack[nowPos[target]][size[nowPos[target]] - 1] = -1;
    size[nowPos[target]]--;

    nowPos[target] = targetPile;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/101.in", "r", stdin);
    freopen("./testdata/101.out", "w", stdout);
    #endif
    int num;

    while(scanf("%d", &num) != EOF)
    {
        int stack[num][num];
        int nowPos[num];
        int size[num];

        memset(stack, 0xFF, sizeof(int) * num * num);

        for(int i = 0; i < num; i++)
        {
            stack[0][i] = numPos[i] = i;
            size[i] = 1;
        }

        char opt[2];
        int from, to;
        char str[5];

        scanf("%s %d", str, &from);

        if(strcmp(str, "move") == 0)
        {
            opt[0] = MOVE;
        }
        else if(strcmp(str, "pile") == 0)
        {
            opt[0] = PILE;
        }

        scanf("%s %d", str, &to);

        if(strcmp(str, "onto") == 0)
        {
            opt[1] = ONTO;
        }
        else if(strcmp(str, "over") == 0)
        {
            opt[1] = OVER;
        }

        if(opt[0] == MOVE && opt[1] == ONTO)
        {

        }


    }

    return 0;
}