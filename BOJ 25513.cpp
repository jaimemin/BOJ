#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 5;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int dist[MAX][MAX];

bool isOutOfBounds(int y, int x)
{
	return y < 0 || y >= MAX || x < 0 || x >= MAX;
}

void initDist() 
{
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			dist[y][x] = -1;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int board[MAX][MAX];

	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			cin >> board[y][x];
		}
	}

	int r, c;
	cin >> r >> c;

	int answer = 0;

	for (int target = 1; target <= 6; target++)
	{
		queue <pair<int, int>> q;
		q.push({ r, c });
		
		initDist();
		dist[r][c] = 0;

		bool targetArrived = false;

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (board[y][x] == target)
			{
				answer += dist[y][x];
				r = y;
				c = x;
				targetArrived = true;

				break;
			}

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (isOutOfBounds(nextY, nextX) 
					|| board[nextY][nextX] == -1)
				{
					continue;
				}


				if (dist[nextY][nextX] != -1)
				{
					continue;
				}

				dist[nextY][nextX] = dist[y][x] + 1;
				q.push({ nextY, nextX });
			}
		}

		if (targetArrived == false)
		{
			cout << -1 << "\n";

			return 0;
		}
	}

	cout << answer << "\n";

	return 0;
}