#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 50;

const int INF = 987654321;

typedef struct
{
	int y, x, s;
}State;

int N, M, K;

int result;

int board[MAX][MAX];

vector<int> spins;

map<int, State> spinMap;

void func(int board[][MAX], int idx)
{
	if (idx == K)
	{
		for (int i = 0; i < N; i++)
		{
			int sum = 0;

			for (int j = 0; j < M; j++)
			{
				sum += board[i][j];
			}

			result = min(result, sum);
		}

		return;
	}

	int copyBoard[MAX][MAX];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copyBoard[i][j] = board[i][j];
		}
	}

	State state = spinMap[spins[idx]];
	int y = state.y;
	int x = state.x;

	for (int s = 1; s <= state.s; s++)
	{
		// 상단
		for (int j = -s + 1; j <= s; j++)
		{
			board[y - s][x + j] = copyBoard[y - s][x + j - 1];
		}

		// 우측
		for (int i = -s + 1; i <= s; i++)
		{
			board[y + i][x + s] = copyBoard[y + i - 1][x + s];
		}

		// 하단
		for (int j = s - 1; j >= -s; j--)
		{
			board[y + s][x + j] = copyBoard[y + s][x + j + 1];
		}

		// 좌측
		for (int i = s - 1; i >= -s; i--)
		{
			board[y + i][x - s] = copyBoard[y + i + 1][x - s];
		}
	}

	func(board, idx + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int k = 0; k < K; k++)
	{
		State temp;
		cin >> temp.y >> temp.x >> temp.s;

		temp.y--;
		temp.x--;

		spins.push_back(k);
		spinMap[k] = temp;
	}

	result = INF;

	do
	{
		int copyBoard[MAX][MAX];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				copyBoard[i][j] = board[i][j];
			}
		}

		func(copyBoard, 0);
	} while (next_permutation(spins.begin(), spins.end()));

	cout << result << "\n";

	return 0;
}