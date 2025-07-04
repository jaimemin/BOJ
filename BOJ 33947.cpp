#include <iostream>
#include <vector>
using namespace std;

bool dfs(int cur, int parent,
    vector<vector<int>>& adj,
    vector<char>& isSpecial,
    int& extraEdgeCnt)
{
    int openChildCnt = 0;

    for (int next : adj[cur])
    {
        if (next == parent)
        {
            continue;
        }

        if (dfs(next, cur, adj, isSpecial, extraEdgeCnt))
        {
            ++openChildCnt;
        }
    }

    if (openChildCnt > 1)
    {
        extraEdgeCnt += openChildCnt - 1;

        return false;
    }

    return (openChildCnt + isSpecial[cur]) != 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<char> isSpecial(n + 1, 0);
    int anySpecial = 0;
    int root = 1;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x)
        {
            isSpecial[i] = 1;
            anySpecial = 1;
            root = i;
        }
    }

    if (!anySpecial)
    {
        cout << 0 << "\n";

        return 0;
    }

    int componentCnt = 0;

    if (dfs(root, 0, adj, isSpecial, componentCnt))
    {
        componentCnt++;
    }

    cout << componentCnt - 1 << "\n";

    return 0;
}