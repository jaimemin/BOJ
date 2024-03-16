#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
	int cnt;
} State;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int result;

string board[MAX];

bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int L, W;
	cin >> L >> W;

	for (int y = 0; y < L; y++)
	{
		cin >> board[y];
	}

	for (int y = 0; y < L; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (board[y][x] == 'W')
			{
				continue;
			}

			memset(visited, false, sizeof(visited));
			queue<State> q;
			q.push({ y, x, 0 });
			visited[y][x] = true;

			while (!q.empty())
			{
				int curY = q.front().y;
				int curX = q.front().x;
				int cnt = q.front().cnt;
				q.pop();

				result = max(result, cnt);

				for (int k = 0; k < 4; k++)
				{
					int nextY = curY + moveDir[k].y;
					int nextX = curX + moveDir[k].x;

					if (nextY < 0 || nextY >= L || nextX < 0 || nextX >= W)
					{
						continue;
					}

					if (visited[nextY][nextX] || board[nextY][nextX] == 'W')
					{
						continue;
					}

					visited[nextY][nextX] = true;
					q.push({ nextY, nextX, cnt + 1 });
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}