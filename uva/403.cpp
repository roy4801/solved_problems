/*
 * UVA 403 - Postscript
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "403"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

char buf[60][60];

const char * letter[5][27] = {{".***..", "****..", ".****.", "****..", "*****.", "*****.", ".****.", "*...*.", "*****.", "..***.", "*...*.", "*.....", "*...*.", "*...*.", ".***..", "****..", ".***..", "****..", ".****.", "*****.", "*...*.", "*...*.", "*...*.", "*...*.", "*...*.", "*****.", "......"},
                              {"*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.....", "*.....", "*...*.", "..*...", "...*..", "*..*..", "*.....", "**.**.", "**..*.", "*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.*.*.", "*...*.", "*...*.", "*...*.", ".*.*..", ".*.*..", "...*..", "......"},
                              {"*****.", "****..", "*.....", "*...*.", "***...", "***...", "*..**.", "*****.", "..*...", "...*..", "***...", "*.....", "*.*.*.", "*.*.*.", "*...*.", "****..", "*...*.", "****..", ".***..", "..*...", "*...*.", ".*.*..", "*.*.*.", "..*...", "..*...", "..*...", "......"},
                              {"*...*.", "*...*.", "*.....", "*...*.", "*.....", "*.....", "*...*.", "*...*.", "..*...", "*..*..", "*..*..", "*.....", "*...*.", "*..**.", "*...*.", "*.....", "*..**.", "*..*..", "....*.", "..*...", "*...*.", ".*.*..", "**.**.", ".*.*..", "..*...", ".*....", "......"},
                              {"*...*.", "****..", ".****.", "****..", "*****.", "*.....", ".***..", "*...*.", "*****.", ".**...", "*...*.", "*****.", "*...*.", "*...*.", ".***..", "*.....", ".****.", "*...*.", "****..", ".***..", ".***..", "..*...", "*...*.", "*...*.", "..*...", "*****.", "......"}};

enum
{
    READ_CMD,
    CMD_P,
    CMD_L,
    CMD_R,
    CMD_C,
    CMD_END
};

enum font_type
{
    FONT_C1,
    FONT_C5
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/" PROB TESTC ".in", "r", stdin);
    freopen("./testdata/" PROB ".out", "w", stdout);
    #endif
    memset(buf, '.', sizeof(buf));

    char c;
    int stat = READ_CMD;
    int font, row, col;
    string in;
    char s[65];

    while((c = getchar()) != EOF)
    {
        if(stat == READ_CMD && c == '.')
        {
            c = getchar();

            switch(c)
            {
                case 'P':
                    stat = CMD_P;
                break;
                case 'L':
                    stat = CMD_L;
                break;
                case 'R':
                    stat = CMD_R;
                break;
                case 'C':
                    stat = CMD_C;
                break;
                case 'E':
                    stat = CMD_END;
                break;
            }
            // get command args
            switch(c)
            {
                case 'P':
                case 'L':
                case 'R':
                case 'C':
                {
                    cin >> in;

                    if(in == "C1")
                        font = FONT_C1;
                    else if(in == "C5")
                        font = FONT_C5;

                    cin >> row;
                    row--;

                    if(c == 'P')
                    {
                        cin >> col;
                        col--;
                    }

                    while((c = getchar()) != '|');
                    int i = 0;
                    while((c = getchar()) != '|')
                    {
                        s[i++] = c==' ' ? '.' : c;
                    }
                    s[i] = '\0';
                    getchar();
                }
                break;
                case 'E':
                    while((c = getchar()) != '\n' && c != EOF);
                break;
            }
        }

        // run cmd
        switch(stat)
        {
            case CMD_P:
            {
                if(font == FONT_C1)
                {
                    for(int i = 0; i < strlen(s); i++)
                    {
                        buf[row][col + i] = s[i];
                    }
                }
            }
            break;

            case CMD_L:
            {
                if(font == FONT_C1)
                {
                    for(int i = 0; i < strlen(s) && i < 60; i++)
                        buf[row][i] = s[i];
                }
            }
            break;

            case CMD_R:
            {
                if(font == FONT_C1)
                {
                    for(int i = strlen(s)-1, j = 59; i >= 0 && j >= 0; i--, j--)
                        buf[row][j] = s[i];
                }
            }
            break;

            case CMD_C:
            {
                if(font == FONT_C1)
                {
                    int start = (60 - strlen(s)) / 2;

                    if(strlen(s) % 2 != 0) // odd
                        start++;

                    if(start < 0)
                    {
                        for(int i = -start, j = 0; i < strlen(s) && j < 60; i++, j++)
                        {
                            buf[row][j] = s[i];
                        }
                    }
                    else
                    {
                        for(int i = 0,j = start; i < strlen(s) && j < 60; i++, j++)
                        {
                            buf[row][j] = s[i];
                        }
                    }
                }
            }
            break;

            case CMD_END:
            {
                for(int i = 0; i < 60; i++)
                {
                    for(int j = 0; j < 60; j++)
                        putchar(buf[i][j]);
                    putchar('\n');
                }
                putchar('\n');
                for(int i = 0; i < 60; i++)
                    putchar('-');
                putchar('\n');
                putchar('\n');
            }
            break;
        }

        // cout << "Font: " << (font==FONT_C1 ? "C1" : "C5") << '\n';
        // cout << "R: " << row;
        // if(stat == CMD_P)
        //     cout << " C: " << col << '\n';
        // else
        //     cout << '\n';
        // cout << s << "\n\n";
        stat = READ_CMD;
    }

    return 0;
}