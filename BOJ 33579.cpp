#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1e5 + 1e2;

int parent[MAX];

int ranks[MAX];

int find(int x) 
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        return false;
    }

    if (ranks[a] < ranks[b])
    {
        parent[a] = b;
    }
    else 
    {
        parent[b] = a;

        if (ranks[a] == ranks[b])
        {
            ranks[a]++;
        }
    }

    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    if (M != N) 
    {
        cout << "NO\n";

        return 0;
    }

    vector<int> U(M), V(M), degree(N + 1, 0);
    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 1; i <= N; i++) 
    {
        parent[i] = i;
        ranks[i] = 0;
    }

    for (int i = 0; i < M; i++) 
    {
        cin >> U[i] >> V[i];

        degree[U[i]]++;
        degree[V[i]]++;

        adj[U[i]].push_back({ V[i], i });
        adj[V[i]].push_back({ U[i], i });
    }

    int cycleEid = -1;

    for (int i = 0; i < M; i++)
    {
        if (!merge(U[i], V[i]))
        {
            cycleEid = i;

            break;
        }
    }

    if (cycleEid < 0) 
    {
        cout << "NO\n";

        return 0;
    }

    int a = U[cycleEid], b = V[cycleEid];
    vector<int> parent(N + 1, -1);
    queue<int> q;
    parent[a] = a;
    q.push(a);

    while (!q.empty() && parent[b] == -1) 
    {
        int u = q.front(); 
        q.pop();

        for (auto pr : adj[u])
        {
            int v = pr.first;
            int eid = pr.second;

            if (eid == cycleEid)
            {
                continue;
            }

            if (parent[v] == -1)
            {
                parent[v] = u;

                q.push(v);
            }
        }
    }

    if (parent[b] == -1) 
    {
        cout << "NO\n";

        return 0;
    }

    vector<bool> inCycle(N + 1, false);
    int cur = b;

    while (true) 
    {
        inCycle[cur] = true;

        if (cur == a)
        {
            break;
        }

        cur = parent[cur];
    }

    while (!q.empty())
    {
        q.pop();
    }

    vector<bool> seen(N + 1, false);
    q.push(1);
    seen[1] = true;
    int seenCnt = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto pr : adj[u])
        {
            int v = pr.first;

            if (!seen[v]) 
            {
                seen[v] = true;
                seenCnt++;

                q.push(v);
            }
        }
    }

    if (seenCnt != N)
    {
        cout << "NO\n";

        return 0;
    }

    int bridgeCount = 0;

    for (int i = 0; i < M; i++)
    {
        bool iu = inCycle[U[i]];
        bool iv = inCycle[V[i]];

        if (iu ^ iv)
        {
            bridgeCount++;
        }
    }

    if (bridgeCount != 1) 
    {
        cout << "NO\n";

        return 0;
    }

    for (int i = 1; i <= N; i++) 
    {
        if (!inCycle[i] && degree[i] > 2)
        {
            cout << "NO\n";

            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}