#include <iostream>
using namespace std;

const int MAX = 4e6 + 4e3;

const long long MOD = 1e9 + 7;

long long factorial[MAX];

long long invFactorial[MAX];

long long power(long long base, long long exp)
{
    long long result = 1;

    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exp /= 2;
    }

    return result;
}

void preprocessFactorials(int n) 
{
    factorial[0] = 1;

    for (int i = 1; i <= n; i++) 
    {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    invFactorial[n] = power(factorial[n], MOD - 2);

    for (int i = n - 1; i >= 0; i--) 
    {
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
    }
}

long long binomialCoefficient(int n, int k) 
{
    if (k < 0 || k > n)
    {
        return 0;
    }

    return factorial[n] * invFactorial[k] % MOD * invFactorial[n - k] % MOD;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    preprocessFactorials(n);

    cout << binomialCoefficient(n, k) << "\n";

    return 0;
}
