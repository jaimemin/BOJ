#include <iostream>
#include <queue>
using namespace std;

const int MAX = 500;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;

int board[MAX][MAX];

bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] || !board[i][j])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			int temp = 0;
			cnt++;

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				temp++;

				for (int k = 0; k < 4; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
					{
						continue;
					}

					if (visited[nextY][nextX] || !board[nextY][nextX])
					{
						continue;
					}

					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}

			result = max(result, temp);
		}
	}

	cout << cnt << "\n";
	cout << result << "\n";

	return 0;
}