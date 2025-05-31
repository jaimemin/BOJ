#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 16;

int N, M, K;

vector<int> adjList[MAX];

int distMatrix[MAX][MAX];

int moveTo[MAX][MAX];

int totalStates, totalBm;

vector<int> dp;

vector<char> visitedState;

bool infiniteSurvival;

int dfsSurvival(int pos, int bm) 
{
    int stateId = pos * totalBm + bm;

    if (visitedState[stateId] == 1) 
    {
        infiniteSurvival = true;

        return 0;
    }

    if (visitedState[stateId] == 2)
    {
        return dp[stateId];
    }

    visitedState[stateId] = 1;
    int bestTime = 0;
    int newBm = 0;

    for (int v = 0; v < N; v++) 
    {
        if (bm & (1 << v)) 
        {
            int u = moveTo[v][pos];

            newBm |= (1 << u);
        }
    }

    if (newBm & (1 << pos)) 
    {
        bestTime = max(bestTime, 1);
    }
    else 
    {
        int result = dfsSurvival(pos, newBm);

        if (infiniteSurvival)
        {
            return 0;
        }

        bestTime = max(bestTime, 1 + result);
    }

    for (int next : adjList[pos]) 
    {
        if (bm & (1 << next))
        {
            continue;
        }

        int newBm = 0;

        for (int v = 0; v < N; v++) 
        {
            if (bm & (1 << v)) 
            {
                int u = moveTo[v][next];

                newBm |= (1 << u);
            }
        }

        if (newBm & (1 << next)) 
        {
            bestTime = max(bestTime, 1);
        }
        else
        {
            int result = dfsSurvival(next, newBm);

            if (infiniteSurvival)
            {
                return 0;
            }

            bestTime = max(bestTime, 1 + result);
        }
    }

    visitedState[stateId] = 2;
    dp[stateId] = bestTime;

    return bestTime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) 
    {
        int a, b;
        cin >> a >> b;

        --a; --b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            distMatrix[i][j] = -1;
        }

        queue<int> q;
        q.push(i);
        distMatrix[i][i] = 0;

        while (!q.empty()) 
        {
            int v = q.front();
            q.pop();

            for (int w : adjList[v]) 
            {
                if (distMatrix[i][w] < 0)
                {
                    distMatrix[i][w] = distMatrix[i][v] + 1;

                    q.push(w);
                }
            }
        }
    }

    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++) 
        {
            int candidate = -1;

            for (int w : adjList[v]) 
            {
                if (distMatrix[w][u] == distMatrix[v][u] - 1)
                {
                    if (candidate < 0 || w < candidate)
                    {
                        candidate = w;
                    }
                }
            }

            moveTo[v][u] = candidate;
        }
    }

    int initialBm = 0;

    for (int i = 0; i < K; i++) 
    {
        int p;
        cin >> p;

        --p;
        initialBm |= (1 << p);
    }

    totalBm = 1 << N;
    totalStates = N * totalBm;
    dp.assign(totalStates, 0);
    visitedState.assign(totalStates, 0);
    infiniteSurvival = false;

    int answer = dfsSurvival(0, initialBm);

    if (infiniteSurvival) 
    {
        cout << "DaeHeungMin\n";
    }
    else 
    {
        cout << answer << "\n";
    }

    return 0;
}