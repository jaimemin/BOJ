#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[8] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 },{ 1, -1 },{ 1, 1 },{ -1, -1 },{ -1, 1 } };

int w, h;
int result;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void init()
{
	result = 0;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			arr[i][j] = 0;
		}
	}

	memset(visited, false, sizeof(visited));
}

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
			{
				continue;
			}

			if (arr[nextY][nextX] == 0 || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	result++;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		init();

		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				cin >> arr[j][i];
			}
		}

		for (int j = 0; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				if (arr[j][i] == 0 || visited[j][i])
				{
					continue;
				}

				BFS(j, i);
			}
		}

		cout << result << "\n";
	}

	return 0;
}
