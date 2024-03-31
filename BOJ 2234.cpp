#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int N, M;

int board[MAX][MAX];

vector<int> answer(3, 0);

void func()
{
	bool visited[MAX][MAX] = { false, };

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (visited[y][x])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ y, x });
			visited[y][x] = true;
			int cnt = 0;

			while (!q.empty())
			{
				int curY = q.front().first;
				int curX = q.front().second;
				q.pop();

				cnt++;

				for (int k = 0; k < 4; k++)
				{
					if (board[curY][curX] & (1 << k))
					{
						continue;
					}

					int nextY = curY + moveDir[k].y;
					int nextX = curX + moveDir[k].x;

					if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
					{
						continue;
					}

					if (visited[nextY][nextX])
					{
						continue;
					}

					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}

			answer[2] = max(answer[2], cnt);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
		}
	}

	bool visited[MAX][MAX] = { false, };

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (visited[y][x])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ y, x });
			visited[y][x] = true;
			int cnt = 0;
			answer[0]++;

			while (!q.empty())
			{
				int curY = q.front().first;
				int curX = q.front().second;
				q.pop();
				cnt++;

				for (int k = 0; k < 4; k++)
				{
					if (board[curY][curX] & (1 << k))
					{
						continue;
					}

					int nextY = curY + moveDir[k].y;
					int nextX = curX + moveDir[k].x;

					if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
					{
						continue;
					}

					if (visited[nextY][nextX])
					{
						continue;
					}

					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}

			answer[1] = max(answer[1], cnt);
		}
	}

	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((1 << k) & board[y][x])
				{
					board[y][x] -= (1 << k);
					func();
					board[y][x] += (1 << k);
				}
			}
		}
	}

	for (int cnt : answer)
	{
		cout << cnt << "\n";
	}

	return 0;
}