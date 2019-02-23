/*
 * UVA 136 - Ugly Numbers
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "136"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

#define N 1500
LL arr[N+5] = {0, 1};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/" PROB TESTC ".in", "r", stdin);
    freopen("./testdata/" PROB ".out", "w", stdout);
    #endif
    int s2 = 1, s3 = 1, s5 = 1;
    for(int i = 2; i <= 1500; i++)
    {
        // 要比前一項大
        while(arr[s2]*2 <= arr[i-1]) s2++;
        while(arr[s3]*3 <= arr[i-1]) s3++;
        while(arr[s5]*5 <= arr[i-1]) s5++;

        arr[i] = min(arr[s2]*2, min(arr[s3]*3, arr[s5]*5));
    }
    printf("The 1500'th ugly number is %lld.\n", arr[1500]);

    return 0;
}