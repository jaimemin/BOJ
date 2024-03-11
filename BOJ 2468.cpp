#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;

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
	int N;
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
		}
	}

	int answer = 1;

	for (int height = 1; height <= N; height++)
	{
		int temp = 0;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (board[y][x] <= height || visited[y][x])
				{
					continue;
				}

				temp++;
				queue<pair<int, int>> q;
				q.push({ y, x });
				visited[y][x] = true;

				while (!q.empty())
				{
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nextY = curY + moveDir[k].y;
						int nextX = curX + moveDir[k].x;

						if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
						{
							continue;
						}

						if (visited[nextY][nextX] || board[nextY][nextX] <= height)
						{
							continue;
						}

						q.push({ nextY, nextX });
						visited[nextY][nextX] = true;
					}
				}
			}
		}

		cout << height << " " << temp << "\n";
		answer = max(answer, temp);
		memset(visited, false, sizeof(visited));
	}

	cout << answer << "\n";

	return 0;
}