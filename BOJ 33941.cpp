#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<long long> refundAmounts;

    for (int i = 0; i < n; i++)
    {
        long long balance;
        cin >> balance;

        if (balance > 500 && balance < 20000)
        {
            refundAmounts.push_back(balance - 500);
        }
    }

    long long totalRefund = 0;

    for (auto b : refundAmounts)
    {
        totalRefund += b;
    }

    if (totalRefund == 0)
    {
        cout << 0 << "\n";

        return 0;
    }

    int rem = (int)(totalRefund % 500);

    if (rem == 0)
    {
        cout << totalRefund << "\n";

        return 0;
    }

    vector<long long> dpOld(500, INF), dpNew(500);
    dpOld[0] = 0;

    for (auto b : refundAmounts)
    {
        int modB = (int)(b % 500);

        for (int r0 = 0; r0 < 500; ++r0)
        {
            dpNew[r0] = dpOld[r0];
        }

        for (int r0 = 0; r0 < 500; ++r0)
        {
            if (dpOld[r0] == INF)
            {
                continue;
            }

            int r1 = r0 + modB;

            if (r1 >= 500)
            {
                r1 -= 500;
            }

            long long candidate = dpOld[r0] + b;

            if (candidate < dpNew[r1])
            {
                dpNew[r1] = candidate;
            }
        }

        dpOld.swap(dpNew);
    }

    long long minDrop = dpOld[rem];

    if (minDrop >= INF || minDrop > totalRefund)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << (totalRefund - minDrop) << "\n";
    }

    return 0;
}