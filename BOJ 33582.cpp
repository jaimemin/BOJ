#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX / 4;

int N;

vector<vector<int>> adjList;

vector<long long> durability;

vector<long long> downValue;

vector<long long> upValue;

void dfsDown(int node, int parent)
{
    downValue[node] = durability[node];

    for (int next : adjList[node]) 
    {
        if (next == parent)
        {
            continue;
        }

        dfsDown(next, node);
        downValue[node] = max(downValue[node], downValue[next] + 1);
    }
}

void dfsUp(int node, int parent)
{
    long long best = -INF, secondBest = -INF;

    for (int next : adjList[node]) 
    {
        if (next == parent)
        {
            continue;
        }

        long long val = downValue[next];

        if (val >= best) 
        {
            secondBest = best;
            best = val;
        }
        else if (val > secondBest) 
        {
            secondBest = val;
        }
    }

    for (int next : adjList[node])
    {
        if (next == parent)
        {
            continue;
        }

        long long viaParent = (upValue[node] < 0 ? -INF : upValue[node] + 1);
        long long viaSelf = durability[node] + 1;
        long long viaSibling;

        if (downValue[next] == best) 
        {
            viaSibling = secondBest + 2;
        }
        else
        {
            viaSibling = best + 2;
        }

        upValue[next] = max({ viaParent, viaSelf, viaSibling });
        dfsUp(next, node);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    adjList.assign(N + 1, {});
    durability.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) 
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> durability[i];
    }

    downValue.assign(N + 1, -INF);
    upValue.assign(N + 1, -INF);

    dfsDown(1, 0);
    upValue[1] = -INF;
    dfsUp(1, 0);

    long long answer = INF;

    for (int i = 1; i <= N; i++)
    {
        long long required = max(downValue[i], upValue[i]);

        answer = min(answer, required);
    }

    cout << answer << "\n";

    return 0;
}