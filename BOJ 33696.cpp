#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long modExp(long long base, long long exp, long long mod) 
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    int maxVal = 3 * N;

    vector<long long> fact(maxVal + 1), invfact(maxVal + 1);
    fact[0] = 1;

    for (int i = 1; i <= maxVal; i++) 
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invfact[maxVal] = modExp(fact[maxVal], MOD - 2, MOD);

    for (int i = maxVal; i >= 1; i--)
    {
        invfact[i - 1] = (invfact[i] * i) % MOD;
    }

    vector<long long> T(N + 1, 0);

    for (int n = 0; n <= N; n++) 
    {
        T[n] = fact[3 * n];
        T[n] = (T[n] * invfact[n]) % MOD;
        T[n] = (T[n] * invfact[n]) % MOD;
        T[n] = (T[n] * invfact[n]) % MOD;
    }

    vector<long long> dp(N + 1, 0);
    dp[0] = 0;

    for (int n = 1; n <= N; n++) 
    {
        long long sum = 0;

        for (int j = 1; j < n; j++) 
        {
            sum = (sum + dp[j] * T[n - j]) % MOD;
        }

        dp[n] = (T[n] - sum) % MOD;

        if (dp[n] < 0)
        {
            dp[n] += MOD;
        }
    }

    cout << dp[N] % MOD << "\n";
    
    return 0;
}