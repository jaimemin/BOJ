#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1,0 }, {-1, 0}, {0, 1}, {0, -1} };

int R, C, K;

int result = 0;

string board[MAX];

bool visited[MAX][MAX];

void func(int y, int x, int cnt)
{
	if (y == 0 && x == C - 1 && cnt == K - 1)
	{
		result++;

		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveDir[k].y;
		int nextX = x + moveDir[k].x;

		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
		{
			continue;
		}

		if (visited[nextY][nextX] || board[nextY][nextX] == 'T')
		{
			continue;
		}

		visited[nextY][nextX] = true;
		func(nextY, nextX, cnt + 1);
		visited[nextY][nextX] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> K;

	for (int y = 0; y < R; y++)
	{
		cin >> board[y];
	}

	visited[R - 1][0] = true;
	func(R - 1, 0, 0);

	cout << result << "\n";

	return 0;
}