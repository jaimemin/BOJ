#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, T;
    cin >> N >> T;

    vector<vector<int>> adjList(N + 1);

    for (int i = 0; i < N - 1; i++) 
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> catTime(T + 1);

    for (int t = 1; t <= T; t++) 
    {
        cin >> catTime[t];
    }

    vector<int> dpPrev(N + 1, 0), dpCurr(N + 1, 0);

    for (int v = 1; v <= N; v++)
    {
        dpPrev[v] = (catTime[1] == v ? 1 : 0);
    }

    for (int t = 2; t <= T; t++)
    {
        for (int v = 1; v <= N; v++) 
        {
            int bestPrev = dpPrev[v];

            for (int neighbor : adjList[v])
            {
                bestPrev = max(bestPrev, dpPrev[neighbor]);
            }

            dpCurr[v] = bestPrev + (catTime[t] == v ? 1 : 0);
        }

        dpPrev.swap(dpCurr);
    }

    int answer = 0;

    for (int v = 1; v <= N; v++) 
    {
        answer = max(answer, dpPrev[v]);
    }

    cout << answer << "\n";

    return 0;
}