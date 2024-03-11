#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int board[MAX][MAX];

bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;

		for (int k = 0; k < K; k++)
		{
			int x, y;
			cin >> x >> y;

			board[y][x] = 1;
		}

		int answer = 0;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (visited[y][x] || !board[y][x])
				{
					continue;
				}

				answer++;
				queue<pair<int, int>> q;
				q.push({ y, x });
				visited[y][x] = true;

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

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

						q.push({ nextY, nextX });
						visited[nextY][nextX] = true;
					}
				}
			}
		}

		cout << answer << "\n";

		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}