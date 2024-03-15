#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 8;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;

int result;

int board[MAX][MAX];

int copyBoard[MAX][MAX];

void copy()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			copyBoard[y][x] = board[y][x];
		}
	}
}

void calculateSafeArea()
{
	copy();
	queue<pair<int, int>> q;
	
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (copyBoard[y][x] == 2)
			{
				q.push({ y, x });
			}
		}
	}

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

			if (copyBoard[nextY][nextX])
			{
				continue;
			}

			copyBoard[nextY][nextX] = 2;
			q.push({ nextY, nextX });
		}
	}

	int cnt = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cnt += (copyBoard[y][x] == 0);
		}
	}

	result = max(result, cnt);
}

void func(int y, int x, int cnt)
{
	if (cnt == 3)
	{
		calculateSafeArea();

		return;
	}

	if (y < 0 || y >= N || x < 0 || x >= M)
	{
		return;
	}

	for (int i = y; i < N; i++)
	{
		for (int j = (i == y ? x : 0); j < M; j++)
		{
			if (!board[i][j])
			{
				board[i][j] = 1;
				func(j == M - 1 ? i + 1 : i, j == M - 1 ? 0 : j + 1, cnt + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> board[y][x];
		}
	}

	func(0, 0, 0);

	cout << result << "\n";

	return 0;
}