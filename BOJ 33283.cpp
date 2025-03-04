#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200200;

int N, M;

int logN;

int parent[MAX];

int ranks[MAX];

vector<vector<int>> mst;

vector<int> depth;

vector<vector<int>> parentTable;

void init(int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int a) 
{
    if (parent[a] != a)
    {
        parent[a] = find(parent[a]);
    }

    return parent[a];
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
        swap(a, b);
    }

    parent[b] = a;

    if (ranks[a] == ranks[b])
    {
        ranks[a]++;
    }

    return true;
}

void dfs(int cur, int parent, int d) 
{
    depth[cur] = d;
    parentTable[0][cur] = parent;

    for (auto next : mst[cur])
    {
        if (next == parent)
        {
            continue;
        }

        dfs(next, cur, d + 1);
    }
}

int lca(int a, int b) 
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    int d = depth[a] - depth[b];

    for (int i = 0; i < logN; i++) 
    {
        if (d & (1 << i))
        {
            a = parentTable[i][a];
        }
    }

    if (a == b)
    {
        return a;
    }

    for (int i = logN - 1; i >= 0; i--)
    {
        if (parentTable[i][a] != parentTable[i][b]) 
        {
            a = parentTable[i][a];
            b = parentTable[i][b];
        }
    }

    return parentTable[0][a];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    vector<pair<int, int>> edges;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({ u, v });
    }

    init(N);

    mst.assign(N + 1, vector<int>());

    for (int i = 0; i < M; i++) 
    {
        int a = edges[i].first;
        int b = edges[i].second;

        if (merge(a, b)) 
        {
            mst[a].push_back(b);
            mst[b].push_back(a);
        }
    }

    depth.assign(N + 1, 0);
    logN = 0;

    while ((1 << logN) <= N)
    {
        logN++;
    }

    parentTable.assign(logN, vector<int>(N + 1, 0));

    dfs(1, 0, 0);

    for (int i = 1; i < logN; i++) 
    {
        for (int node = 1; node <= N; node++) 
        {
            int p = parentTable[i - 1][node];

            parentTable[i][node] = (p == 0 ? 0 : parentTable[i - 1][p]);
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) 
    {
        int u, v;
        cin >> u >> v;

        int anc = lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[anc];

        cout << (dist > 0 ? dist - 1 : 0) << "\n";
    }

    return 0;
}
