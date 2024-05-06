#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50 + 5;

const int MOD = 1e6 + 7;

int N, M, C;

int board[MAX][MAX];

int cache[MAX][MAX][MAX][MAX];

int func(int y, int x, int prev, int cnt)
{
	if (y > N || x > M)
	{
		return 0;
	}

	if (y == N && x == M)
	{
		return (cnt == 0 && board[y][x] == 0) || (cnt == 1 && board[y][x] > prev);
	}

	int& result = cache[y][x][prev][cnt];

	if (result != -1)
	{
		return result;
	}

	result = 0;

	if (board[y][x] == 0)
	{
		result = (func(y + 1, x, prev, cnt) + func(y, x + 1, prev, cnt)) % MOD;
	}
	else if (board[y][x] > prev)
	{
		result = (func(y + 1, x, board[y][x], cnt - 1) + func(y, x + 1, board[y][x], cnt - 1)) % MOD;
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> C;

	for (int i = 1; i <= C; i++)
	{
		int y, x;
		cin >> y >> x;

		board[y][x] = i;
	}

	memset(cache, -1, sizeof(cache));

	for (int cnt = 0; cnt <= C; cnt++)
	{
		cout << func(1, 1, 0, cnt) << " ";
	}

	cout << "\n";

	return 0;
}