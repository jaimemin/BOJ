#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<vector<int>> adj;

vector<long long> a, subtreeSum;

long long dfs(int u, int parent) 
{
    long long sum = a[u];

    for (int v : adj[u])
    {
        if (v == parent)
        {
            continue;
        }

        sum += dfs(v, u);
    }

    subtreeSum[u] = sum;

    return sum;
}

long long extraTransfers = 0;

void dfsTransfer(int u, int parent) 
{
    long long childTotal = 0, best = 0;

    for (int v : adj[u]) 
    {
        if (v == parent)
        {
            continue;
        }

        childTotal += subtreeSum[v];
        best = max(best, subtreeSum[v]);
        dfsTransfer(v, u);
    }

    if (u != 1 && childTotal > 0) 
    {
        extraTransfers += (childTotal - best);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    a.resize(N + 1);
    subtreeSum.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        cin >> a[i];
    }

    a[1] = 0;
    adj.resize(N + 1);

    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    dfsTransfer(1, 0);

    long long baseline = subtreeSum[1];

    cout << 2 * (baseline + extraTransfers) << "\n";

    return 0;
}