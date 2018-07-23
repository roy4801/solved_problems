/*
 * Uva 1124 - Celebrity jeopardy
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/1124.in", "r", stdin);
    freopen("./testdata/1124.out", "w", stdout);
    #endif
    std::string s;

    while(getline(std::cin, s))
    {
        std::cout << s << std::endl;
    }

    return 0;
}