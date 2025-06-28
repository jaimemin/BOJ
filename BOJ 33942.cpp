#include <iostream>
using namespace std;

long long floorSqrt(long long x)
{
    long long lo = 0, hi = 3000000000LL;
    long long answer = 0;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        long long sq = mid * mid;

        if (sq <= x)
        {
            answer = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long maxByStarts = (N + 2) / 3 + 1;
        long long D = 1 + 8 * N;
        long long sqrtD = floorSqrt(D);
        long long maxBySum = (sqrtD - 1) / 2;

        cout << (maxByStarts < maxBySum ? maxByStarts : maxBySum) << "\n";
    }

    return 0;
}
