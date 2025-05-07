#include <iostream>
#include <vector>
using namespace std;

int N;

vector<long long> fenw;

long long fenwSum(int idx)
{
    long long s = 0;

    while (idx > 0)
    {
        s += fenw[idx];

        idx -= idx & -idx;
    }

    return s;
}

void fenwAdd(int idx, long long v)
{
    while (idx <= N) 
    {
        fenw[idx] += v;

        idx += idx & -idx;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    vector<int> E(N + 1);

    for (int i = 1; i <= N; i++) 
    {
        cin >> E[i];
    }

    int maxForward = 0;

    for (int i = 1; i <= N; i++)
    {
        if (E[i] > i) 
        {
            if (E[i] < maxForward)
            {
                cout << -1 << "\n";

                return 0;
            }

            maxForward = E[i];
        }
    }

    int maxReverse = 0;

    for (int i = N; i >= 1; i--)
    {
        if (E[i] < i) 
        {
            int rev = N - E[i] + 1;

            if (rev < maxReverse) 
            {
                cout << -1 << "\n";

                return 0;
            }

            maxReverse = rev;
        }
    }

    fenw.resize(N + 1, 0LL);

    long long inversionCount = 0;

    for (int i = 1; i <= N; i++) 
    {
        inversionCount += (i - 1) * 1LL - fenwSum(E[i]);

        fenwAdd(E[i], 1);
    }

    cout << inversionCount << "\n";

    return 0;
}