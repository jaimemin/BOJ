#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 2000;

bool adjacency[MAX + 1][MAX + 1];

vector<int> inNeighbors[MAX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            adjacency[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adjacency[u][v] = true;
        inNeighbors[v].push_back(u);
    }

    long long answer = 0;

    for (int z = 1; z <= N; z++)
    {
        vector<int>& parents = inNeighbors[z];
        int k = parents.size();

        if (k < 2)
        {
            continue;
        }

        for (int i = 0; i < k; i++)
        {
            int x = parents[i];

            for (int j = i + 1; j < k; j++)
            {
                int y = parents[j];

                if (!adjacency[x][y] && !adjacency[y][x])
                {
                    answer++;
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}