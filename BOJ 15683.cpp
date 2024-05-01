#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;

const int INF = 987654321;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

int N, M;

int result;

int room[MAX][MAX];

int copyRoom[MAX][MAX];

vector<pair<int, int>> camera;

vector<int> angle;

bool visited[MAX][MAX][4];

void copy(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copyRoom[i][j] = room[i][j];
		}
	}
}

void func(int cnt)
{
	if (cnt == camera.size())
	{
		for (int i = 0; i < angle.size(); i++)
		{
			int y = camera[i].first;
			int x = camera[i].second;

			for (int j = 0; j < 4; j++)
			{
				if (visited[y][x][j])
				{
					int nextY = y + moveDir[(angle[i] + j) % 4].y;
					int nextX = x + moveDir[(angle[i] + j) % 4].x;

					while (true)
					{
						if (copyRoom[nextY][nextX] == 6)
						{
							break;
						}

						if (!(0 <= nextY && nextY < N && 0 <= nextX && nextX < M))
						{
							break;
						}

						if (copyRoom[nextY][nextX] == 0)
						{
							copyRoom[nextY][nextX] = -1;
						}


						nextY += moveDir[(angle[i] + j) % 4].y;
						nextX += moveDir[(angle[i] + j) % 4].x;
					}
				}
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (copyRoom[i][j] == 0)
				{
					cnt++;
				}
			}
		}

		result = min(result, cnt);
		copy();

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		angle.push_back(i);
		func(cnt + 1);
		angle.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> room[i][j];

			if (1 <= room[i][j] && room[i][j] <= 5)
			{
				camera.push_back({ i, j });
			}

			switch (room[i][j])
			{
			case 1:
				visited[i][j][0] = true;

				break;
			case 2:
				visited[i][j][0] = true;
				visited[i][j][2] = true;

				break;
			case 3:
				visited[i][j][0] = true;
				visited[i][j][1] = true;

				break;
			case 4:
				visited[i][j][0] = true;
				visited[i][j][1] = true;
				visited[i][j][2] = true;

				break;
			case 5:
				visited[i][j][0] = true;
				visited[i][j][1] = true;
				visited[i][j][2] = true;
				visited[i][j][3] = true;

				break;
			}
		}
	}

	result = INF;
	copy();
	func(0);

	cout << result << "\n";

	return 0;
}