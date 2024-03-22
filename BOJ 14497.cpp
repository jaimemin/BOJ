#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 300;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[5] = { {1,0 }, {-1, 0}, {0, 1}, {0, -1} };

string board[MAX];

int visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	int y, x, y2, x2;
	cin >> y >> x >> y2 >> x2;

	for (int y = 0; y < N; y++)
	{
		cin >> board[y];
	}

	int result = 0;
	queue<pair<int, int>> q;
	q.push({ y - 1, x - 1 });
	visited[y - 1][x - 1] = 1;

	while (board[y2 - 1][x2 - 1] != '0')
	{
		queue<pair<int, int>> nextQ;
		result++;

		while (!q.empty())
		{
			int curY = q.front().first;
			int curX = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
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

				visited[nextY][nextX] = result;

				if (board[nextY][nextX] == '0')
				{
					q.push({ nextY, nextX });

					continue;
				}

				nextQ.push({ nextY, nextX });
				board[nextY][nextX] = '0';
			}
		}

		q = nextQ;
	}

	cout << visited[y2 - 1][x2 - 1] << "\n";

	return 0;
}