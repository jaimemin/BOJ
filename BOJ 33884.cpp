#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;

    long long sum1x = 0, sum1y = 0;

    for (long long i = 0; i < N; i++) 
    {
        long long x, y;
        cin >> x >> y;

        sum1x += x;
        sum1y += y;
    }

    long long sum2x = 0, sum2y = 0;

    for (long long i = 0; i < N; i++)
    {
        long long u, v;
        cin >> u >> v;

        sum2x += u;
        sum2y += v;
    }

    long long A = (sum2x - sum1x) / N;
    long long B = (sum2y - sum1y) / N;

    cout << A << " " << B << "\n";

    return 0;
}