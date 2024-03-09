#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 100;

int maze[MAX][MAX];

bool visited[MAX][MAX];

typedef struct
{
	int y, x;
	int cnt;
} State;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		string s;
		cin >> s;

		int x = 0;

		for (char c : s)
		{
			maze[y][x++] = c - '0';
		}
	}

	queue<State> q;
	q.push({ 0, 0, 1 });
	visited[0][0] = true;

	while (!q.empty())
	{
		State state = q.front();
		int y = state.y;
		int x = state.x;
		int cnt = state.cnt;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << cnt << "\n";

			return 0;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
			{
				continue;
			}

			if (visited[nextY][nextX] || !maze[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX, cnt + 1 });
		}
	}

	return 0;
}