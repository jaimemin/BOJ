#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 25;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

int N;
string arr[MAX];
bool visited[MAX][MAX];
vector<int> houses;

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	int cnt = 0;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		cnt++;

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (arr[nextY][nextX] == '0' || visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	houses.push_back(cnt);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == '0' || visited[i][j])
			{
				continue;
			}

			BFS(i, j);
		}
	}

	sort(houses.begin(), houses.end());

	cout << houses.size() << "\n";

	for (int houseCnt : houses)
	{
		cout << houseCnt << "\n";
	}

	return 0;
}