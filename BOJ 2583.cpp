#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool board[MAX][MAX];

bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, N, K;
	cin >> M >> N >> K;

	for (int k = 0; k < K; k++)
	{
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		for (int i = y; i < y2; i++)
		{
			for (int j = x; j < x2; j++)
			{
				board[i][j] = true;
			}
		}
	}

	vector<int> areas;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x] || board[y][x])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ y, x });
			visited[y][x] = true;
			int area = 0;

			while (!q.empty())
			{
				int curY = q.front().first;
				int curX = q.front().second;
				q.pop();

				area++;

				for (int k = 0; k < 4; k++)
				{
					int nextY = curY + moveDir[k].y;
					int nextX = curX + moveDir[k].x;

					if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
					{
						continue;
					}

					if (visited[nextY][nextX] || board[nextY][nextX])
					{
						continue;
					}

					q.push({ nextY, nextX });
					visited[nextY][nextX] = true;
				}
			}

			areas.push_back(area);
		}
	}

	sort(areas.begin(), areas.end());

	cout << areas.size() << "\n";

	for (int i = 0; i < areas.size(); i++)
	{
		cout << areas[i];

		if (i != areas.size() - 1)
		{
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}