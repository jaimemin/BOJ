#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

// 빠른 모듈러 거듭제곱 함수: base^exp mod mod
long long modExp(long long base, long long exp, long long mod) 
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;

    while (Q--) 
    {
        long long p, n;
        cin >> p >> n;

        long long pn = modExp(p, n, MOD);
        long long numerator = (pn - 1 + MOD) % MOD;
        long long denominator = (p - 1) % MOD;
        long long invDenom = modExp(denominator, MOD - 2, MOD);
        long long answer = (numerator * invDenom) % MOD;

        cout << answer << "\n";
    }

    return 0;
}