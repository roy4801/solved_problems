/*
 * Uva 620 - Cellular Structure
 * author: roy4801
 * AC(C++) 0.000
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

char s[1000];

#define TYPE_MUTANT 0
#define TYPE_SIMPL 1
#define TYPE_FULL 2
#define TYPE_MUTAGEN 3

int parse(const int start, const int end)
{
    // O = OAB
    if(s[end-1] == 'A' && s[end] == 'B')
    {
        if(parse(start, end - 2)) // != TYPE_MUTANT
        {
            return TYPE_FULL;
        }
    }
    // O = BOA
    else if(s[start] == 'B' && s[end] == 'A') // != TYPE_MUTANT
    {
        if(parse(start + 1, end - 1))
        {
            return TYPE_MUTAGEN;
        }
    }
    // O = A
    else if(start == end && (s[start] == 'A' && s[end] == 'A')) // != TYPE_MUTANT
    {
        return TYPE_SIMPL;
    }

    return TYPE_MUTANT;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/620.in", "r", stdin);
    freopen("./testdata/620.out", "w", stdout);
    #endif
    int test;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%s", s);
        
        switch( parse(0, strlen(s)-1) )
        {
            case TYPE_SIMPL:
                printf("SIMPLE\n");
            break;

            case TYPE_FULL:
                printf("FULLY-GROWN\n");
            break;

            case TYPE_MUTAGEN:
                printf("MUTAGENIC\n");
            break;

            case TYPE_MUTANT:
                printf("MUTANT\n");
            break;
        }
    }

    return 0;
}