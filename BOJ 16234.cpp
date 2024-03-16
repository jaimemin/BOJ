#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, L, R;

int board[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L >> R;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
		}
	}

	int result = 0;

	while (true)
	{
		bool flag = false;
		bool visited[MAX][MAX] = { false, };

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (visited[y][x])
				{
					continue;
				}

				visited[y][x] = true;
				queue<pair<int, int>> q;
				q.push({ y, x });
				vector<pair<int, int>> v;

				while (!q.empty())
				{
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();
					v.push_back({ curY, curX });

					for (int k = 0; k < 4; k++)
					{
						int nextY = curY + moveDir[k].y;
						int nextX = curX + moveDir[k].x;

						if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
						{
							continue;
						}

						if (visited[nextY][nextX])
						{
							continue;
						}

						int diff = abs(board[curY][curX] - board[nextY][nextX]);

						if (!(diff >= L && diff <= R))
						{
							continue;
						}

						flag = true;
						visited[nextY][nextX] = true;
						q.push({ nextY, nextX });
					}
				}

				int sum = 0;

				for (pair<int, int> p : v)
				{
					sum += board[p.first][p.second];
				}

				for (pair<int, int> p : v)
				{
					board[p.first][p.second] = sum / v.size();
				}
			}
		}

		if (!flag) 
		{
			break;
		}

		result++;
	}

	cout << result << "\n";

	return 0;
}