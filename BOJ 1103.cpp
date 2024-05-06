#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 50;

const int INF = 987654321;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1,0 }, {-1, 0}, {0, 1}, {0, -1} };

int N, M;

string board[MAX];

int cache[MAX][MAX];

bool visited[MAX][MAX];

int func(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
	{
		return 0;
	}

	if (board[y][x] == 'H')
	{
		return 0;
	}

	if (visited[y][x])
	{
		cout << -1 << "\n";

		exit(0);
	}

	int& result = cache[y][x];

	if (result != -1)
	{
		return result;
	}

	result = 0;
	visited[y][x] = true;

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y * int(board[y][x] - '0');
		int nextX = x + moveDir[k].x * int(board[y][x] - '0');

		result = max(result, 1 + func(nextY, nextX));
	}

	visited[y][x] = false;

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	memset(cache, -1, sizeof(cache));

	cout << func(0, 0) << "\n";

	return 0;
}