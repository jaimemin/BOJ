#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1e3;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

int M, N;
int tomatoes[MAX][MAX];

bool isAllRipe(void)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			if (tomatoes[j][i] == -1)
			{
				continue;
			}

			if (tomatoes[j][i] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

int BFS(void)
{
	queue<pair<int, int>> q;

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			if (tomatoes[j][i] == 1)
			{
				q.push({ j, i });
			}
		}
	}

	int result = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
				{
					continue;
				}

				if (tomatoes[nextY][nextX])
				{
					continue;
				}

				tomatoes[nextY][nextX] = 1;
				q.push({ nextY, nextX });
			}
		}

		if (isAllRipe())
		{
			return result;
		}

		result++;
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			cin >> tomatoes[j][i];
		}
	}

	if (isAllRipe())
	{
		cout << 0 << "\n";

		return 0;
	}

	cout << BFS() << "\n";

	return 0;
}