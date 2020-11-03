#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 100;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, -1 },{ 0, 1 } };

typedef struct
{
	int y, x, moveCnt;
}State;

bool operator<(State a, State b)
{
	return a.moveCnt > b.moveCnt;
}

int N, M;
string maze[MAX];
bool visited[MAX][MAX];

void BFS(void)
{
	priority_queue<State> pq;
	pq.push({ 0, 0, 1 });
	visited[0][0] = true;

	while (!pq.empty())
	{
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().moveCnt;
		pq.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << cnt << "\n";

			return;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveDir[k].y;
			int nextX = x + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
			{
				continue;
			}

			if (maze[nextY][nextX] == '0' || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			pq.push({ nextY, nextX, cnt + 1 });
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int n = 0; n < N; n++)
	{
		cin >> maze[n];
	}

	BFS();

	return 0;
}