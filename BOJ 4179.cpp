#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1000;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;

pair<int, int> start;

string board[MAX];

bool visited[MAX][MAX];

vector<pair<int, int>> fires;

int func(void)
{
	queue<pair<int, int>> q;
	q.push(start);

	queue<pair<int, int>> flame;

	for (pair<int, int> fire : fires)
	{
		flame.push(fire);
	}

	int result = 0;

	while (!q.empty())
	{
		int flameSize = flame.size();

		for (int i = 0; i < flameSize; i++)
		{
			int y = flame.front().first;
			int x = flame.front().second;
			flame.pop();

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				{
					continue;
				}

				if (board[nextY][nextX] == '.' || board[nextY][nextX] == 'J')
				{
					board[nextY][nextX] = 'F';
					flame.push({ nextY, nextX });
				}
			}
		}

		int curSize = q.size();

		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
			{
				return result + 1;
			}

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				{
					continue;
				}

				if (visited[nextY][nextX])
				{
					continue;
				}

				if (board[nextY][nextX] == '.')
				{
					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}
		}

		result++;
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		cin >> board[y];

		for (int x = 0; x < board[y].size(); x++)
		{
			if (board[y][x] == 'J')
			{
				start = { y, x };
			}
			else if (board[y][x] == 'F')
			{
				fires.push_back({ y, x });
			}
		}
	}

	int result = func();

	cout << (result == -1 ? "IMPOSSIBLE" : to_string(result)) << "\n";

	return 0;
}