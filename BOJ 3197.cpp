#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1500;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;

vector<pair<int, int>> swans;

string board[MAX];

bool canSwansMeet()
{
	queue<pair<int, int>> q;
	q.push(swans[0]);

	bool visited[MAX][MAX] = { false, };
	visited[swans[0].first][swans[0].second] = true;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		cout << curY << " " << curX << "\n";

		if (curY == swans[1].first && curX == swans[1].second)
		{
			return true;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
			{
				continue;
			}

			if (visited[nextY][nextX] || board[nextY][nextX] == 'X')
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		cin >> board[y];

		for (int x = 0; x < C; x++)
		{
			if (board[y][x] == 'L')
			{
				swans.push_back({ y, x });
			}
		}
	}

	int result = 0;

	while (canSwansMeet())
	{
		vector<pair<int, int>> v;

		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				if (board[y][x] != 'X')
				{
					continue;
				}

				bool adjacentToWater = false;

				for (int k = 0; k < 4; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
					{
						continue;
					}

					if (board[nextY][nextX] == '.')
					{
						adjacentToWater = true;

						break;
					}
				}

				if (adjacentToWater)
				{
					v.push_back({ y, x });
				}
			}
		}

		for (pair<int, int> p : v)
		{
			board[p.first][p.second] = '.';
		}

		result++;
	}

	cout << result << "\n";

	return 0;
}