#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long absll(long long x)
{
    return x < 0 ? -x : x;
}

long long extendedGcd(long long a, long long b, long long& x, long long& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }

    long long x1, y1;
    long long g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

long long floorDiv(long long a, long long b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }

    if (a >= 0)
    {
        return a / b;
    }

    return (a - (b - 1)) / b;
}

long long ceilDiv(long long a, long long b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }

    if (a >= 0)
    {
        return (a + (b - 1)) / b;
    }

    return a / b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long M;
    cin >> N >> M;

    if (N == 0)
    {
        cout << (M == 0 ? 0 : -1) << "\n";

        return 0;
    }

    if (N == 1)
    {
        long long p;
        cin >> p;

        if (p == 0)
        {
            cout << (M == 0 ? 0 : -1) << "\n";
        }
        else if (M % p != 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            long long k = M / p;

            cout << (k >= 0 ? k : -1) << "\n";
        }

        return 0;
    }

    long long p1, p2;
    cin >> p1 >> p2;

    if (p1 == 0 && p2 == 0)
    {
        cout << (M == 0 ? 0 : -1);

        return 0;
    }

    if (p1 == 0)
    {
        if (M % p2 != 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            long long y = M / p2;

            cout << (y >= 0 ? y : -1) << "\n";
        }

        return 0;
    }

    if (p2 == 0)
    {
        if (M % p1 != 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            long long x = M / p1;

            cout << (x >= 0 ? x : -1) << "\n";
        }

        return 0;
    }

    long long sign1 = (p1 >= 0 ? 1 : -1);
    long long sign2 = (p2 >= 0 ? 1 : -1);
    long long absP1 = absll(p1);
    long long absP2 = absll(p2);
    long long u, v;
    long long g = extendedGcd(absP1, absP2, u, v);

    if (M % g != 0)
    {
        cout << -1 << "\n";

        return 0;
    }

    long long factor = M / g;
    long long x0 = u * sign1 * factor;
    long long y0 = v * sign2 * factor;
    long long k2 = p2 / g;
    long long k1 = p1 / g;
    long long leftBound = LLONG_MIN / 4;
    long long rightBound = LLONG_MAX / 4;

    if (k2 != 0)
    {
        if (k2 > 0)
        {
            leftBound = max(leftBound, ceilDiv(-x0, k2));
        }
        else
        {
            rightBound = min(rightBound, floorDiv(-x0, k2));
        }
    }
    else if (x0 < 0)
    {
        cout << -1 << "\n";

        return 0;
    }

    if (k1 != 0)
    {
        if (k1 > 0)
        {
            rightBound = min(rightBound, floorDiv(y0, k1));
        }
        else
        {
            leftBound = max(leftBound, ceilDiv(y0, k1));
        }
    }
    else if (y0 < 0)
    {
        cout << -1 << "\n";

        return 0;
    }

    if (leftBound > rightBound)
    {
        cout << -1 << "\n";

        return 0;
    }

    long long delta = k2 - k1;
    long long t = (delta > 0 ? leftBound : (delta < 0 ? rightBound : leftBound));
    long long x = x0 + k2 * t;
    long long y = y0 - k1 * t;

    if (x < 0 || y < 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << (x + y) << "\n";
    }

    return 0;
}