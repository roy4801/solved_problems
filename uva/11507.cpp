/*
 * Uva 11507 - Bender B. Rodríguez Problem
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

enum
{
    MOVE_PY = 0,
    MOVE_NY,
    MOVE_PZ,
    MOVE_NZ
};

enum DIR
{
    D_PX,
    D_NX,
    D_PY,
    D_NY,
    D_PZ,
    D_NZ
};

// It's like permutations
// We mapped all movements in a two-dimensional array
void initMovement(int m[4][6])
{
    // init +y movements
    m[MOVE_PY][D_PX] = D_PY;
    m[MOVE_PY][D_NX] = D_NY;
    m[MOVE_PY][D_PY] = D_NX;
    m[MOVE_PY][D_NY] = D_PX;
    m[MOVE_PY][D_PZ] = D_PZ;
    m[MOVE_PY][D_NZ] = D_NZ;

    // init -y movements
    m[MOVE_NY][D_PX] = D_NY;
    m[MOVE_NY][D_NX] = D_PY;
    m[MOVE_NY][D_PY] = D_PX;
    m[MOVE_NY][D_NY] = D_NX;
    m[MOVE_NY][D_PZ] = D_PZ;
    m[MOVE_NY][D_NZ] = D_NZ;

    // init +z movements
    m[MOVE_PZ][D_PX] = D_PZ;
    m[MOVE_PZ][D_NX] = D_NZ;
    m[MOVE_PZ][D_PY] = D_PY;
    m[MOVE_PZ][D_NY] = D_NY;
    m[MOVE_PZ][D_PZ] = D_NX;
    m[MOVE_PZ][D_NZ] = D_PX;

    // init -z movements
    m[MOVE_NZ][D_PX] = D_NZ;
    m[MOVE_NZ][D_NX] = D_PZ;
    m[MOVE_NZ][D_PY] = D_PY;
    m[MOVE_NZ][D_NY] = D_NY;
    m[MOVE_NZ][D_PZ] = D_PX;
    m[MOVE_NZ][D_NZ] = D_NX;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11507.in", "r", stdin);
    freopen("./testdata/11507.out", "w", stdout);
    #endif
    int len;
    int move[4][6];
    char instr[3];

    initMovement(move);

    while(scanf("%d", &len) != EOF && len)
    {
        int nowDir = D_PX;

        for(int i = 0; i < len - 1 && scanf("%s", instr) != EOF; i++)
        {
            if(instr[0] == 'N' && instr[1] == 'o')
            {
                continue;
            }
            else
                switch(instr[1])
                {
                    case 'y':
                        if(instr[0] == '+')
                            nowDir = move[MOVE_PY][nowDir];
                        else if(instr[0] == '-')
                            nowDir = move[MOVE_NY][nowDir];
                    break;

                    case 'z':
                        if(instr[0] == '+')
                            nowDir = move[MOVE_PZ][nowDir];
                        else if(instr[0] == '-')
                            nowDir = move[MOVE_NZ][nowDir];
                    break;
                }
        }

        // print the direction
        switch(nowDir)
        {
            case D_PX:
                printf("+x");
            break;

            case D_NX:
                printf("-x");
            break;

            case D_PY:
                printf("+y");
            break;

            case D_NY:
                printf("-y");
            break;

            case D_PZ:
                printf("+z");
            break;

            case D_NZ:
                printf("-z");
            break;
        }
        putchar('\n');
    }

    return 0;
}
