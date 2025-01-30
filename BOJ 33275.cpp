#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

pair<long long, pair<long long, long long>> extendedGCD(long long a, long long b)
{
    if (b == 0) 
    {
        return { a, {1, 0} };
    }

    auto ret = extendedGCD(b, a % b);
    long long g = ret.first;
    long long x = ret.second.first;
    long long y = ret.second.second;

    return make_pair(g, make_pair(y, x - (a / b) * y));
}

long long modInverse(long long a, long long m) 
{
    auto res = extendedGCD(a, m);
    long long g = res.first;
    long long x = res.second.first;

    if (g != 1)
    {
        return -1;
    }

    return (x % m + m) % m;
}

long long modPow(long long base, long long exp, long long m) 
{
    if (exp == 0)
    {
        return 1 % m;
    }

    if (exp == 1)
    {
        return base % m;
    }

    if (exp % 2 == 0) 
    {
        long long half = modPow(base, exp / 2, m);

        return (half * half) % m;
    }
    
    return (base * modPow(base, exp - 1, m)) % m;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    long long twocnt = 0;

    while (K % 2 == 0)
    {
        twocnt++;

        K /= 2;
    }

    vector<long long> v(K, 0);
    
    long long cur = 0;
    long long answer = 0;
    long long zerostreak = 0;
    long long inv2 = modInverse(2, K);

    queue<long long> q;

    for (long long i = 0; i < N; i++) 
    {
        cur *= 2;

        if (S[i] == '1') 
        {
            zerostreak = 0;

            cur++;
        }
        else 
        {
            zerostreak++;

            if (twocnt > 1)
            {
                answer += min(zerostreak, twocnt - 1);
            }
        }

        cur %= K;

        long long a = (cur * modPow(inv2, i, K)) % K;

        if (zerostreak >= twocnt) 
        {
            if (cur == 0)
            {
                answer++;
            }

            answer += v[a];
        }

        q.push(a);

        while (!q.empty() && q.size() >= twocnt) 
        {
            v[q.front()]++;
            q.pop();
        }
    }

    cout << answer << "\n";

    return 0;
}
