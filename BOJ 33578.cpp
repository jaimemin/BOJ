#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = { {1,0 }, {-1, 0}, {0, 1}, {0, -1} };

vector<int> bfs( vector<string>& grid, int startY, int startX, int N, int M) 
{
    const int INF = INT_MAX;
    vector<int> dist(N * M, INF);
    queue<int> q;

    int startIdx = startY * M + startX;
    dist[startIdx] = 0;
    q.push(startIdx);

    while (!q.empty())
    {
        int curIdx = q.front(); 
        q.pop();

        int curY = curIdx / M;
        int curX = curIdx % M;
        int curDist = dist[curIdx];

        for (int k = 0; k < 4; k++) 
        {
            int newY = curY + moveDir[k].y;
            int newX = curX + moveDir[k].x;

            if (newY < 0 || newY >= N || newX < 0 || newX >= M)
            {
                continue;
            }

            if (grid[newY][newX] == '#')
            {
                continue;
            }

            int newIdx = newY * M + newX;

            if (dist[newIdx] > curDist + 1) 
            {
                dist[newIdx] = curDist + 1;

                q.push(newIdx);
            }
        }
    }

    return dist;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> grid[i];
    }

    int startSY = -1, startSX = -1;
    int startJY = -1, startJX = -1;
    vector<pair<int, int>> teacherPositions;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c = grid[i][j];

            if (c == 'S') 
            {
                startSY = i; 
                startSX = j;
            }
            else if (c == 'J')
            {
                startJY = i;
                startJX = j;
            }
            else if (c == 'T') 
            {
                teacherPositions.emplace_back(i, j);
            }
        }
    }

    vector<int> distFromJ = bfs(grid, startJY, startJX, N, M);
    vector<int> distFromS = bfs(grid, startSY, startSX, N, M);

    long long answer = LLONG_MAX;
    int idxS = startSY * M + startSX;

    if (distFromJ[idxS] != INT_MAX)
    {
        answer = min(answer, distFromJ[idxS] * 2LL);
    }

    for (auto tp : teacherPositions)
    {
        int ty = tp.first;
        int tx = tp.second;
        int idxT = ty * M + tx;

        if (distFromJ[idxT] != INT_MAX && distFromS[idxT] != INT_MAX)
        {
            long long timeViaTeacher = distFromJ[idxT] * 2LL + distFromS[idxT];

            answer = min(answer, timeViaTeacher);
        }
    }

    if (answer == LLONG_MAX) 
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }

    return 0;
}