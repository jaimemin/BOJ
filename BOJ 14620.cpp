#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 10;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[5] = { {1,0 }, {-1, 0}, {0, 1}, {0, -1}, {0, 0} };

int N;

int result = INT_MAX;

int garden[MAX][MAX];

bool visited[MAX][MAX];

void func(int y, int x, int cnt, int total)
{
	if (cnt == 3)
	{
		result = min(result, total);

		return;
	}

	for (int i = y; i < N - 1; i++)
	{
		for (int j = (i == y ? x : 1); j < N - 1; j++)
		{
			bool flag = true;

			for (int k = 0; k < 5; k++)
			{
				int nextY = i + moveDir[k].y;
				int nextX = j + moveDir[k].x;

				if (visited[nextY][nextX])
				{
					flag = false;

					break;
				}
			}

			if (!flag)
			{
				continue;
			}

			int sum = 0;

			for (int k = 0; k < 5; k++)
			{
				int nextY = i + moveDir[k].y;
				int nextX = j + moveDir[k].x;

				sum += garden[nextY][nextX];
				visited[nextY][nextX] = true;
			}

			func(i, j + 1, cnt + 1, total + sum);

			for (int k = 0; k < 5; k++)
			{
				int nextY = i + moveDir[k].y;
				int nextX = j + moveDir[k].x;

				visited[nextY][nextX] = false;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> garden[y][x];
		}
	}

	func(1, 1, 0, 0);

	cout << result << "\n";

	return 0;
}