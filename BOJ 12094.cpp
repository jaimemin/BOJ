#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20;

int N;

int result;

struct Board
{
	int arr[MAX][MAX];

	void rotate90()
	{
		int temp[MAX][MAX];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				temp[i][j] = arr[N - (j + 1)][i];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = temp[i][j];
			}
		}
	}

	int move()
	{
		int temp[MAX][MAX];

		for (int i = 0; i < N; i++)
		{
			int idx = -1;
			bool mergable = false;

			for (int j = 0; j < N; j++)
			{
				if (!arr[i][j])
				{
					continue;
				}

				if (mergable && arr[i][j] == temp[i][idx])
				{
					temp[i][idx] *= 2;
					mergable = false;
				}
				else
				{
					temp[i][++idx] = arr[i][j];
					mergable = true;
				}
			}

			idx++;

			for (; idx < N; idx++)
			{
				temp[i][idx] = 0;
			}
		}

		int maxValue = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = temp[i][j];
				maxValue = max(maxValue, arr[i][j]);
			}
		}

		return maxValue;
	}
};

bool isDifferent(int arr[MAX][MAX], int temp[MAX][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != temp[i][j])
			{
				return true;
			}
		}
	}

	return false;
}

void func(Board board, int cnt, int maxValue)
{
	if (cnt == 10)
	{
		result = maxValue;

		return;
	}

	for (int k = 0; k < 4; k++)
	{
		Board temp = board;
		int nextMaxValue = temp.move();
		int potentialMaxValue = (1 << (10 - (cnt + 1))) * nextMaxValue;

		if (isDifferent(board.arr, temp.arr) 
			&& potentialMaxValue > result)
		{
			func(temp, cnt + 1, nextMaxValue);
		}

		board.rotate90();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	Board board;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board.arr[i][j];

			result = max(result, board.arr[i][j]);
		}
	}

	func(board, 0, result);

	cout << result << "\n";

	return 0;
}
