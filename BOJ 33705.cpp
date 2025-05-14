#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEG_INF = -(1LL << 60);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++) 
    {
        cin >> A[i];
    }

    vector<int> p(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        p[i] = p[i - 1] + (A[i] == 1);
    }

    int totalOnes = p[N];
    int need0 = (N + 1) / 2;

    if (totalOnes >= need0) 
    {
        cout << 0 << "\n";

        return 0;
    }

    for (int i = 1; i <= N - 1; i++)
    {
        int k = N - i;
        int x = totalOnes - p[i];
        int need = (k + 1) / 2;

        if (x >= need) 
        {
            cout << 1 << "\n";

            return 0;
        }
    }

    for (int i = 1; i <= N - 1; i++)
    {
        int k = i;
        int x = p[i];
        int need = (k + 1) / 2;

        if (x >= need) 
        {
            cout << 1 << "\n";

            return 0;
        }
    }

    vector<long long> B(N + 1);

    for (int i = 1; i <= N; i++)
    {
        B[i] = 2LL * p[i] - i;
    }

    vector<long long> bestEven(N + 1, NEG_INF), bestOdd(N + 1, NEG_INF);

    for (int i = 1; i <= N; i++) 
    {
        bestEven[i] = bestEven[i - 1];
        bestOdd[i] = bestOdd[i - 1];

        if ((i & 1) == 0) 
        {
            bestEven[i] = max(bestEven[i], B[i]);
        }
        else 
        {
            bestOdd[i] = max(bestOdd[i], B[i]);
        }
    }

    int M = (N + 1) & 1;

    for (int r = 3; r <= N; r++)
    {
        int lenSuffix = N - (r - 1);
        long long onesSuffix = p[N] - p[r - 1];
        long long C = 2LL * onesSuffix - lenSuffix;
        int rp = r & 1;
        int req0 = (M - rp) & 1;
        long long be = bestEven[r - 2];

        if (be != NEG_INF && be + C >= req0) 
        {
            cout << 1 << "\n";

            return 0;
        }

        int req1 = (M + 1 - rp) & 1;
        long long bo = bestOdd[r - 2];

        if (bo != NEG_INF && bo + C >= req1)
        {
            cout << 1 << "\n";

            return 0;
        }
    }

    cout << 2 << "\n";

    return 0;
}