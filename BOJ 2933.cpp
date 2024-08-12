#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    int y, x;
} Dir;

int R, C;

vector<string> cave;

Dir moveDir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void throwStick(int row, bool fromLeft) 
{
    int col;

    if (fromLeft) {
        col = 0;

        while (col < C && cave[row][col] == '.')
        {
            col++;
        }
    }
    else 
    {
        col = C - 1;

        while (col >= 0 && cave[row][col] == '.')
        {
            col--;
        }
    }

    if (col >= 0 && col < C) 
    {
        cave[row][col] = '.';
    }
}

void bfs(int startY, int startX, vector<vector<bool>>& visited) 
{
    queue<pair<int, int>> q;
    q.push({ startY, startX });
    visited[startY][startX] = true;

    while (!q.empty()) 
    {
        pair<int, int> p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();

        for (int k = 0; k < 4; k++) 
        {
            int nextY = y + moveDir[k].y;
            int nextX = x + moveDir[k].x;

            if (nextY >= 0 && nextY < R
                && nextX >= 0 && nextX < C
                && cave[nextY][nextX] == 'x' && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                q.push({ nextY, nextX });
            }
        }
    }
}

void dropCluster() 
{
    vector<pair<int, int>> cluster;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<int> bottom(R, -1);

    for (int i = 0; i < C; i++) 
    {
        if (cave[R - 1][i] == 'x' && !visited[R - 1][i]) 
        {
            bfs(R - 1, i, visited);
        }
    }

    for (int i = 0; i < R; i++) 
    {
        for (int j = 0; j < C; j++) 
        {
            if (cave[i][j] == 'x' && !visited[i][j])
            {
                cluster.push_back({ i, j });
                cave[i][j] = '.';
                bottom[j] = max(bottom[j], i);
            }
        }
    }

    if (cluster.empty())
    {
        return;
    }

    int dropHeight = R;

    for (pair<int, int> p : cluster)
    {
        int y = p.first;
        int x = p.second;
        int height = 0;

        while (y + height + 1 < R && cave[y + height + 1][x] == '.')
        {
            height++;
        }

        dropHeight = min(dropHeight, height);
    }

    for (pair<int, int> p : cluster) 
    {
        cave[p.first + dropHeight][p.second] = 'x';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    cave.resize(R);

    for (int i = 0; i < R; i++) 
    {
        cin >> cave[i];
    }

    int N;
    cin >> N;
    vector<int> heights(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> heights[i];
    }

    bool fromLeft = true;

    for (int i = 0; i < N; i++)
    {
        int row = R - heights[i];
        throwStick(row, fromLeft);
        dropCluster();
        fromLeft = !fromLeft;
    }

    for (int i = 0; i < R; i++) 
    {
        cout << cave[i] << "\n";
    }

    return 0;
}
