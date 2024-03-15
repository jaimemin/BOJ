#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int board[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
		}
	}

	int duration = 0;
	int area = 0;

	while (true)
	{
		bool visited[MAX][MAX] = { false, };
		set<pair<int, int>> boundaries;
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty())
		{
			int curY = q.front().first;
			int curX = q.front().second;
			q.pop();

			if (board[curY][curX])
			{
				boundaries.insert({ curY, curX });

				continue;
			}

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

				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
			}
		}

		if (boundaries.empty())
		{
			break;
		}

		area = boundaries.size();

		for (pair<int, int> p : boundaries)
		{
			board[p.first][p.second] = 0;
		}

		duration++;
	}

	cout << duration << "\n" << area << "\n";

	return 0;
}