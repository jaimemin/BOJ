#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Command
{
    int y, x, n;
    char d;
};

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;

int K;

vector<vector<char>> board;

vector<vector<int>> subtree;

vector<Command> commands;

char idx2dir[4] = { 'D', 'U', 'R', 'L' };

int moveSteps(int y, int x, int d) 
{
    int cnt = 0;

    if (d == 2 || d == 3) 
    {
        while (true)
        {
            cnt++;

            int newX = x + moveDir[d].x * cnt;

            if (board[y][newX] == '#') 
            {
                return cnt - 1;
            }
        }
    }
    else
    {
        while (true)
        {
            cnt++;

            int newY = y + moveDir[d].y * cnt;

            if (board[newY][x] == '#')
            {
                return cnt - 1;
            }
        }
    }

    return 0;
}

void dfs(int y, int x)
{
    board[y][x] = '#';

    for (int k = 0; k < 4; k++) 
    {
        int cnt = moveSteps(y, x, k);

        if (cnt == 0)
        {
            continue;
        }

        int nextY = y + moveDir[k].y * cnt;
        int nextX = x + moveDir[k].x * cnt;

        dfs(nextY, nextX);
        subtree[y][x] += subtree[nextY][nextX];
        commands.push_back({ y, x, subtree[nextY][nextX], idx2dir[k] });
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    board.assign(N + 2, vector<char>(M + 2, '#'));
    subtree.assign(N + 2, vector<int>(M + 2, 0));

    for (int i = 1; i <= N; i++) 
    {
        string line;
        cin >> line;

        for (int j = 1; j <= M; j++) 
        {
            board[i][j] = line[j - 1];
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++)
        {
            if (board[i][j] == '.')
            {
                subtree[i][j] = 1;
            }
            else
            {
                K++;
            }
        }
    }

    int R, C;
    cin >> R >> C;

    dfs(R, C);

    int nonWallCount = N * M - K;

    if (subtree[R][C] != nonWallCount)
    {
        cout << "NO\n";

        return 0;
    }

    cout << "YES\n";
    cout << nonWallCount - 1 << "\n";
    reverse(commands.begin(), commands.end());

    for (int i = 0; i < nonWallCount - 1; i++)
    {
        cout << commands[i].y << " " << commands[i].x << " " << commands[i].n << " " << commands[i].d << "\n";
    }

    return 0;
}
