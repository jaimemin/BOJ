#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;
const int INF = 987654321;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

typedef struct
{
	int y, x, length;
}State;

bool operator<(State a, State b)
{
	return a.length > b.length;
}

int N;
int result = INF;
int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> landsEdges[MAX * MAX + 2];

bool isEdge(int y, int x)
{
	bool flag = false;

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
		{
			continue;
		}

		if (arr[nextY][nextX] == 0)
		{
			flag = true;

			break;
		}
	}

	return flag;
}

void BFS(int y, int x, int num)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = num;
	visited[y][x] = true;

	if (isEdge(y, x))
	{
		landsEdges[num].push_back({ y, x });
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

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (arr[nextY][nextX] == 0 || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			arr[nextY][nextX] = num;
			q.push({ nextY, nextX });

			if (isEdge(nextY, nextX))
			{
				landsEdges[num].push_back({ nextY, nextX });
			}
		}
	}
}

int getLength(int y, int x, int num)
{
	priority_queue<State> pq;
	pq.push({ y, x, 0 });
	visited[y][x] = true;

	while (!pq.empty())
	{
		int curY = pq.top().y;
		int curX = pq.top().x;
		int cnt = pq.top().length;
		pq.pop();

		if (arr[curY][curX] && arr[curY][curX] != num)
		{
			return cnt - 1;
		}

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (visited[nextY][nextX] || arr[nextY][nextX] == num)
			{
				continue;
			}

			visited[nextY][nextX] = true;
			pq.push({ nextY, nextX, cnt + 1 });
		}
	}

	return INF;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int num = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] && !visited[i][j])
			{
				BFS(i, j, num++);
			}
		}
	}

	for (int i = 1; i < num; i++)
	{
		for (pair<int, int> edge : landsEdges[i])
		{
			memset(visited, false, sizeof(visited));

			result = min(result, getLength(edge.first, edge.second, i));
		}
	}

	cout << result << "\n";

	return 0;
}