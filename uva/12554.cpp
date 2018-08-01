/*
 * Uva 12554 - A Special "Happy Birthday" Song!!!
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

const char* word[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
const int num = sizeof(word) / sizeof(char*);

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12554.in", "r", stdin);
    freopen("./testdata/12554.out", "w", stdout);
    #endif
    int people;

    scanf("%d", &people);

    char name[people][101];

    for(int i = 0; i < people; i++)
        scanf("%s", name[i]);

    int times = (people / num + 1) * num;

    for(int i = 0; i < times; i++)
    {
        printf("%s: %s\n", name[i % people], word[i % num]);
    }

    return 0;
}