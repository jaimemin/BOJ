#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const long long MOD = 1000000007;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<long long> D(N + 1, 0);
    D[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        cin >> D[i];
    }

    vector<long long> candidateProduct(N + 1, 1);
    vector<long long> candidateNonTightProduct(N + 1, 1);
    vector<int> candidateEdgeCount(N + 1, 0);
    vector<vector<int>> candidateGraphForConnectivity(N + 1);

    long long nonCandidateProduct = 1;

    for (int i = 0; i < M; i++) 
    {
        int u, v;
        long long l, r;
        cin >> u >> v >> l >> r;

        int low = u, high = v;

        if (D[u] > D[v]) 
        {
            low = v;
            high = u;
        }

        long long diff = D[high] - D[low]; 
        long long lowBound = max(l, diff);

        if (lowBound > r)
        {
            cout << 0 << "\n";

            return 0;
        }

        long long total = (r - lowBound + 1) % MOD;

        if (D[low] < D[high] && (diff >= l && diff <= r)) 
        {
            candidateEdgeCount[high]++;
            candidateProduct[high] = (candidateProduct[high] * total) % MOD;

            long long nonTight = (total - 1 + MOD) % MOD;
            candidateNonTightProduct[high] = (candidateNonTightProduct[high] * nonTight) % MOD;

            candidateGraphForConnectivity[low].push_back(high);
        }
        else
        {
            nonCandidateProduct = (nonCandidateProduct * total) % MOD;
        }
    }

    queue<int>q;
    q.push(1);

    vector<bool> visited(N + 1, false);
    visited[1] = true;

    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (int next : candidateGraphForConnectivity[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;

                q.push(next);
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (!visited[i]) 
        {
            cout << 0 << "\n";

            return 0;
        }

        if (candidateEdgeCount[i] == 0)
        {
            cout << 0 << "\n";

            return 0;
        }
    }

    long long candidateTotal = 1;

    for (int i = 2; i <= N; i++)
    {
        long long ways = ((candidateProduct[i] - candidateNonTightProduct[i]) % MOD + MOD) % MOD;

        candidateTotal = (candidateTotal * ways) % MOD;
    }

    long long answer = (nonCandidateProduct * candidateTotal) % MOD;
    cout << answer << "\n";

    return 0;
}