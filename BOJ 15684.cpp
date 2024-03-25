#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 30;

int N, M, H;

int total;

bool flag = false;

bool ladder[MAX][9 + 2];

void func(int height, int cnt)
{
	if (flag)
	{
		return;
	}

	if (total == cnt)
	{
		bool possible = true;

		for (int x = 1; x <= N; x++)
		{
			int col = x;

			for (int y = 0; y < H; y++)
			{
				if (ladder[y][col])
				{
					col++;
				}
				else if (col > 1 && ladder[y][col - 1])
				{
					col--;
				}
			}

			if (x != col)
			{
				possible = false;

				break;
			}
		}

		if (possible)
		{
			flag = true;
		}

		return;
	}

	for (int y = height; y < H; y++)
	{
		for (int x = 1; x < N; x++)
		{
			if (!ladder[y][x - 1]
				&& !ladder[y][x]
				&& !ladder[y][x + 1])
			{
				ladder[y][x] = true;
				func(y, cnt + 1);
				ladder[y][x] = false;
			}
		}
	}
}



int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		int y, x;
		cin	>> y >> x;

		ladder[y - 1][x] = true;
	}

	for (int cnt = 0; cnt <= 3; cnt++)
	{
		total = cnt;
		func(0, 0);

		if (flag)
		{
			cout << total << "\n";

			return 0;
		}
	}

	cout << -1 << "\n";

	return 0;
}