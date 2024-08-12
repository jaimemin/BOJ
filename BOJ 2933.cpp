#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
} Dir;

int N;

int R, C;

char cave[MAX][MAX];

int branch[MAX];

int visited[MAX][MAX];

vector<pair<int, int>> group;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void DFS(int y, int x)
{
	if (cave[y][x] == '.' || visited[y][x])
	{
		return;
	}

	visited[y][x] = true;
	group.push_back({ y,x });

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (0 <= nextY && nextY < R
			&& 0 <= nextX && nextX < C)
		{
			DFS(nextY, nextX);
		}
	}
}

void func()
{
	memset(visited, 0, sizeof(visited));

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (cave[y][x] == '.' || visited[y][x])
			{
				continue;
			}

			group.clear();
			DFS(y, x);

			vector<int> low(C, -1);

			for (auto &p : group)
			{
				//각 열마다 가장 밑에있는 행을 찾는다
				low[p.second] = max(low[p.second], p.first);
				//옮길점들 이므로 '.'로 바꿔주자
				cave[p.first][p.second] = '.';
			}

			int lowmove = R;

			for (int j = 0; j < C; ++j) 
			{
				if (low[j] == -1)
				{
					continue;
				}
				
				int i = low[j];

				while (i < R && cave[i][j] == '.') 
				{
					i++;
				}

				lowmove = min(lowmove, i - low[j] - 1);
			}

			for (auto& p : group)
			{
				p.first += lowmove;
				cave[p.first][p.second] = 'x';
				visited[p.first][p.second] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> cave[y][x];
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		branch[i] = R - num;
	}

	for (int i = 0; i < N; i++)
	{
		int height = branch[i];

		if (i % 2 == 0)
		{
			for (int x = 0; x < C; x++)
			{
				if (cave[height][x] == 'x') 
				{
					cave[height][x] = '.';

					break;
				}
			}
		}
		else
		{
			for (int x = C - 1; x >= 0; x--)
			{
				if (cave[height][x] == 'x') 
				{
					cave[height][x] = '.';

					break;
				}
			}
		}

		func();
	}

	for (int y = 0; y < R; y++) 
	{
		for (int x = 0; x < C; x++)
		{
			cout << cave[y][x];
		}

		cout << "\n";
	}

	return 0;
}
