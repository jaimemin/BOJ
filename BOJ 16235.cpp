#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10 + 1;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int N, M, K;

int A[MAX][MAX];

int nutritions[MAX][MAX];

vector<int> board[MAX][MAX];

vector<int> deadTrees[MAX][MAX];

void springAndSummer()
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (board[y][x].empty())
			{
				continue;
			}

			sort(board[y][x].begin(), board[y][x].end());

			int dead = 0;
			vector<int> temp;

			for (int tree : board[y][x])
			{
				if (A[y][x] >= tree)
				{
					A[y][x] -= tree;

					temp.push_back(tree + 1);
				}
				else
				{
					dead += tree / 2;
				}
			}

			board[y][x].clear();

			for (int age : temp)
			{
				board[y][x].push_back(age);
			}

			A[y][x] += dead;
		}
	}
}

void autumn()
{
	vector<int> copyBoard[MAX][MAX];

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			copyBoard[y][x] = board[y][x];
		}
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			for (int tree : copyBoard[y][x])
			{
				if (tree % 5)
				{
					continue;
				}

				for (int k = 0; k < 8; k++)
				{
					int nextY = y + moveDir[k].y;
					int nextX = x + moveDir[k].x;

					if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
					{
						continue;
					}

					board[nextY][nextX].push_back(1);
				}
			}
		}
	}
}

void winter()
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			A[y][x] += nutritions[y][x];
		}
	}
}

void print()
{
	cout << "BOARD\n";

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cout << "(" << y << ", " << x << "): ";

			for (int tree : board[y][x])
			{
				cout << tree << " ";
			}

			cout << "\n";
		}
	}

	cout << "\nºñ·á\n";

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cout << A[y][x] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> nutritions[i][j];
			
			A[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int y, x, year;
		cin >> y >> x >> year;

		board[y][x].push_back(year);
	}

	while (K--)
	{
		springAndSummer();
		autumn();
		winter();
	}

	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			result += board[i][j].size();
		}
	}

	cout << result << "\n";

	return 0;
}