#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int input;
    
    while(cin >> input && input != 0)
    {
        uint64_t sum = 0;
        uint64_t times, lower = 1, upper;

        while(lower <= input)
        {
            times = input / lower;
            upper = input / times;

            sum += times * ((upper + lower) * (upper - lower + 1LL) / 2LL);
            lower = upper + 1LL;
        }
        cout << sum - 1LL << endl;

    }
}