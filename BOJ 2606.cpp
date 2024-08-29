#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100 + 1;

vector<int> graph[MAX];

bool visited[MAX];

void func(int node, int& cnt)
{
    visited[node] = true;

    for (int next : graph[node])
    {
        if (visited[next])
        {
            continue;
        }

        func(next, ++cnt);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, C;
    cin >> N >> C;

    for (int i = 0; i < C; i++) 
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    func(1, cnt);

    cout << cnt << "\n";

    return 0;
}
