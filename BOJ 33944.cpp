#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        long long n;
        int x;
        cin >> n >> x;

        vector<long long> spikes(x);

        for (int i = 0; i < x; i++)
        {
            cin >> spikes[i];
        }

        if (spikes[0] > 6)
        {
            long long shift = spikes[0] - 6;

            for (int i = 0; i < x; i++)
            {
                spikes[i] -= shift;
            }

            n -= shift;
        }

        for (int i = 1; i < x; i++)
        {
            if (spikes[i] - spikes[i - 1] > 6)
            {
                long long shift = spikes[i] - (spikes[i - 1] + 6);

                for (int j = i; j < x; ++j)
                {
                    spikes[j] -= shift;
                }

                n -= shift;
            }
        }

        if (n > spikes.back() + 3)
        {
            n = spikes.back() + 3;
        }

        vector<bool> spikeMask(n + 3, false);

        for (int i = 0; i < x; i++)
        {
            spikeMask[spikes[i]] = true;
        }

        vector<bool> canReach(n + 3, false);
        canReach[0] = true;

        for (int i = 1; i <= n + 2; i++)
        {
            if (spikeMask[i])
            {
                continue;
            }

            if (canReach[i - 1] || (i - 4 >= 0 && canReach[i - 4]))
            {
                canReach[i] = true;
            }
        }

        cout << (canReach[n + 2] ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }

    return 0;
}