#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    int count = 0;

    for (int d = 0; d < 10; d++) 
    {
        if (d <= N)
        {
            count++;
        }
    }

    for (int len = 2; len <= 10; len++)
    {
        for (int d = 1; d <= 9; d++)
        {
            long long rep = 0;

            for (int i = 0; i < len; i++)
            {
                rep = rep * 10 + d;
            }

            if (rep <= N)
            {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}