/*
 * Uva 573 - The Snail
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/573.in", "r", stdin);
    freopen("./testdata/573.out", "w", stdout);
    #endif
    float well, climb, slide, fatigue;

    while(scanf("%f %f %f %f", &well, &climb, &slide, &fatigue) != EOF && well)
    {
        float now = 0.f;
        int time = 0;

        // the climbing height of the snail is lesser as the time goes up
        fatigue = climb * fatigue / 100.f;

        while(true)
        {
            ++time;

            now += climb >= 0.f ? climb : 0.f;

            if(now > well)
                break;

            now -= slide;

            if(now < 0.f)
                break;

            climb -= fatigue;
        }
        printf("%s on day %d\n", now > well ? "success" : "failure", time);
    }

    return 0;
}