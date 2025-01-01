#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        long long x, y;
        cin >> x >> y;

        long long distance = y - x;

        if (distance == 0) 
        {
            cout << 0 << "\n";

            continue;
        }

        long long n = (long long)floor(sqrt((long double)distance));

        if (n * n == distance) 
        {
            cout << 2 * n - 1 << "\n";
        }
        else if (distance <= n * n + n) 
        {
            cout << 2 * n << "\n";
        }
        else 
        {
            cout << 2 * n + 1 << "\n";
        }
    }

    return 0;
}
