#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX / 4;

struct Edge
{
    int to;
    long long w;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<vector<Edge>> adjacency(n + 1);
    vector<tuple<int, int, long long>> edgeList;

    for (int i = 0; i < n - 1; i++) 
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;

        adjacency[a].push_back({ b, w });
        adjacency[b].push_back({ a, w });
        edgeList.emplace_back(a, b, w);
    }

    vector<int> defenders(k);

    for (int i = 0; i < k; i++)
    {
        cin >> defenders[i];
    }

    vector<long long> dd(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int p : defenders) 
    {
        dd[p] = 0;

        pq.emplace(0, p);
    }

    while (!pq.empty()) 
    {
        auto [distU, u] = pq.top();
        pq.pop();

        if (distU > dd[u])
        {
            continue;
        }

        for (auto e : adjacency[u]) 
        {
            int v = e.to;
            long long nd = distU + e.w;

            if (nd < dd[v]) 
            {
                dd[v] = nd;

                pq.emplace(nd, v);
            }
        }
    }

    vector<long long> dp(n + 1, INF);
    dp[1] = 0;

    vector<bool> visited(n + 1, false);
    visited[1] = true;

    vector<int> stk;
    stk.push_back(1);

    while (!stk.empty()) 
    {
        int u = stk.back();
        stk.pop_back();

        for (auto e : adjacency[u]) 
        {
            int v = e.to;

            if (!visited[v]) 
            {
                visited[v] = true;
                dp[v] = dp[u] + e.w;

                stk.push_back(v);
            }
        }
    }

    long long answer = 0;

    for (int u = 1; u <= n; u++)
    {
        if (dp[u] < dd[u])
        {
            answer = max(answer, dd[u]);
        }
    }

    for (auto ed : edgeList)
    {
        int u, v;
        long long w;

        tie(u, v, w) = ed;

        if (dp[u] > dp[v])
        {
            swap(u, v);
        }

        long long dpRoot = dp[u];
        long long du = dd[u];
        long long dv = dd[v];
        long long nVal = dv - du + w; 
        long long x1 = nVal / 2;
        long long x2 = (nVal + 1) / 2;

        for (long long x : {x1, x2})
        {
            if (x < 1 || x > w - 1)
            {
                continue;
            }

            long long parkTime = dpRoot + x;
            long long defTime = min(du + x, dv + (w - x));

            if (parkTime < defTime) 
            {
                answer = max(answer, defTime);
            }
        }
    }

    cout << answer << "\n";

    return 0;
}