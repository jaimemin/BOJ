#include <iostream>
using namespace std;

const int MAX = 100;

int N, L;

int result;

int board[MAX][MAX];

int symetricBoard[MAX][MAX];

void func(int arr[MAX][MAX])
{
	for (int y = 0; y < N; y++)
	{
		int cnt = 1;
		int x = 0;

		for (; x < N - 1; x++)
		{
			if (arr[y][x] == arr[y][x + 1])
			{
				cnt++;
			}
			else if (arr[y][x] + 1 == arr[y][x + 1] && cnt >= L)
			{
				cnt = 1;
			}
			else if (arr[y][x] - 1 == arr[y][x + 1] && cnt >= 0)
			{
				cnt = -L + 1;
			}
			else
			{
				break;
			}
		}

		if (x == N - 1 && cnt >= 0)
		{
			result++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];

			symetricBoard[x][y] = board[y][x];
		}
	}

	func(board);
	func(symetricBoard);

	cout << result << "\n";

	return 0;
}