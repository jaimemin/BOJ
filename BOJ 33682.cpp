#include <iostream>
using namespace std;

long long gcd(long long a, long long b) 
{
    if (a % b == 0)
    {
        return b;
    }

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long s0, X, M, D, K;
    cin >> s0 >> X >> M >> D >> K;

    if (M == 1) 
    {
        cout << 0 << "\n";

        return 0;
    }

    long long a = (s0 + X) % M;
    long long g = gcd(X, M);
    long long candidate = (M - 1) - ((M - 1 - a) % g);

    if (candidate == 0) 
    {
        cout << 0 << "\n";

        return 0;
    }

    long long LMax = K / candidate;
    long long blocks = (D + LMax - 1) / LMax;

    cout << blocks - 1 << "\n";

    return 0;
}