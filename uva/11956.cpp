/*
 * Uva 11956 - Brainfuck
 * author: roy4801
 * AC(C++) 0.120
 */
#include <iostream>

using namespace std;

#define MAX_MEM 100

typedef unsigned char byte;

void printMem(const byte mem[])
{
    for(int i = 0; i < MAX_MEM; i++)
        if(mem[i] > 15)
            printf(" %X", mem[i]);
        else
            printf(" 0%X", mem[i]);
    putchar('\n');
}

void runCode(const char opt, byte **n, byte mem[])
{
    ptrdiff_t diff = *n - mem;
    // printf("diff %d\n", diff);

    switch(opt)
    {
        case '>':
            if(diff == MAX_MEM - 1)
                *n = mem;
            else
                (*n)++;
        break;

        case '<':
            if(diff == 0)
                *n = mem + MAX_MEM - 1;
            else
                (*n)--;
        break;

        case '+':
            (*(*n))++;
        break;

        case '-':
            (*(*n))--;
        break;

        case '.':

        break;
    }
    // diff = *n - mem;
    // printf("diff %d\n", diff);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11956.in", "r", stdin);
    freopen("./testdata/11956.out", "w", stdout);
    #endif
    char instruct;
    int cases, i = 1;

    scanf("%d ", &cases);

    while(cases--)
    {
        byte mem[MAX_MEM] = {0};
        byte *now = mem;
        
        printf("Case %d:", i++);

        // interpret the brainfuck code
        while((instruct = getchar()) != '\n')
        {
            // printf("Ptr      : %p\nMem_start: %p\n", now, mem);
            // printf("Run %c\n", instruct);
            runCode(instruct, &now, mem);
            // printMem(mem);
            // putchar('\n'); 
        }
        printMem(mem);
    }

    return 0;
}