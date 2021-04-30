#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 499;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int N;
int result;
int A[MAX][MAX];

double sandPercentage[5][5] = {
	{0, 0, 0.02, 0, 0},
	{0, 0.1, 0.07, 0.01, 0},
	{0.05, 0.45, 0, 0, 0},
	{0, 0.1, 0.07, 0.01, 0},
	{0, 0, 0.02, 0, 0}
};

void rotateSandPercentage(void)
{
	double tempSandPercentage[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tempSandPercentage[i][j] = sandPercentage[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sandPercentage[5 - (j + 1)][i] = tempSandPercentage[i][j];
		}
	}
}

int getLeftSand(int originalSand)
{
	return originalSand
		- floor(originalSand * 0.01) * 2
		- floor(originalSand * 0.02) * 2
		- floor(originalSand * 0.07) * 2
		- floor(originalSand * 0.1) * 2
		- floor(originalSand * 0.05);
}

void moveSand(int y, int x)
{
	int originalSand = A[y][x];
	A[y][x] = 0;

	if (originalSand == 0)
	{
		return;
	}

	for (int i = -2; i <= 2; i++)
	{
		for (int j = - 2; j <= 2; j++)
		{
			double percentage = sandPercentage[i + 2][j + 2];

			if (percentage == 0)
			{
				continue;
			}

			int movedSand;

			if (percentage < 0.40) 
			{
				movedSand = floor(originalSand * percentage);
			}
			else 
			{
				movedSand = getLeftSand(originalSand);
			}

			int nextY = y + i;
			int nextX = x + j;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			{
				result += movedSand;

				continue;
			}

			A[nextY][nextX] += movedSand;
		}
	}
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
			cin >> A[i][j];
		}
	}

	int y = N / 2;
	int x = N / 2;
	int cnt = 1;
	int dir = 0;

	while (1)
	{
		if (y == 0 && x == 0)
		{
			break;
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				y = y + moveDir[dir].y;
				x = x + moveDir[dir].x;

				moveSand(y, x);

				if (y == 0 && x == 0)
				{
					cout << result << "\n";

					return 0;
				}
			}

			// 방향 전환
			dir = (dir == 3) ? 0 : dir + 1;
			rotateSandPercentage();
		}

		cnt++;
	}
}