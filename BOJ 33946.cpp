#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdint>
using namespace std;

long long combination2(int x)
{
    return 1LL * x * (x - 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;

    if (!(cin >> n >> m))
    {
        return 0;
    }

    vector<vector<int>> outAdj(n + 1);
    vector<int> inDeg(n + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        outAdj[u].push_back(v);
        inDeg[v]++;
        edges.emplace_back(u, v);
    }

    for (int v = 1; v <= n; v++)
    {
        sort(outAdj[v].begin(), outAdj[v].end());
    }

    long long answer = 0;

    for (int v = 1; v <= n; v++)
    {
        answer += combination2(inDeg[v]);
    }

    for (const auto e : edges)
    {
        int u = e.first;
        int v = e.second;

        if (outAdj[u].size() > outAdj[v].size())
        {
            swap(u, v);
        }

        long long commonCnt = 0;

        for (int child : outAdj[u])
        {
            if (binary_search(outAdj[v].begin(), outAdj[v].end(), child))
            {
                commonCnt++;
            }
        }

        answer -= commonCnt;
    }

    cout << answer << '\n';

    return 0;
}