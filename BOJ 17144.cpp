#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int R, C, T;

int arr[MAX][MAX];

int ccw[4] = { 2, 0, 3, 1 };

int cw[4] = { 2, 1, 3, 0 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;

	int airY = -1, airX = -1, airY2 = -1, airX2 = -1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
			{
				if (airY == -1)
				{
					airY = i, airX = j;
				}
				else
				{
					airY2 = i, airX2 = j;
				}
			}
		}
	}

	for (int t = 0; t < T; t++)
	{
		queue<pair<int, int>> q;

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] >= 1)
				{
					q.push({ i, j });
				}
			}
		}

		int copyArr[MAX][MAX] = { 0, };

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				copyArr[i][j] = arr[i][j];
			}
		}

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			int temp = copyArr[y][x] / 5;
			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C)
				{
					if (copyArr[nextY][nextX] >= 0)
					{
						arr[nextY][nextX] += temp;
						arr[y][x] -= temp;
					}
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				copyArr[i][j] = arr[i][j];
			}
		}

		int y = airY;
		int x = airX + 1;
		arr[y][x] = 0;

		for (int i = 0; i < 4; i++)
		{
			while (1)
			{
				int nextY = y + moveDir[ccw[i]].y;
				int nextX = x + moveDir[ccw[i]].x;

				if (nextY == airY && nextX == airX)
				{
					break;
				}

				if (!(0 <= nextY && nextY < R && 0 <= nextX && nextX < C))
				{
					break;
				}

				arr[nextY][nextX] = copyArr[y][x];
				y = nextY;
				x = nextX;
			}
		}

		y = airY2;
		x = airX2 + 1;
		arr[y][x] = 0;

		for (int i = 0; i < 4; i++)
		{
			while (1)
			{
				int nextY = y + moveDir[cw[i]].y;
				int nextX = x + moveDir[cw[i]].x;

				if (nextY == airY2 && nextX == airX2)
				{
					break;
				}

				if (!(0 <= nextY && nextY < R && 0 <= nextX && nextX < C))
				{
					break;
				}

				arr[nextY][nextX] = copyArr[y][x];
				y = nextY;
				x = nextX;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] >= 1)
			{
				result += arr[i][j];
			}
		}
	}

	cout << result << "\n";

	return 0;
}