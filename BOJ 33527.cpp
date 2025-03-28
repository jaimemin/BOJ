#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, X;
    cin >> N >> X;

    int M = 5 * X;

    vector<array<int, 5>> stops(N);

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> stops[i][j];
        }
    }

    vector<vector<int>> dp(M, vector<int>(M, INF));

    for (int i = 0; i < M; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 0; i < N; i++) 
    {
        array<int, 5> nodes;

        for (int j = 0; j < 5; j++)
        {
            nodes[j] = j * X + (stops[i][j] - 1);
        }

        for (int a = 0; a < 5; a++)
        {
            for (int b = a + 1; b < 5; b++)
            {
                int u = nodes[a], v = nodes[b];

                if (dp[u][v] > 1) 
                {
                    dp[u][v] = 1;
                    dp[v][u] = 1;
                }
            }
        }
    }

    for (int k = 0; k < M; k++) 
    {
        for (int i = 0; i < M; i++)
        {
            int dik = dp[i][k];

            if (dik == INF)
            {
                continue;
            }

            for (int j = 0; j < M; j++) 
            {
                if (dp[k][j] == INF)
                {
                    continue;
                }

                if (dp[i][j] > dik + dp[k][j])
                {
                    dp[i][j] = dik + dp[k][j];
                }
            }
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int U, V;
        cin >> U >> V;

        U--; V--;

        int answer = INF;
        array<int, 5> startRoutes, destRoutes;

        for (int j = 0; j < 5; j++) 
        {
            startRoutes[j] = j * X + (stops[U][j] - 1);
            destRoutes[j] = j * X + (stops[V][j] - 1);
        }

        for (int i = 0; i < 5; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                int cur = dp[startRoutes[i]][destRoutes[j]];

                if (cur < INF)
                {
                    answer = min(answer, cur + 1);
                }
            }
        }

        if (answer >= INF)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }

    return 0;
}