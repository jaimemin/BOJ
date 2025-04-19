#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

vector<int> parent;

vector<int> ranks;

vector<int> xor2Parent;

vector<int> fixedVal;

bool conflict = false;

int findSet(int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    int p = parent[x];
    parent[x] = findSet(p);
    xor2Parent[x] ^= xor2Parent[p];

    return parent[x];
}

void unionSet(int x, int y, int w)
{
    int rx = findSet(x), ry = findSet(y);

    if (rx == ry)
    {
        if ((xor2Parent[x] ^ xor2Parent[y]) != w)
        {
            conflict = true;
        }

        return;
    }

    int d = xor2Parent[x] ^ xor2Parent[y] ^ w;

    if (ranks[rx] < ranks[ry])
    {
        swap(rx, ry);
    }

    parent[ry] = rx;
    xor2Parent[ry] = d;

    if (fixedVal[rx] == -1 && fixedVal[ry] != -1) 
    {
        fixedVal[rx] = fixedVal[ry] ^ d;
    }
    else if (fixedVal[rx] != -1 && fixedVal[ry] != -1) 
    {
        if (fixedVal[rx] != (fixedVal[ry] ^ d))
        {
            conflict = true;
        }
    }
    
    if (ranks[rx] == ranks[ry])
    {
        ranks[rx]++;
    }
}

void fixNode(int x, int val) 
{
    int rx = findSet(x);
    int desired = val ^ xor2Parent[x];

    if (fixedVal[rx] == -1)
    {
        fixedVal[rx] = desired;
    }
    else if (fixedVal[rx] != desired)
    {
        conflict = true;
    }
}

long long modexp(long long base, long long exp)
{
    long long result = 1;
    base %= MOD;

    while (exp > 0) 
    {
        if (exp & 1)
        {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    ranks.assign(N + 1, 0);
    xor2Parent.assign(N + 1, 0);
    fixedVal.assign(N + 1, -1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        char type;
        cin >> a >> b >> type;

        if (conflict)
        {
            continue;
        }

        if (type == 'D') 
        {
            unionSet(a, b, 1);
        }
        else if (type == 'U')
        {
            unionSet(a, b, 0);
            fixNode(a, 0);
            fixNode(b, 0);
        }
        else if (type == 'P') 
        {
            unionSet(a, b, 0);
            fixNode(a, 1);
            fixNode(b, 1);
        }
    }

    if (conflict)
    {
        cout << 0 << "\n";

        return 0;
    }

    vector<bool> seen(N + 1, false);
    int freeCount = 0;

    for (int i = 1; i <= N; i++)
    {
        int r = findSet(i);

        if (!seen[r])
        {
            seen[r] = true;

            if (fixedVal[r] == -1)
            {
                freeCount++;
            }
        }
    }
    
    long long answer = modexp(2, freeCount);
    cout << answer % MOD << "\n";

    return 0;
}