#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long a, d, m;
    cin >> n >> a >> d >> m;

    int bestK = 0;
    long long bestT = 0;

    for (int k = n; k >= 1; k--)
    {
        long long remValue = m * 1LL - k * a * 1LL;

        if (remValue < 0)
        {
            continue;
        }

        if (remValue % d != 0)
        {
            continue;
        }

        long long tValue = (long long)(remValue / d);
        long long tMin = (long long)k * (k - 1LL) / 2LL;
        long long tMax = (long long)k * (2LL * n - k - 1LL) / 2LL;

        if (tValue < tMin || tValue > tMax)
        {
            continue;
        }

        bestK = k;
        bestT = tValue;

        break;
    }

    if (bestK == 0)
    {
        cout << -1 << "\n";

        return 0;
    }

    int k = bestK;
    long long tMin = k * 1LL * (k - 1LL) / 2LL;
    long long deltaSum = bestT - tMin;

    vector<int> indices(k);

    for (int i = 0; i < k; i++)
    {
        indices[i] = i;
    }

    for (int i = k - 1; i >= 0 && deltaSum > 0; i--)
    {
        long long inc = min(deltaSum, (n - k) * 1LL);
        indices[i] += (int)inc;
        deltaSum -= inc;
    }

    cout << k << "\n";

    for (int i = 0; i < k; i++)
    {
        long long value = a + d * (long long)indices[i];

        cout << value << (i + 1 < k ? ' ' : '\n');
    }

    return 0;
}