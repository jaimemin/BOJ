#include <iostream>
using namespace std;

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

        long long availableStarts = (N + 2) / 3;
        long long low = 0, high = 1000000000LL;

        for (int i = 0; i < 100; i++)
        {
            long long mid = (low + high) / 2;
            long long needed = 3LL * mid * (mid + 1) / 2;

            if (needed <= availableStarts)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        long long groupCount = (3LL * high * (high + 1) / 2 <= availableStarts ? high : low);
        long long usedStarts = 3LL * groupCount * (groupCount + 1) / 2;
        long long remain = availableStarts - usedStarts;
        long long answer = 1 + 3LL * groupCount + remain / (groupCount + 1);

        cout << answer << "\n";
    }

    return 0;
}